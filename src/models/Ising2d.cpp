#include "Ising2d.h"
#include "../lib/utility.h"
#include <cmath>
#include <limits>
#include <algorithm>

Uniform uniform;

Ising2d::Ising2d() {
  size             = 3;
  favorAlignment   = true;
  favorSpinUp      = true;
  periodicBoundary = false;
  nodeMaxValue     = 1;
  nodeMinValue     = -1;
  arcMaxValue      = 1;
  arcMinValue      = -1;
}

void Ising2d::generate() {
  nodes = std::vector<std::vector<Node>>(size, std::vector<Node>(size));
  arcs  = std::vector<std::vector<std::vector<Arc2>>>(size, std::vector<std::vector<Arc2>>(size, std::vector<Arc2>(DIM)));
  for (int i = 0; i < nodes.size(); i++) {
    for (int j = 0; j < nodes[i].size(); j++) {
      nodes[i][j].id    = std::to_string(i) + "-" + std::to_string(j);
      nodes[i][j].value = uniform() * (nodeMaxValue - nodeMinValue) + nodeMinValue;
      if (i > 0) {
        arcs[i][j][UP].node1 = &(nodes[i][j]);
        arcs[i][j][UP].node2 = &(nodes[i - 1][j]);
        arcs[i][j][UP].value = uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
      }
      if (periodicBoundary && (i == nodes.size() - 1)) {
        arcs[0][j][UP].node1 = &(nodes[0][j]);
        arcs[0][j][UP].node2 = &(nodes[i][j]);
        arcs[0][j][UP].value = uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
      }
      if (j > 0) {
        arcs[i][j][LEFT].node1 = &(nodes[i][j]);
        arcs[i][j][LEFT].node2 = &(nodes[i][j - 1]);
        arcs[i][j][LEFT].value = uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
      }
      if (periodicBoundary && (j == nodes.size() - 1)) {
        arcs[i][0][LEFT].node1 = &(nodes[i][0]);
        arcs[i][0][LEFT].node2 = &(nodes[i][j]);
        arcs[i][0][LEFT].value = uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
      }
    }
  }
  arcs.shrink_to_fit();
}

double Ising2d::getEnergy() const {
  double energy = 0;
  int alpha     = favorSpinUp ? -1 : 1;
  int beta      = favorAlignment ? -1 : 1;
  for (int i = 0; i < nodes.size(); i++)
    for (int j = 0; j < nodes[i].size(); j++)
      energy += alpha * nodes[i][j].value * nodes[i][j].spin;

  for (int i = 0; i < arcs.size(); i++)
    for (int j = 0; j < arcs[i].size(); j++)
      for (int k = 0; k < DIM; k++)
        if (arcs[i][j][k].node1 != nullptr && arcs[i][j][k].node2 != nullptr)
          energy += beta * arcs[i][j][k].value * arcs[i][j][k].node1->spin * arcs[i][j][k].node2->spin;

  return energy;
}

double Ising2d::getDelta(const Ising2d& ising) const {
  double myEnergy    = getEnergy();
  double otherEnergy = ising.getEnergy();
  return (myEnergy > otherEnergy ? 1 : -1) * abs(myEnergy - otherEnergy);
}