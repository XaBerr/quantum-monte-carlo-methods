#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("SimulatedAnnealing SimulatedAnnealing()", "[sa]") {
  SimulatedAnnealing sa;
  REQUIRE(sa.scale == 1);
}