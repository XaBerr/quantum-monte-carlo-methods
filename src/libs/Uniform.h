#ifndef Uniform_h
#define Uniform_h

#include <random>
#include <ctime>

namespace QMCm {
class Uniform {
 private:
  std::mt19937 mt;
  std::uniform_real_distribution<double> dist;

 public:
  Uniform(double lower = 0.0, double upper = 1.0) : mt(std::time(nullptr)), dist(lower, upper) {}
  double operator()() { return dist(mt); }
};
};  // namespace QMCm

#endif