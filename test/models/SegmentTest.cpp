#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Segment Segment()", "[seg]") {
  Segment seg;
  REQUIRE(seg.spin == 0);
  REQUIRE(seg.size() == 0);
}

TEST_CASE("Segment add(point, point)", "[seg]") {
  Segment seg;
  seg.add(Point(1, 2, 3), Point(4, 5, 6));
  REQUIRE(seg.subsegment[0].begin.x == 1);
  REQUIRE(seg.subsegment[0].begin.y == 2);
  REQUIRE(seg.subsegment[0].begin.z == 3);
  REQUIRE(seg.subsegment[0].end.x == 4);
  REQUIRE(seg.subsegment[0].end.y == 5);
  REQUIRE(seg.subsegment[0].end.z == 6);
}

TEST_CASE("Segment Segment(point, point, spin)", "[seg]") {
  Segment seg(Point(1, 2, 3), Point(4, 5, 6), 1);
  REQUIRE(seg.spin == 1);
  REQUIRE(seg.subsegment[0].begin.x == 1);
  REQUIRE(seg.subsegment[0].begin.y == 2);
  REQUIRE(seg.subsegment[0].begin.z == 3);
  REQUIRE(seg.subsegment[0].end.x == 4);
  REQUIRE(seg.subsegment[0].end.y == 5);
  REQUIRE(seg.subsegment[0].end.z == 6);
}

TEST_CASE("Segment size()", "[seg]") {
  Segment seg;
  REQUIRE(seg.size() == 0);
  seg.add(Point(1, 2, 3), Point(4, 4, 4));
  REQUIRE(seg.size() == 3);
  seg.add(Point(10, 2, 3), Point(4, 4, 4));
  REQUIRE(seg.size() == 9);
}

TEST_CASE("Segment intersect(segment)", "[seg1, seg2]") {
  // Segment seg(Point(1, 2, 3), 1);
  // REQUIRE(seg.spin == 1);
  // REQUIRE(seg.size() == 1);
  // REQUIRE(seg.subsegment[0].begin.x == 1);
  // REQUIRE(seg.subsegment[0].begin.y == 2);
  // REQUIRE(seg.subsegment[0].begin.z == 3);
}