#include "Arc2.h"

#ifndef Ising_h
#define Ising_h
class Ising {
 public:
  Ising();
  ~Ising();
  void generateRandom();
  double getEnergy();

 private:
  int nodes[10];
};
#endif