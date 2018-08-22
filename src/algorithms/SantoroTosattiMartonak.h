#include "../models/Ising2dTransverse.h"

#ifndef SantoroTosattiMartonak_h
#define SantoroTosattiMartonak_h
class SantoroTosattiMartonak {
 public:
  SantoroTosattiMartonak();
  ~SantoroTosattiMartonak();
  Ising2dTransverse generateNeighboringConfig(Ising2dTransverse _ising);
  void run();

  Ising2dTransverse startingConfig;
  Ising2dTransverse endingConfig;
  double temperature;
};
#endif