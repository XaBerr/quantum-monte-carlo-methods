#ifndef Ising2d_h
#define Ising2d_h

#include "Arc2.h"

class Ising2d {
 public:
  Ising2d();
  Ising2d(const Ising2d& ising);
  Ising2d& operator=(const Ising2d& ising);
  ~Ising2d();
  void generate();
  double getEnergy();
  double getDelta(Ising2d* ising);
  Node** nodes;
  Arc2* arcs;
  int nodesLength;
  int arcsLength;
  int size;
  bool favorAlignment;
  bool favorSpinUp;
  bool periodicBoundary;
  double nodeMaxValue;
  double nodeMinValue;
  double arcMaxValue;
  double arcMinValue;
};
#endif