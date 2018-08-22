#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("SantoroTosattiMartonak SantoroTosattiMartonak()", "[stm]") {
  SantoroTosattiMartonak stm;
  REQUIRE(stm.scale != 0);
}

TEST_CASE("SantoroTosattiMartonak generateNeighboringConfig()", "[stm]") {
  // SantoroTosattiMartonak stm;
  // Ising2dTransverse ising1, ising2;
  // ising1.mainReplica.generate();
  // ising1.generate();
  // ising2 = stm.generateNeighboringConfig(ising1);
  // REQUIRE(ising1.getEnergy() != ising2.getEnergy());
}

TEST_CASE("SantoroTosattiMartonak run()", "[stm]") {
  // SantoroTosattiMartonak stm;
  // double min = 999;
  // stm.startingConfig.size = 3;
  // stm.startingConfig.generate();
  // for (int i = 0; i < stm.startingConfig.nodesLength; i++) {
  //   for (int j = 0; j < stm.startingConfig.nodesLength; j++) {
  //     stm.startingConfig.nodes[i][j].value = 1;
  //     stm.startingConfig.nodes[i][j].spin = (uniform() < 0.5) ? 1 : -1;
  //   }
  // }
  // for (int i = 0; i < stm.startingConfig.arcsLength; i++) {
  //   stm.startingConfig.arcs[i].value = 1;
  // }

  // for (int i = 0; i < 5; i++) {
  //   stm.run();
  //   if (min > stm.endingConfig.getEnergy()) min =
  //   stm.endingConfig.getEnergy();
  // }
  // REQUIRE(stm.startingConfig.getEnergy() >= min);
}