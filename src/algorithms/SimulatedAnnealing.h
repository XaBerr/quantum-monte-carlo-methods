#include "../models/Ising2d.h"

#ifndef SimulatedAnnealing_h
#define SimulatedAnnealing_h
class SimulatedAnnealing {
 public:
  SimulatedAnnealing();
  ~SimulatedAnnealing();
  Ising2d generateNeighboringConfig(Ising2d _ising);
  void run();

  Ising2d startingConfig;
  Ising2d endingConfig;
  double startingTemperature;
  double deltaTemeprature;
  double endingTemeprature;
  double scale;
};
#endif