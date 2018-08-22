#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Node Node()", "[node]") {
  Node node;
  REQUIRE(strcmp((const char *)(node.id), "0-0") == 0);
  REQUIRE(node.spin == 1);
  REQUIRE(node.value == 1);
}

TEST_CASE("Node Node(id, value)", "[node]") {
  Node node((char *)"1-2", 3, 4);
  REQUIRE(strcmp((const char *)(node.id), "1-2") == 0);
  REQUIRE(node.spin == 3);
  REQUIRE(node.value == 4);
}