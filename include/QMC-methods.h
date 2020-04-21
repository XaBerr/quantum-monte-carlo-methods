#include <cstring>  /* strcmp */
#include <iostream> /* coutm cin*/
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <cstdlib>  /* srand, rand, abs */

using namespace std;

#include "../src/lib/utility.h"
#include "../src/models/Node.h"
#include "../src/models/Arc2.h"
#include "../src/models/Ising2d.h"
#include "../src/algorithms/SimulatedAnnealing.h"
#include "../src/models/Ising2dTransverse.h"
#include "../src/algorithms/SantoroTosattiMartonak.h"
#include "../src/algorithms/SwendsenWang.h"
#include "../src/algorithms/RiegerKawashimaContinuous.h"
#include "../src/algorithms/RiegerKawashimaDiscrete.h"
