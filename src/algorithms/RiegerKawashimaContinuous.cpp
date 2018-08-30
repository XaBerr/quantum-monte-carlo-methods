#include "RiegerKawashimaContinuous.h"
#include "../lib/utility.h"
#include <math.h>
#include <stdio.h>

static Uniform uniform;

RiegerKawashimaContinuous::RiegerKawashimaContinuous() {
  temperature      = 1;
  numberOfreplicas = 3;
  startingField    = 100;
  endingField      = 0;
  deltaField       = 1;
  scale            = 10;
}

std::vector<std::vector<std::vector<bool>>> RiegerKawashimaContinuous::generateJoins(Ising2d ising) {
  std::vector<std::vector<std::vector<bool>>> joins;
  return joins;
}

std::vector<std::vector<std::vector<bool>>> RiegerKawashimaContinuous::generateCuts(Ising2dTransverse ising) {
  std::vector<std::vector<std::vector<bool>>> cuts =
      std::vector<std::vector<std::vector<bool>>>(
          ising.slices.size(),
          std::vector<std::vector<bool>>(ising.mainReplica.size, std::vector<bool>(ising.mainReplica.size)));
  int beta = ising.mainReplica.favorAlignment ? -1 : 1;
  for (int s = 0; s < ising.slices.size(); s++)
    for (int i = 0; i < ising.slices[s].nodes.size(); i++)
      for (int j = 0; j < ising.slices[s].nodes[i].size(); j++) {
        if (s == ising.slices.size() - 1)
          cuts[0][i][j] = !ising.periodicBoundary || uniform() < 0.8;
        if (s > 0)
          cuts[s][i][j] = ising.slices[s].nodes[i][j].spin != ising.slices[s - 1].nodes[i][j].spin || uniform() < 0.8;
      }
  return cuts;
}

std::vector<std::vector<Node *>> RiegerKawashimaContinuous::generateClusters(Ising2d &ising, std::vector<std::vector<std::vector<bool>>> joins) {
  std::vector<std::vector<Node *>> clusters;
  return clusters;
}

void RiegerKawashimaContinuous::randomFlip(std::vector<std::vector<Node *>> clusters) {
  for (int i = 0; i < clusters.size(); i++)
    if (uniform() < 0.5)
      for (int j = 0; j < clusters[i].size(); j++)
        clusters[i][j]->flip();
}

void RiegerKawashimaContinuous::run() {
  Ising2dTransverse currentConfig = startingConfig;
  std::vector<std::vector<std::vector<bool>>> cuts;
  std::vector<std::vector<std::vector<bool>>> joins;
  std::vector<std::vector<Node *>> clusters;
  for (double currentField = startingField; currentField > endingField; currentField -= deltaField) {
    cuts = generateCuts(currentConfig);
    //   joins    = generateJoins(currentConfig);
    //   clusters = generateClusters(currentConfig, joins);
    //   randomFlip(clusters);
  }
  endingConfig = currentConfig;
}