#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Ising2d Ising2d()", "[ising]") {
  Ising2d ising;
  REQUIRE(ising.nodes.size() == 0);
}

TEST_CASE("Ising2d generate()", "[ising]") {
  Ising2d ising;
  ising.generate();
  for (int i = 0; i < ising.nodes.size(); i++) {
    for (int j = 0; j < ising.nodes.size(); j++) {
      REQUIRE(ising.nodes[i][j].id != 0);
    }
  }
  for (int i = 0; i < ising.arcs.size(); i++) {
    REQUIRE(ising.arcs[i].node1 != 0);
    REQUIRE(ising.arcs[i].node2 != 0);
  }
  ising.size = 1;
  ising.generate();
  REQUIRE(ising.arcs.size() == 0);
  REQUIRE(ising.nodes.size() == 1);
  ising.size = 2;
  ising.generate();
  REQUIRE(ising.arcs.size() == 4);
  REQUIRE(ising.nodes.size() == 2);
}

TEST_CASE("Ising2d getEnergy()", "[ising]") {
  Ising2d ising;
  REQUIRE(ising.getEnergy() == 0);
  ising.generate();
  double energy = ising.getEnergy();
  ising.periodicBoundary = true;
  ising.generate();
  REQUIRE(ising.getEnergy() != energy);
}

TEST_CASE("Ising2d ising1 = ising2", "[ising]") {
  Ising2d ising1, ising2;
  ising1.size = 2;
  ising1.periodicBoundary = true;
  ising1.generate();
  ising2 = ising1;
  REQUIRE(ising2.size == ising1.size);
  REQUIRE(ising2.periodicBoundary == ising1.periodicBoundary);
  REQUIRE(ising2.getEnergy() == ising1.getEnergy());
  ising1.nodes[0][0].flip();
  REQUIRE(ising2.getEnergy() != ising1.getEnergy());
}

TEST_CASE("Ising2d getDelta()", "[ising1,ising2]") {
  Ising2d ising1, ising2;
  ising1.size = 1;
  ising2.size = 1;
  ising1.generate();
  ising2.generate();
  ising1.nodes[0][0].spin = 1;
  ising1.nodes[0][0].value = 1;
  ising2.nodes[0][0].spin = 1;
  ising2.nodes[0][0].value = 1;
  REQUIRE(ising1.getEnergy() == -1);
  REQUIRE(ising2.getEnergy() == -1);
  REQUIRE(ising1.getDelta(ising2) == 0);
  REQUIRE(ising2.getDelta(ising1) == 0);
  ising1.nodes[0][0].value = 2;
  REQUIRE(ising1.getDelta(ising2) == -1);
  REQUIRE(ising2.getDelta(ising1) == 1);
}