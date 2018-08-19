#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Arc2 Arc2()", "[arc]") {
  Arc2 arc;
  REQUIRE(arc.getValue() == 0);
  REQUIRE(arc.getNode1() == 0);
  REQUIRE(arc.getNode2() == 0);
}

TEST_CASE("Arc2 Arc2(_node1, _node2, _value)", "[arc]") {
  Node node;
  Arc2 arc(&node, &node, 3);
  REQUIRE(arc.getValue() == 3);
  REQUIRE(arc.getNode1() == &node);
  REQUIRE(arc.getNode2() == &node);
}

TEST_CASE("Arc2 setValue()", "[arc]") {
  Arc2 arc;
  arc.setValue(3);
  REQUIRE(arc.getValue() == 3);
}

TEST_CASE("Arc2 setNode1() and setNode2", "[arc]") {
  Arc2 arc;
  Node node;
  arc.setNode1(&node);
  arc.setNode2(&node);
  REQUIRE(arc.getNode1() == &node);
  REQUIRE(arc.getNode2() == &node);
}