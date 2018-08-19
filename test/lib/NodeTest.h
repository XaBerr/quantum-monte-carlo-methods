#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Node Node()", "[node]") {
  Node node;
  REQUIRE(strcmp((const char *)(node.getId()), "0-0") == 0);
  REQUIRE(node.getSpin() == 1);
  REQUIRE(node.getValue() == 1);
}

TEST_CASE("Node Node(id, value)", "[node]") {
  Node node((char *)"1-2", 3, 4);
  REQUIRE(strcmp((const char *)(node.getId()), "1-2") == 0);
  REQUIRE(node.getSpin() == 3);
  REQUIRE(node.getValue() == 4);
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

TEST_CASE("Node setSpin()", "[node]") {
  Node node;
  node.setSpin(0);
  REQUIRE(node.getSpin() == 0);
}