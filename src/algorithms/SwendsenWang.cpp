#include "SwendsenWang.h"
#include "../lib/utility.h"
#include <math.h>
#include <stdio.h>

static Uniform uniform;

SwendsenWang::SwendsenWang() {
  temperature = 1;
  scale = 1;
  numberOfIterations = 1;
}

std::vector<Arc2*> SwendsenWang::addJoins(Ising2d ising) {
  std::vector<Arc2*> joins;
  for (auto& j : ising.arcs) {
    if (j.node1 == j.node2 && uniform() > 0.8) {
      joins.push_back(&j);
    }
  }
  return joins;
}

std::vector<Arc2*> SwendsenWang::removeFakeJoin(Ising2d ising,
                                                std::vector<Arc2*> cuts) {
  std::vector<Arc2*> joins;
  return joins;
}

std::vector<std::vector<Node*>> SwendsenWang::findClusters(Ising2d ising) {
  std::vector<std::vector<Node*>> temp;
  return temp;
}

void SwendsenWang::randomFlip(std::vector<std::vector<Node*>> clusters) {}

void SwendsenWang::run() {
  Ising2d currentConfig = startingConfig;
  std::vector<Arc2*> joins;
  std::vector<std::vector<Node*>> clusters;
  // cuts = getCuts(currentConfig);
  for (int i = 0; i < numberOfIterations; i++) {
    // cuts += addCuts(currentConfig);
    // clusters = findClusters(currentConfig);
    // randomFlip(clusters)
    // cuts = removeFakeCuts(currentConfig)
  }
}

// std::vector<Cut> SwendsenWang::getCuts(Ising2d ising) {
//   std::vector<Cut> cuts;
//   for (int i = 0; i < ising.nodes.size(); i++) {
//     for (int j = 0; j < ising.nodes[i].size(); j++) {
//       if (i > 0 && ising.nodes[i][j].spin != ising.nodes[i - 1][j].spin) {
//         cuts.emplace_back(i - 1, j, 0);
//       }
//     }
//   }
//   return cuts;
// }

// std::vector<Cut> SwendsenWang::addCuts(Ising2d ising) {
//   std::vector<Cut> cuts;
//   for (int i = 0; i < ising.nodes.size(); i++) {
//     for (int j = 0; j < ising.nodes[i].size(); j++) {
//       if (i > 0 && uniform() > 0.8) {
//         cuts.emplace_back(i - 1, j, 0);
//       }
//     }
//   }
//   return cuts;
// }

// std::vector<Cut> SwendsenWang::removeFakeCuts(Ising2d ising,
//                                               std::vector<Cut> cuts) {
//   std::vector<Cut> temp;
//   for (int i = 0; i < cuts.size(); i++) {
//     if (ising.nodes[cuts[i].x][cuts[i].y].spin !=
//         ising.nodes[cuts[i].x + 1][cuts[i].y].spin) {
//       temp.emplace_back(cuts[i].x, cuts[i].y);
//     }
//   }
//   return temp;
// }
