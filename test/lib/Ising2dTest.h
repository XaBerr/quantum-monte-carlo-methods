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

TEST_CASE("Ising2d setSize()", "[ising]") {
  Ising2d ising;
  ising.setSize(1);
  ising.generate();
  REQUIRE(ising.getArcsLength() == 0);
  REQUIRE(ising.getNodesLength() == 1);
  ising.setSize(2);
  ising.generate();
  REQUIRE(ising.getArcsLength() == 4);
  REQUIRE(ising.getNodesLength() == 2);
}

TEST_CASE("Ising2d getDelta()", "[ising1,ising2]") {
  Ising2d ising1, ising2;
  ising1.setSize(1);
  ising2.setSize(1);
  ising1.generate();
  ising2.generate();
  (ising1.getNode(0, 0))->setSpin(1);
  (ising1.getNode(0, 0))->setValue(1);
  (ising2.getNode(0, 0))->setSpin(1);
  (ising2.getNode(0, 0))->setValue(1);
  REQUIRE(ising1.getEnergy() == -1);
  REQUIRE(ising2.getEnergy() == -1);
  REQUIRE(ising1.getDelta(&ising2) == 0);
  REQUIRE(ising2.getDelta(&ising1) == 0);
  (ising1.getNode(0, 0))->setValue(2);
  REQUIRE(ising1.getDelta(&ising2) == -1);
  REQUIRE(ising2.getDelta(&ising1) == 1);
}