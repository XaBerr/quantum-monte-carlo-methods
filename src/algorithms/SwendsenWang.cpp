#include "../../include/QMC-methods/SwendsenWang.h"
#include <math.h>
#include <stdio.h>
using namespace QMCm;
static Uniform uniform;

SwendsenWang::SwendsenWang() {
  temperature        = 1;
  scale              = 1;
  numberOfIterations = 1;
}

std::vector<std::vector<std::vector<bool>>> SwendsenWang::generateJoins(Ising2d ising) {
  std::vector<std::vector<std::vector<bool>>> joins =
      std::vector<std::vector<std::vector<bool>>>(ising.size, std::vector<std::vector<bool>>(ising.size, std::vector<bool>(DIM)));
  int beta = ising.favorAlignment ? -1 : 1;
  for (int i = 0; i < ising.arcs.size(); i++)
    for (int j = 0; j < ising.arcs[i].size(); j++)
      for (int k = 0; k < ising.arcs[i][j].size(); k++)
        if (ising.arcs[i][j][k].node1 != nullptr &&
            ising.arcs[i][j][k].node2 != nullptr &&
            ising.arcs[i][j][k].node1->spin == ising.arcs[i][j][k].node2->spin &&
            uniform() < (1 - exp(-scale * beta * ising.arcs[i][j][k].value / temperature)))
          joins[i][j][k] = true;
        else
          joins[i][j][k] = false;
  return joins;
}

std::vector<std::vector<Node *>> SwendsenWang::generateClusters(Ising2d &ising, std::vector<std::vector<std::vector<bool>>> joins) {
  std::vector<std::vector<Node *>> clusters = std::vector<std::vector<Node *>>();
  int clustersMap[ising.size][ising.size]   = {};
  int lastCluster                           = 0;
  for (int i = 0; i < ising.nodes.size(); i++)
    for (int j = 0; j < ising.nodes[i].size(); j++) {
      if (j == ising.nodes[i].size() - 1 && joins[i][0][LEFT]) {
        clustersMap[i][j] = clustersMap[i][0];
        clusters[clustersMap[i][0]].push_back(&(ising.nodes[i][j]));
      } else if (j > 0 && joins[i][j][LEFT]) {
        clustersMap[i][j] = clustersMap[i][j - 1];
        clusters[clustersMap[i][j - 1]].push_back(&(ising.nodes[i][j]));
      } else if (i == ising.nodes.size() - 1 && joins[0][j][UP]) {
        clustersMap[i][j] = clustersMap[0][j];
        clusters[clustersMap[0][j]].push_back(&(ising.nodes[i][j]));
      } else if (i > 0 && joins[i][j][UP]) {
        clustersMap[i][j] = clustersMap[i - 1][j];
        clusters[clustersMap[i - 1][j]].push_back(&(ising.nodes[i][j]));
      } else {
        std::vector<Node *> newCluster = std::vector<Node *>();
        newCluster.push_back(&(ising.nodes[i][j]));
        clusters.push_back(newCluster);
        clustersMap[i][j] = lastCluster++;
      }
    }
  return clusters;
}

void SwendsenWang::randomFlip(std::vector<std::vector<Node *>> clusters) {
  for (int i = 0; i < clusters.size(); i++)
    if (uniform() < 0.5)
      for (int j = 0; j < clusters[i].size(); j++)
        clusters[i][j]->flip();
}

void SwendsenWang::run() {
  Ising2d currentConfig = startingConfig;
  std::vector<std::vector<std::vector<bool>>> joins;
  std::vector<std::vector<Node *>> clusters;
  for (int i = 0; i < numberOfIterations; i++) {
    joins    = generateJoins(currentConfig);
    clusters = generateClusters(currentConfig, joins);
    randomFlip(clusters);
  }
  endingConfig = currentConfig;
}