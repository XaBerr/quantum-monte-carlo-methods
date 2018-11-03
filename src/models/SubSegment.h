#ifndef SubSegment_h
#define SubSegment_h

#include <vector>

class SubSegment {
 public:
  SubSegment() {
    begin = 0;
    end   = 0;
  }
  SubSegment(int _begin) {
    begin = _begin;
    end   = 0;
  }
  SubSegment(int _begin, int _end) {
    begin = _begin;
    end   = _end;
  }
  int size() {
    return abs(begin - end);
  }
  int intersectionSize(SubSegment _subsegment) {
    int max1, max2, max3, min1, min2, min3;
    if (begin > end) {
      max1 = begin;
      min1 = end;
    } else {
      max1 = end;
      min1 = begin;
    }
    if (_subsegment.begin > _subsegment.end) {
      max2 = _subsegment.begin;
      min2 = _subsegment.end;
    } else {
      max2 = _subsegment.end;
      min2 = _subsegment.begin;
    }
    max3 = (max1 > max2) ? max2 : max1;
    min3 = (min1 > min2) ? min1 : min2;
    return (max3 - min3 > 0) ? max3 - min3 : 0;
  }
  int begin;
  int end;
};
#endif