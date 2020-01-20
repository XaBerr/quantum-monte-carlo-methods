#ifndef Point_h
#define Point_h

namespace QMCm {
class Point {
 public:
  Point(int _x = 0, int _y = 0, int _z = 0) {
    x = _x;
    y = _y;
    z = _z;
  }
  int x;
  int y;
  int z;
};
};  // namespace QMCm
#endif