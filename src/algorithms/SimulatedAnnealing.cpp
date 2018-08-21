#include "SimulatedAnnealing.h"
#include "../lib/functions.h"
#include <math.h>
#include <stdio.h>

SimulatedAnnealing::SimulatedAnnealing() {
  startingTemperature = 100.0;
  deltaTemeprature = 1.0;
  endingTemeprature = 0.0;
  scale = 1.0;
}

SimulatedAnnealing::~SimulatedAnnealing() {}

Ising2d SimulatedAnnealing::generateNeighboringConfig(Ising2d _ising) {
  _ising
      .nodes[(int)(uniform() * (float)(_ising.nodesLength - 1))]
            [(int)(uniform() * (float)(_ising.nodesLength - 1))]
      .flip();
  return _ising;
}

void SimulatedAnnealing::run() {
  Ising2d currentConfig = startingConfig;
  Ising2d bestConfig = startingConfig;
  int steps =
      (int)(abs(startingTemperature - endingTemeprature) / deltaTemeprature);
  printf("Steps [%d]\n", steps);
  for (int i = 0; i < steps; i++) {
    currentConfig = generateNeighboringConfig(bestConfig);
    double t1 = endingTemeprature - steps * deltaTemeprature;
    double t2 = currentConfig.getDelta(&bestConfig);
    printf("Energia corrente [%f] energia di prova [%f]\n",
           bestConfig.getEnergy(), currentConfig.getEnergy());
    if (t1 < 0 || uniform() < exp(-scale * t1 / t2)) {
      printf("si\n");
      bestConfig = currentConfig;
    } else
      printf("no\n");
  }
  endingConfig = bestConfig;
}