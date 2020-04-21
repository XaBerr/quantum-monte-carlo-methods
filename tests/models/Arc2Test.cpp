#include <QMC-methods.h>
#include <catch2/catch.hpp>
using namespace QMCm;

TEST_CASE("Arc2 Arc2()", "[arc]") {
  Arc2 arc;
  REQUIRE(arc.value == 0);
  REQUIRE(arc.node1 == 0);
  REQUIRE(arc.node2 == 0);
}

TEST_CASE("Arc2 Arc2(_node1, _node2, _value)", "[arc]") {
  Node node;
  Arc2 arc(&node, &node, 3);
  REQUIRE(arc.value == 3);
  REQUIRE(arc.node1 == &node);
  REQUIRE(arc.node2 == &node);
}