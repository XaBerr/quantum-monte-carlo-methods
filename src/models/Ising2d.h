#ifndef Ising2d_h
#define Ising2d_h

#include <vector>
#include "Arc2.h"

#define UP 0
#define LEFT 1
#define DIM 2

namespace QMCm {
class Ising2d {
 public:
  Ising2d();
  void generate();
  double getEnergy() const;
  double getDelta(const Ising2d& ising) const;
  std::vector<std::vector<Node>> nodes;
  std::vector<std::vector<std::vector<Arc2>>> arcs;
  int size;
  bool favorAlignment;
  bool favorSpinUp;
  bool periodicBoundary;
  double nodeMaxValue;
  double nodeMinValue;
  double arcMaxValue;
  double arcMinValue;
};
};  // namespace QMCm
#endif