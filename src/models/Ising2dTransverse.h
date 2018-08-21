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
  int nodesLength;
  int arcsLength;
  int slicesLength;
  int size;
  bool favorAlignment;
  bool favorSpinUp;
  double nodeMaxValue;
  double nodeMinValue;
  double arcMaxValue;
  double arcMinValue;
};
#endif