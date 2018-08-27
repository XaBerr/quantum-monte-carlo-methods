#ifndef Cut_h
#define Cut_h

class Cut {
 public:
  Cut(int _x = 0, int _y = 0, int _z = 0) {
    x = _x;
    y = _y;
    z = _z;
  }
  int x;
  int y;
  int z;
};
#endif