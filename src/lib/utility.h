#ifndef utility_h
#define utility_h

#include <random>

class Uniform {
 private:
  std::random_device rd;
  std::mt19937 mt;
  std::uniform_real_distribution<double> dist;

 public:
  Uniform(double lower = 0.0, double upper = 1.0)
      : rd(), mt(rd()), dist(lower, upper) {}
  double operator()() { return dist(mt); }
};

#endif