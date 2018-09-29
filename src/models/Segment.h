#ifndef Segment_h
#define Segment_h

#include <vector>
#include "Point.h"

class Segment {
 public:
  Segment() {
    spin = 0;
  }
  Segment(Point _begin, int _spin) {
    points.push_back(_begin);
    spin = _spin;
  }
  int size() {
    return points.size();
  }
  std::vector<Point> points;
  int spin;
};
#endif