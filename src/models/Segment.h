#ifndef Segment_h
#define Segment_h

#include "SubSegment.h"

class Segment {
 public:
  Segment() {
    spin = 0;
  }
  Segment(Point _begin, Point _back, int _spin) {
    add(_begin, _back);
    spin = _spin;
  }
  void add(Point _begin, Point _back) {
    subsegment.emplace_back(_begin, _back);
  }
  int size() {
    int size = 0;
    for (int i = 0; i < subsegment.size(); i++) {
      size += subsegment[i].size();
    }
    return size;
  }
  int intersectionSize(Segment _segment) {
    int size = 0;
    for (int i = 0; i < subsegment.size(); i++) {
      for (int j = 0; j < _segment.subsegment.size(); j++) {
        size += subsegment[i].intersectionSize(_segment.subsegment[j]);
      }
    }
    return size;
  }
  std::vector<SubSegment> subsegment;
  int spin;
};
#endif