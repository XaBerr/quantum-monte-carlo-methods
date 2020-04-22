#ifndef SwendsenWang_h
#define SwendsenWang_h

#include "../../src/models/Ising2d.h"
#include "../../src/libs/Uniform.h"

namespace QMCm {
class SwendsenWang {
 public:
  SwendsenWang();
  std::vector<std::vector<std::vector<bool>>> generateJoins(Ising2d ising);
  std::vector<std::vector<Node *>> generateClusters(Ising2d &ising, std::vector<std::vector<std::vector<bool>>> joins);
  void randomFlip(std::vector<std::vector<Node *>> clusters);
  void run();

  Ising2d startingConfig;
  Ising2d endingConfig;
  double temperature;
  double scale;
  int numberOfIterations;
};
};  // namespace QMCm
#endif