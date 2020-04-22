#ifndef RiegerKawashimaContinuous_h
#define RiegerKawashimaContinuous_h

#include "../../src/models/Ising2dTransverse.h"
#include "../../src/models/Segment.h"
#include "../../src/libs/Uniform.h"

namespace QMCm {
class RiegerKawashimaContinuous {
 public:
  RiegerKawashimaContinuous();
  std::vector<std::vector<std::vector<bool>>> generateCuts(Ising2dTransverse ising);
  std::vector<Segment> generateSegments(Ising2dTransverse ising, std::vector<std::vector<std::vector<bool>>> cuts);
  std::vector<std::vector<Node *>> generateClusters(Ising2d &ising, std::vector<std::vector<std::vector<bool>>> cuts);
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
};  // namespace QMCm
#endif