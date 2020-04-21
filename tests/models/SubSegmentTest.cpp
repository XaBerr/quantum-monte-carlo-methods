#include <QMC-methods.h>
#include <catch2/catch.hpp>
using namespace QMCm;

TEST_CASE("SubSegment SubSegment()", "[sseg]") {
  SubSegment sseg;
  REQUIRE(sseg.begin == 0);
  REQUIRE(sseg.end == 0);
}

TEST_CASE("SubSegment size()", "[sseg]") {
  SubSegment sseg;
  REQUIRE(sseg.size() == 0);
  sseg.end = 100;
  REQUIRE(sseg.size() == 100);
  sseg.begin = 200;
  REQUIRE(sseg.size() == 100);
}

TEST_CASE("SubSegment intersectionSize(subsegment)", "[sseg1, sseg2]") {
  SubSegment sseg1, sseg2;
  REQUIRE(sseg1.intersectionSize(sseg2) == 0);
  sseg1.begin = 5;
  sseg1.end   = 10;
  sseg2.begin = 1;
  sseg2.end   = 5;
  REQUIRE(sseg1.intersectionSize(sseg2) == 0);
  sseg2.end = 6;
  REQUIRE(sseg1.intersectionSize(sseg2) == 1);
  sseg2.begin = 5;
  sseg2.end   = 7;
  REQUIRE(sseg1.intersectionSize(sseg2) == 2);
  sseg2.begin = 8;
  sseg2.end   = 12;
  REQUIRE(sseg1.intersectionSize(sseg2) == 2);
  sseg2.begin = 1;
  sseg2.end   = 12;
  REQUIRE(sseg1.intersectionSize(sseg2) == 5);
}