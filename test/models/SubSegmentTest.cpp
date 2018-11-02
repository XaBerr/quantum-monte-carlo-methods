#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("SubSegment SubSegment()", "[sseg]") {
  SubSegment sseg;
  REQUIRE(sseg.begin.x == 0);
  REQUIRE(sseg.begin.y == 0);
  REQUIRE(sseg.begin.z == 0);
  REQUIRE(sseg.end.x == 0);
  REQUIRE(sseg.end.y == 0);
  REQUIRE(sseg.end.z == 0);
}

TEST_CASE("SubSegment size()", "[sseg]") {
  SubSegment sseg;
  REQUIRE(sseg.size() == 0);
  sseg.end.x = 100;
  REQUIRE(sseg.size() == 100);
  sseg.begin.x = 200;
  REQUIRE(sseg.size() == 100);
}

TEST_CASE("SubSegment intersectionSize(subsegment)", "[sseg1, sseg2]") {
  SubSegment sseg1, sseg2;
  REQUIRE(sseg1.intersectionSize(sseg2) == 0);
  sseg1.begin.x = 5;
  sseg1.end.x   = 10;
  sseg2.begin.x = 1;
  sseg2.end.x   = 5;
  REQUIRE(sseg1.intersectionSize(sseg2) == 0);
  sseg2.end.x = 6;
  REQUIRE(sseg1.intersectionSize(sseg2) == 1);
  sseg2.begin.x = 5;
  sseg2.end.x   = 7;
  REQUIRE(sseg1.intersectionSize(sseg2) == 2);
  sseg2.begin.x = 8;
  sseg2.end.x   = 12;
  REQUIRE(sseg1.intersectionSize(sseg2) == 2);
  sseg2.begin.x = 1;
  sseg2.end.x   = 12;
  REQUIRE(sseg1.intersectionSize(sseg2) == 5);
}