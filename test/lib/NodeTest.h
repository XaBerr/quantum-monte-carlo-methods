#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Node node()", "[node]") {
  Node node;
  REQUIRE(strcmp((const char *)(node.getId()), "0-0") == 0);
  REQUIRE(node.getValue() == 1);
}

TEST_CASE("Node node(id, value)", "[node]") {
  Node node((char *)"3-3", 3);
  REQUIRE(strcmp((const char *)(node.getId()), "3-3") == 0);
  REQUIRE(node.getValue() == 3);
}

TEST_CASE("Node setId()", "[node]") {
  Node node;
  node.setId((char *)"1-1");
  REQUIRE(strcmp((const char *)(node.getId()), "1-1") == 0);
}

TEST_CASE("Node setValue()", "[node]") {
  Node node;
  node.setValue(0);
  REQUIRE(node.getValue() == 0);
}