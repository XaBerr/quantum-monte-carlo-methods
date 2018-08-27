#ifndef SwendsenWang_h
#define SwendsenWang_h

#include "../models/Ising2d.h"

class SwendsenWang {
 public:
  SwendsenWang();
  std::vector<Arc2*> addJoins(Ising2d ising);
  std::vector<Arc2*> removeFakeJoin(Ising2d ising, std::vector<Arc2*> cuts);
  std::vector<std::vector<Node*>> findClusters(Ising2d ising);
  void randomFlip(std::vector<std::vector<Node*>> clusters);
  void run();

  Ising2d startingConfig;
  Ising2d endingConfig;
  double temperature;
  double scale;
  int numberOfIterations;
};
#endif