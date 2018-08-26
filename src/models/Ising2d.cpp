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

// Ising2d::Ising2d(const Ising2d& ising) { *this = ising; }

// Ising2d& Ising2d::operator=(const Ising2d& ising) {
//   if (this != &ising) {
//     size = ising.size;
//     favorAlignment = ising.favorAlignment;
//     favorSpinUp = ising.favorSpinUp;
//     nodeMaxValue = ising.nodeMaxValue;
//     nodeMinValue = ising.nodeMinValue;
//     arcMaxValue = ising.arcMaxValue;
//     arcMinValue = ising.arcMinValue;
//     periodicBoundary = ising.periodicBoundary;
//     generate();
//     for (int i = 0; i < nodes.size(); i++) {
//       for (int j = 0; j < nodes.size(); j++) {
//         nodes[i][j].value = ising.nodes[i][j].value;
//         nodes[i][j].spin = ising.nodes[i][j].spin;
//       }
//     }
//     for (int i = 0; i < arcs.size(); i++) {
//       arcs[i].value = ising.arcs[i].value;
//     }
//   }
//   return *this;
// }

// Ising2d::~Ising2d() {}

void Ising2d::generate() {
  int cont = 0;
  nodes = std::vector<std::vector<Node>>(size, std::vector<Node>(size));
  arcs = std::vector<Arc2>((size - 1) * (size - 1) * 2 + (size - 1) * 2);
  for (int i = 0; i < nodes.size(); i++) {
    for (int j = 0; j < nodes.size(); j++) {
      nodes[i][j].id = (char*)"id";
      nodes[i][j].value =
          uniform() * (nodeMaxValue - nodeMinValue) + nodeMinValue;
      if (i > 0) {
        arcs[cont].node1 = &(nodes[i - 1][j]);
        arcs[cont].node2 = &(nodes[i][j]);
        arcs[cont++].value =
            uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
      }
      if (periodicBoundary && (i == nodes.size() - 1)) {
        arcs[cont].node1 = &(nodes[i][j]);
        arcs[cont].node2 = &(nodes[0][j]);
        arcs[cont++].value =
            uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
      }
      if (j > 0) {
        arcs[cont].node1 = &(nodes[i][j - 1]);
        arcs[cont].node2 = &(nodes[i][j]);
        arcs[cont++].value =
            uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
      }
      if (periodicBoundary && (j == nodes.size() - 1)) {
        arcs[cont].node1 = &(nodes[i][j]);
        arcs[cont].node2 = &(nodes[i][0]);
        arcs[cont++].value =
            uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
      }
    }
  }
}

double Ising2d::getEnergy() const {
  double energy = 0;
  int alpha = favorSpinUp ? -1 : 1;
  int beta = favorAlignment ? -1 : 1;
  for (int i = 0; i < nodes.size(); i++) {
    for (int j = 0; j < nodes.size(); j++) {
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