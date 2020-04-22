#include "../../include/QMC-methods/SimulatedAnnealing.h"
#include <math.h>
#include <stdio.h>
using namespace QMCm;
static Uniform uniform;

SimulatedAnnealing::SimulatedAnnealing() {
  startingTemperature = 100.0;
  deltaTemperature    = 1.0;
  endingTemperature   = 0.0;
  scale               = 10;
}

Ising2d SimulatedAnnealing::generateNeighboringConfig(Ising2d _ising) {
  _ising.nodes[(int)(uniform() * (float)(_ising.nodes.size() - 1))]
              [(int)(uniform() * (float)(_ising.nodes.size() - 1))]
                  .flip();
  return _ising;
}

void SimulatedAnnealing::run() {
  Ising2d trialConfig;
  Ising2d bestConfig = startingConfig;
  double delta;
  for (double currentTemperature = startingTemperature;
       currentTemperature > endingTemperature;
       currentTemperature -= deltaTemperature) {
    trialConfig = generateNeighboringConfig(bestConfig);
    delta       = trialConfig.getDelta(bestConfig);
    if (uniform() < exp(-scale * delta / currentTemperature))
      bestConfig = trialConfig;
  }
  endingConfig = bestConfig;
}