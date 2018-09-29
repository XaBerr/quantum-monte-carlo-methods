#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Segment Segment()", "[seg]") {
  Segment seg;
  REQUIRE(seg.spin == 0);
  REQUIRE(seg.size() == 0);
}

TEST_CASE("Segment Segment(point, spin)", "[seg]") {
  Segment seg(Point(1, 2, 3), 1);
  REQUIRE(seg.spin == 1);
  REQUIRE(seg.size() == 1);
  REQUIRE(seg.points[0].x == 1);
  REQUIRE(seg.points[0].y == 2);
  REQUIRE(seg.points[0].z == 3);
  seg.points.push_back(Point(4, 5, 6));
  REQUIRE(seg.spin == 1);
  REQUIRE(seg.size() == 2);
  REQUIRE(seg.points[1].x == 4);
  REQUIRE(seg.points[1].y == 5);
  REQUIRE(seg.points[1].z == 6);
}