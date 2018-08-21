#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Ising2d Ising2dTransverse()", "[ising]") {
  Ising2dTransverse ising;
  REQUIRE(ising.slices == 0);
}

TEST_CASE("Ising2d getEnergy()", "[ising]") {
  Ising2dTransverse ising;
  ising.mainReplica.generate();
  ising.generate();
  REQUIRE(ising.getEnergy() != 0);
}