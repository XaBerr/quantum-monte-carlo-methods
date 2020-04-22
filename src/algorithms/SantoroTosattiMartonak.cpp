#include "../../include/QMC-methods/SantoroTosattiMartonak.h"
#include <math.h>
#include <stdio.h>
using namespace QMCm;
static Uniform uniform;

SantoroTosattiMartonak::SantoroTosattiMartonak() {
  temperature      = 1;
  numberOfreplicas = 3;
  startingField    = 100;
  endingField      = 0;
  deltaField       = 1;
  scale            = 10;
}

Ising2dTransverse SantoroTosattiMartonak::generateNeighboringConfig(Ising2dTransverse _ising) {
  _ising.slices[(int)(uniform() * (float)(_ising.numberOfreplicas - 1))]
      .nodes[(int)(uniform() * (float)(_ising.mainReplica.nodes.size() - 1))]
            [(int)(uniform() * (float)(_ising.mainReplica.nodes.size() - 1))]
      .flip();
  int row = (int)(uniform() * (float)(_ising.mainReplica.nodes.size() - 1));
  int col = (int)(uniform() * (float)(_ising.mainReplica.nodes.size() - 1));
  for (int i = 0; i < _ising.numberOfreplicas; i++)
    _ising.slices[i].nodes[row][col].flip();
  return _ising;
}

void SantoroTosattiMartonak::run() {
  Ising2dTransverse trialConfig;
  Ising2dTransverse bestConfig = startingConfig;
  double delta;
  for (double currentField = startingField; currentField > endingField; currentField -= deltaField) {
    bestConfig.tranverseField = -log(tanh(currentField / (numberOfreplicas * temperature)));
    trialConfig               = generateNeighboringConfig(bestConfig);
    delta                     = trialConfig.getDelta(bestConfig);
    if (uniform() < exp(-scale * delta / currentField))
      bestConfig = trialConfig;
  }
  endingConfig = bestConfig;
}