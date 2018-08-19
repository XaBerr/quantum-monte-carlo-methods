#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Arc arc()", "[arc]") {
  Arc2 arc;
  REQUIRE(arc.getValue() == 0);
  // REQUIRE(arc.getValue() == 1);
}

// TEST_CASE("Node setId()", "[node]") {
//   Node node;
//   node.setId("1-1");
//   REQUIRE(strcmp((const char *)(node.getId()), "1-1") == 0);
// }

// TEST_CASE("Node setValue()", "[node]") {
//   Node node;
//   node.setValue(0);
//   REQUIRE(node.getValue() == 0);
// }