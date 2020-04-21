#include <QMC-methods.h>
#include <catch2/catch.hpp>
using namespace QMCm;

TEST_CASE("Node Node()", "[node]") {
  Node node;
  REQUIRE(node.id == "0-0");
  REQUIRE(node.spin == 1);
  REQUIRE(node.value == 1);
}

TEST_CASE("Node Node(id, value)", "[node]") {
  Node node("1-2", 3, 4);
  REQUIRE(node.id == "1-2");
  REQUIRE(node.spin == 3);
  REQUIRE(node.value == 4);
}