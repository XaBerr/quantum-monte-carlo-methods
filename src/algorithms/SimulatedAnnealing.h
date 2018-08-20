#include "../models/Ising2d.h"

#ifndef SimulatedAnnealing_h
#define SimulatedAnnealing_h
class SimulatedAnnealing {
 public:
  SimulatedAnnealing();
  ~SimulatedAnnealing();

  Ising2d ising;
  Ising2d startingConfig;
  double startingTemperature;
  double deltaTemeprature;
  double endingTemeprature;
  double scale;
};
#endif