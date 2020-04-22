#ifndef SimulatedAnnealing_h
#define SimulatedAnnealing_h

#include "../../src/models/Ising2d.h"
#include "../../src/libs/Uniform.h"

namespace QMCm {
class SimulatedAnnealing {
 public:
  SimulatedAnnealing();
  Ising2d generateNeighboringConfig(Ising2d _ising);
  void run();

  Ising2d startingConfig;
  Ising2d endingConfig;
  double startingTemperature;
  double deltaTemperature;
  double endingTemperature;
  double scale;
};
};  // namespace QMCm
#endif