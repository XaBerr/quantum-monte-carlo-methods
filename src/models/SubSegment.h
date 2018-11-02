#ifndef SubSegment_h
#define SubSegment_h

#include <vector>
#include "Point.h"

class SubSegment {
 public:
  SubSegment() {}
  SubSegment(Point _begin) {
    begin = _begin;
  }
  SubSegment(Point _begin, Point _end) {
    begin = _begin;
    end   = _end;
  }
  int size() {
    return abs(begin.x - end.x);
  }
  int intersectionSize(SubSegment _subsegment) {
    int max1, max2, max3, min1, min2, min3;
    if (begin.x > end.x) {
      max1 = begin.x;
      min1 = end.x;
    } else {
      max1 = end.x;
      min1 = begin.x;
    }
    if (_subsegment.begin.x > _subsegment.end.x) {
      max2 = _subsegment.begin.x;
      min2 = _subsegment.end.x;
    } else {
      max2 = _subsegment.end.x;
      min2 = _subsegment.begin.x;
    }
    max3 = (max1 > max2) ? max2 : max1;
    min3 = (min1 > min2) ? min1 : min2;
    return (max3 - min3 > 0) ? max3 - min3 : 0;
  }
  Point begin;
  Point end;
};
#endif