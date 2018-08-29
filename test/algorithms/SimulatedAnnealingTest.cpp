#include "../../src/include.h"
#include "../catch.hpp"

static Uniform uniform;

TEST_CASE("SimulatedAnnealing SimulatedAnnealing()", "[sa]") {
  SimulatedAnnealing sa;
  REQUIRE(sa.scale != 0);
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
  double min             = 999;
  sa.startingConfig.size = 3;
  sa.startingConfig.generate();
  for (int i = 0; i < sa.startingConfig.nodes.size(); i++) {
    for (int j = 0; j < sa.startingConfig.nodes[i].size(); j++) {
      sa.startingConfig.nodes[i][j].value = 1;
      sa.startingConfig.nodes[i][j].spin  = (uniform() < 0.5) ? 1 : -1;
    }
  }
  for (int i = 0; i < sa.startingConfig.arcs.size(); i++)
    for (int j = 0; j < sa.startingConfig.arcs[i].size(); j++)
      for (int k = 0; k < sa.startingConfig.arcs[i][k].size(); k++)
        sa.startingConfig.arcs[i][j][k].value = 1;

  for (int i = 0; i < 5; i++) {
    sa.run();
    if (min > sa.endingConfig.getEnergy()) min = sa.endingConfig.getEnergy();
  }
  REQUIRE(sa.startingConfig.getEnergy() > min);
}