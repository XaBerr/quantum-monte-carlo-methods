#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("SimulatedAnnealing SimulatedAnnealing()", "[sa]") {
  SimulatedAnnealing sa;
  REQUIRE(sa.scale == 1);
}

TEST_CASE("SimulatedAnnealing generateNeighboringConfig()", "[sa]") {
  SimulatedAnnealing sa;
  Ising2d ising1, ising2;
  ising1.generate();
  ising2 = sa.generateNeighboringConfig(ising1);
  REQUIRE(ising1.getEnergy() != ising2.getEnergy());
}

TEST_CASE("SimulatedAnnealing run()", "[sa]") {
  SimulatedAnnealing sa;
  sa.startingConfig.generate();
  sa.run();
  REQUIRE(sa.endingConfig.getEnergy());
}