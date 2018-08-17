#include "../../src/lib/Ising.h"

TEST_CASE( "Ising model", "[ising]" ) {
  Ising ising;
  REQUIRE( ising.getEnergy() == 888 );
}