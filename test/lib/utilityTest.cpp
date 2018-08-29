#include "../../src/include.h"
#include "../catch.hpp"

TEST_CASE("Uniform uniform", "[uniform]") {
  Uniform uniform;
  double array[50];
  bool oneValue     = true;
  bool sameSequence = true;
  for (int i = 0; i < 50; i++) {
    array[i] = uniform();
    if (i > 0 && array[i] != array[i - 1])
      oneValue = false;
  }
  REQUIRE(!oneValue);
  for (int i = 0; i < 50; i++) {
    if (array[i] != uniform())
      sameSequence = false;
  }
  REQUIRE(!sameSequence);
}
