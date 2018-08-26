#include "Ising2d.h"
#include "../lib/utility.h"
#include <cmath>
#include <limits>
#include <algorithm>

Uniform uniform;

Ising2d::Ising2d() {
  size = 3;
  favorAlignment = true;
  favorSpinUp = true;
  periodicBoundary = false;
  nodeMaxValue = 1;
  nodeMinValue = -1;
  arcMaxValue = 1;
  arcMinValue = -1;
}

void Ising2d::generate() {
  nodes = std::vector<std::vector<Node>>(size, std::vector<Node>(size));
  arcs = std::vector<Arc2>();
  arcs.reserve(size * size * 4);
  for (int i = 0; i < nodes.size(); i++) {
    for (int j = 0; j < nodes[i].size(); j++) {
      nodes[i][j].value =
          uniform() * (nodeMaxValue - nodeMinValue) + nodeMinValue;
      if (i > 0) {
        Node* node1 = &(nodes[i - 1][j]);
        Node* node2 = &(nodes[i][j]);
        double value = uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
        arcs.emplace_back(node1, node2, value);
      }
      if (periodicBoundary && (i == nodes.size() - 1)) {
        Node* node1 = &(nodes[i][j]);
        Node* node2 = &(nodes[0][j]);
        double value = uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
        arcs.emplace_back(node1, node2, value);
      }
      if (j > 0) {
        Node* node1 = &(nodes[i][j - 1]);
        Node* node2 = &(nodes[i][j]);
        double value = uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
        arcs.emplace_back(node1, node2, value);
      }
      if (periodicBoundary && (j == nodes.size() - 1)) {
        Node* node1 = &(nodes[i][j]);
        Node* node2 = &(nodes[i][0]);
        double value = uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
        arcs.emplace_back(node1, node2, value);
      }
    }
  }
  arcs.shrink_to_fit();
}

double Ising2d::getEnergy() const {
  double energy = 0;
  int alpha = favorSpinUp ? -1 : 1;
  int beta = favorAlignment ? -1 : 1;
  for (int i = 0; i < nodes.size(); i++) {
    for (int j = 0; j < nodes[i].size(); j++) {
      energy += alpha * nodes[i][j].value * nodes[i][j].spin;
    }
  }
  for (int i = 0; i < arcs.size(); i++) {
    energy += beta * arcs[i].value * arcs[i].node1->spin * arcs[i].node2->spin;
  }
  return energy;
}

double Ising2d::getDelta(const Ising2d& ising) const {
  double myEnergy = getEnergy();
  double otherEnergy = ising.getEnergy();
  return (myEnergy > otherEnergy ? 1 : -1) * abs(myEnergy - otherEnergy);
}