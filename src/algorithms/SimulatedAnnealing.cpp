#include "SimulatedAnnealing.h"

SimulatedAnnealing::SimulatedAnnealing() {
  startingTemperature = 100.0;
  deltaTemeprature = 1.0;
  endingTemeprature = 0.0;
  scale = 1.0;
}

SimulatedAnnealing::~SimulatedAnnealing() {}