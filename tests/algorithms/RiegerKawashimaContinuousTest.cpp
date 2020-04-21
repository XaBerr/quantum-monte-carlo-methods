#include <QMC-methods.h>
#include <catch2/catch.hpp>
using namespace QMCm;
static Uniform uniform;

TEST_CASE("RiegerKawashimaContinuous RiegerKawashimaContinuous()", "[rkc]") {
  RiegerKawashimaContinuous rkc;
  REQUIRE(rkc.scale != 0);
}
