#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Ising2d Ising2d()", "[ising]") {
  Ising2d ising;
  REQUIRE(ising.getEnergy() == 0);
}

TEST_CASE("Ising2d generate()", "[ising]") {
  Ising2d ising;
  ising.generate();

  for (int i = 0; i < ising.getNodesLength(); i++) {
    for (int j = 0; j < ising.getNodesLength(); j++) {
      REQUIRE(ising.getNode(i, j) != 0);
    }
  }
  for (int i = 0; i < ising.getArcsLength(); i++) {
    REQUIRE(ising.getArc(i) != 0);
    REQUIRE((ising.getArc(i))->getNode1() != 0);
    REQUIRE((ising.getArc(i))->getNode2() != 0);
  }
}