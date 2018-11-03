#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Segment Segment()", "[seg]") {
  Segment seg;
  REQUIRE(seg.spin == 0);
  REQUIRE(seg.size() == 0);
}

TEST_CASE("Segment add(point, point)", "[seg]") {
  Segment seg;
  seg.add(1, 4);
  REQUIRE(seg.subsegment[0].begin == 1);
  REQUIRE(seg.subsegment[0].end == 4);
}

TEST_CASE("Segment Segment(point, point, spin)", "[seg]") {
  Segment seg(1, 4, 1);
  REQUIRE(seg.spin == 1);
  REQUIRE(seg.subsegment[0].begin == 1);
  REQUIRE(seg.subsegment[0].end == 4);
}

TEST_CASE("Segment size()", "[seg]") {
  Segment seg;
  REQUIRE(seg.size() == 0);
  seg.add(1, 4);
  REQUIRE(seg.size() == 3);
  seg.add(10, 4);
  REQUIRE(seg.size() == 9);
}

TEST_CASE("Segment intersect(segment)", "[seg1, seg2]") {
  Segment seg1, seg2;
  seg1.add(1, 2);
  seg1.add(4, 5);
  REQUIRE(seg1.intersectionSize(seg2) == 0);
  seg2.add(1, 2);
  REQUIRE(seg1.intersectionSize(seg2) == 1);
  seg2.add(4, 7);
  REQUIRE(seg1.intersectionSize(seg2) == 2);
}