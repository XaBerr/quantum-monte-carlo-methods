#include "../../src/include.h"
#include "../catch.hpp"

static Uniform uniform;

TEST_CASE("Ising2dTransverse Ising2dTransverse()", "[ising]") {
  Ising2dTransverse ising;
  REQUIRE(ising.slices.size() == 0);
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
  ising.slices[(int)(uniform() * (float)(ising.numberOfreplicas - 1))]
      .nodes[(int)(uniform() * (float)(ising.mainReplica.nodes.size() - 1))]
            [(int)(uniform() * (float)(ising.mainReplica.nodes.size() - 1))]
      .flip();
  REQUIRE(energy != ising.getEnergy());
  ising.periodicBoundary = true;
  ising.mainReplica.periodicBoundary = true;
  ising.mainReplica.generate();
  ising.generate();
  REQUIRE(energy != ising.getEnergy());
}

TEST_CASE("Ising2dTransverse  ising1 = ising2", "[ising]") {
  Ising2dTransverse ising1, ising2;
  ising1.numberOfreplicas = 2;
  ising1.periodicBoundary = true;
  ising1.mainReplica.periodicBoundary = true;
  ising1.mainReplica.generate();
  ising1.generate();
  ising2 = ising1;
  REQUIRE(ising2.numberOfreplicas == ising1.numberOfreplicas);
  REQUIRE(ising2.periodicBoundary == ising1.periodicBoundary);
  REQUIRE(ising2.mainReplica.periodicBoundary ==
          ising1.mainReplica.periodicBoundary);
  REQUIRE(ising2.getEnergy() == ising1.getEnergy());
  ising1.slices[0].nodes[0][0].flip();
  REQUIRE(ising2.getEnergy() != ising1.getEnergy());
  ising1.generate();
  ising1.mainReplica.nodes[0][0].spin = 1;
  ising1.mainReplica.nodes[0][0].value = 1;
  ising2 = ising1;
  REQUIRE(ising2.getEnergy() == ising1.getEnergy());
}

TEST_CASE("Ising2dTransverse getDelta()", "[ising1,ising2]") {
  Ising2dTransverse ising1, ising2;
  ising1.mainReplica.size = 1;
  ising1.mainReplica.nodeMaxValue = 1;
  ising1.mainReplica.nodeMinValue = 1;
  ising1.mainReplica.arcMaxValue = 1;
  ising1.mainReplica.arcMinValue = 1;
  ising1.numberOfreplicas = 2;
  ising1.tranverseField = 1;
  ising1.mainReplica.generate();
  ising1.generate();
  ising1.mainReplica.nodes[0][0].spin = 1;
  ising1.mainReplica.nodes[0][0].value = 1;
  ising2 = ising1;
  REQUIRE(ising1.getEnergy() == -3);
  REQUIRE(ising2.getEnergy() == -3);
  REQUIRE(ising1.getDelta(ising2) == 0);
  REQUIRE(ising2.getDelta(ising1) == 0);
  ising1.slices[0].nodes[0][0].flip();
  REQUIRE(ising1.getEnergy() == 1);
  REQUIRE(ising2.getEnergy() == -3);
  REQUIRE(ising1.getDelta(ising2) == 4);
  REQUIRE(ising2.getDelta(ising1) == -4);
}