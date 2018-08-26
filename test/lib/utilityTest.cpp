#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Uniform uniform", "[uniform]") {
  Uniform uniform;
  double array[50];
  bool equals = true;
  for (int i = 0; i < 50; i++) {
    array[i] = uniform();
    // printf("Random number [%f]\n", array[i]);
    if (i > 0 && array[i] != array[i - 1]) {
      equals = false;
    }
  }
  REQUIRE(!equals);
}
