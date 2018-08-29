#include "../../src/include.h"
#include "../catch.hpp"

static Uniform uniform;

TEST_CASE("RiegerKawashimaContinuous RiegerKawashimaContinuous()", "[rkc]") {
  RiegerKawashimaContinuous rkc;
  REQUIRE(rkc.scale != 0);
}
