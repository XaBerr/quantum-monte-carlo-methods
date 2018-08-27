#include "../../src/include.h"
#include "../catch.hpp"

static Uniform uniform;

TEST_CASE("SwendsenWang SwendsenWang()", "[sw]") {
  SwendsenWang sw;
  REQUIRE(sw.scale != 0);
}