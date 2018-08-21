#include "Ising2d.h"

#ifndef Ising2dTransverse_h
#define Ising2dTransverse_h
class Ising2dTransverse {
 public:
  Ising2dTransverse();
  Ising2dTransverse(Ising2dTransverse& ising);
  ~Ising2dTransverse();
  void generate();
  void setNodeValue(int i, int j, int value);
  double getEnergy();
  double getDelta(Ising2dTransverse* ising);
  Ising2d* slices;
  Ising2d mainReplica;
  int slicesLength;
  double tranverseField;
};
#endif