#include "RiegerKawashimaContinuous.h"
#include "../lib/utility.h"
#include <math.h>
#include <stdio.h>

static Uniform uniform;

RiegerKawashimaContinuous::RiegerKawashimaContinuous() {
  temperature      = 1;
  numberOfreplicas = 3;
  startingField    = 100;
  endingField      = 0;
  deltaField       = 1;
  scale            = 10;
}
