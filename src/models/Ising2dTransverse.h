#ifndef Ising2dTransverse_h
#define Ising2dTransverse_h

#include "Ising2d.h"

class Ising2dTransverse {
 public:
  Ising2dTransverse();
  Ising2dTransverse(const Ising2dTransverse& ising);
  Ising2dTransverse& operator=(const Ising2dTransverse& ising);
  ~Ising2dTransverse();
  void generate();
  double getEnergy();
  double getIsingDiscreteEnergy();
  double getIsingContinueEnergy();
  double getDelta(Ising2dTransverse* ising);
  Ising2d* slices;
  Ising2d mainReplica;
  int numberOfReplica;
  double tranverseField;
  double periodicBoundary;

 private:
  int slicesLength;
};
#endif