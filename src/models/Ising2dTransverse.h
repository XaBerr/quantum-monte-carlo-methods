#ifndef Ising2dTransverse_h
#define Ising2dTransverse_h

#include <vector>
#include "Ising2d.h"

class Ising2dTransverse {
 public:
  Ising2dTransverse();
  void generate();
  double getEnergy() const;
  double getIsingDiscreteEnergy() const;
  double getIsingContinueEnergy() const;
  double getDelta(const Ising2dTransverse& ising) const;
  std::vector<Ising2d> slices;
  Ising2d mainReplica;
  int numberOfReplica;
  double tranverseField;
  double periodicBoundary;
};
#endif