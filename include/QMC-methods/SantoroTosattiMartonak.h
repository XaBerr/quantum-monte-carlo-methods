#ifndef SantoroTosattiMartonak_h
#define SantoroTosattiMartonak_h

#include "../../src/models/Ising2dTransverse.h"
#include "../../src/libs/Uniform.h"

namespace QMCm {
class SantoroTosattiMartonak {
 public:
  SantoroTosattiMartonak();
  Ising2dTransverse generateNeighboringConfig(Ising2dTransverse _ising);
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