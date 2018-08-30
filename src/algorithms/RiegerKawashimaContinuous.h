#ifndef RiegerKawashimaContinuous_h
#define RiegerKawashimaContinuous_h

#include "../models/Ising2dTransverse.h"

class RiegerKawashimaContinuous {
 public:
  RiegerKawashimaContinuous();
  std::vector<std::vector<std::vector<bool>>> generateJoins(Ising2d ising);
  std::vector<std::vector<std::vector<bool>>> generateCuts(Ising2dTransverse ising);
  std::vector<std::vector<Node *>> generateClusters(Ising2d &ising, std::vector<std::vector<std::vector<bool>>> joins);
  void randomFlip(std::vector<std::vector<Node *>> clusters);
  void run();

  Ising2dTransverse startingConfig;
  Ising2dTransverse endingConfig;
  double temperature;
  double numberOfreplicas;
  double startingField;
  double endingField;
  double deltaField;
  double scale;
};
#endif