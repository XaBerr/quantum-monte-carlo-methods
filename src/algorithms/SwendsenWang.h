#include "../models/Ising2d.h"

#ifndef SwendsenWang_h
#define SwendsenWang_h
class SwendsenWang {
 public:
  SwendsenWang();
  ~SwendsenWang();
  Ising2d generateNeighboringConfig(Ising2d _ising);
  void run();

  Ising2d startingConfig;
  Ising2d endingConfig;
  double temperature;
  double scale;
};
#endif