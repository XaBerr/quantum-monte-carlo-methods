#include "../../src/include.h"
#include "../catch.hpp"

static Uniform uniform;

TEST_CASE("SantoroTosattiMartonak SantoroTosattiMartonak()", "[stm]") {
  SantoroTosattiMartonak stm;
  REQUIRE(stm.scale != 0);
}

TEST_CASE("SantoroTosattiMartonak generateNeighboringConfig()", "[stm]") {
  SantoroTosattiMartonak stm;
  Ising2dTransverse ising1, ising2;
  ising1.numberOfReplica = 4;
  ising1.mainReplica.generate();
  ising1.generate();
  ising2 = stm.generateNeighboringConfig(ising1);
  REQUIRE(ising1.getEnergy() != ising2.getEnergy());
}

TEST_CASE("SantoroTosattiMartonak run()", "[stm]") {
  SantoroTosattiMartonak stm;
  double min = 999;
  double temp;
  stm.startingConfig.numberOfReplica = 3;
  stm.startingConfig.mainReplica.size = 3;
  stm.startingConfig.mainReplica.generate();

  for (int i = 0; i < stm.startingConfig.mainReplica.nodes.size(); i++) {
    for (int j = 0; j < stm.startingConfig.mainReplica.nodes.size(); j++) {
      stm.startingConfig.mainReplica.nodes[i][j].value = 1;
      stm.startingConfig.mainReplica.nodes[i][j].spin =
          (uniform() < 0.5) ? 1 : -1;
    }
  }
  for (int i = 0; i < stm.startingConfig.mainReplica.arcs.size(); i++) {
    stm.startingConfig.mainReplica.arcs[i].value = 1;
  }
  stm.startingConfig.generate();

  for (int i = 0; i < 5; i++) {
    stm.run();
    temp = stm.endingConfig.getIsingDiscreteEnergy();
    if (min > temp) {
      min = temp;
    }
  }
  REQUIRE(stm.startingConfig.mainReplica.getEnergy() > min);
}