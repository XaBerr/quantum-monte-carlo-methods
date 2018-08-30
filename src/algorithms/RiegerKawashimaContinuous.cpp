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

// std::vector<std::vector<std::vector<bool>>> RiegerKawashimaContinuous::generateJoins(Ising2d ising) {
//   std::vector<std::vector<std::vector<bool>>> joins;
//   return joins;
// }

std::vector<std::vector<std::vector<bool>>> RiegerKawashimaContinuous::generateCuts(Ising2dTransverse ising) {
  int beta        = ising.mainReplica.favorAlignment ? -1 : 1;
  double deltaTau = 1 / (temperature * ising.numberOfreplicas);
  std::vector<std::vector<std::vector<bool>>> cuts =
      std::vector<std::vector<std::vector<bool>>>(
          ising.slices.size(),
          std::vector<std::vector<bool>>(ising.mainReplica.size, std::vector<bool>(ising.mainReplica.size)));
  int count[ising.mainReplica.size][ising.mainReplica.size] = {};
  for (int s = 0; s < ising.slices.size(); s++)
    for (int i = 0; i < ising.slices[s].nodes.size(); i++) {
      for (int j = 0; j < ising.slices[s].nodes[i].size(); j++) {
        if (s == ising.slices.size() - 1)
          if (!ising.periodicBoundary || uniform() < (1 - exp(ising.tranverseField * count[i][j] * deltaTau))) {
            cuts[0][i][j] = true;
            count[i][j]   = 0;
          } else {
            cuts[0][i][j] = false;
            count[i][j]++;
          }
        if (s > 0)
          if (ising.slices[s].nodes[i][j].spin != ising.slices[s - 1].nodes[i][j].spin || uniform() < (1 - exp(ising.tranverseField * count[i][j] * deltaTau))) {
            cuts[s][i][j] = true;
            count[i][j]   = 0;
          } else {
            cuts[s][i][j] = false;
            count[i][j]++;
          }
      }
    }
  return cuts;
}

std::vector<std::vector<Node *>> RiegerKawashimaContinuous::generateClusters(Ising2d &ising, std::vector<std::vector<std::vector<bool>>> cuts) {
  std::vector<std::vector<Node *>> clusters;
  double t, j = 0;
  double pjoin = 1 - exp(2 * t * j);
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