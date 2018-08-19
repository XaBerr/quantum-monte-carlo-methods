#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Node class", "[node]") {
  Node node;
  REQUIRE(strcmp((const char *)(node.getId()), "0-0") == 0);
}