#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Ising2dTransverse Ising2dTransverse()", "[ising]") {
  Ising2dTransverse ising;
  REQUIRE(ising.slices == 0);
}

TEST_CASE("Ising2dTransverse getEnergy()", "[ising]") {
  Ising2dTransverse ising;
  REQUIRE(ising.getEnergy() == 0);
  ising.periodicBoundary = false;
  ising.mainReplica.periodicBoundary = false;
  ising.mainReplica.generate();
  ising.generate();
  double energy = ising.getEnergy();
  REQUIRE(energy != 0);
  ising.periodicBoundary = true;
  ising.mainReplica.periodicBoundary = true;
  ising.mainReplica.generate();
  ising.generate();
  REQUIRE(energy != ising.getEnergy());
}