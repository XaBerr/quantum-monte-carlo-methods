#include "include.h"

using namespace QMCm;

static Uniform uniform;

int main(int argc, char const *argv[]) {
  SimulatedAnnealing sa;
  sa.startingConfig.size = 3;
  sa.startingConfig.generate();
  /*
  Nodes value matrix
  1 1 1
  1 1 1
  1 1 1
  */
  for (int i = 0; i < sa.startingConfig.nodes.size(); i++) {
    for (int j = 0; j < sa.startingConfig.nodes.size(); j++) {
      sa.startingConfig.nodes[i][j].value = 1;
      sa.startingConfig.nodes[i][j].spin  = (uniform() < 0.5) ? 1 : -1;
    }
  }
  /*
  Arcs value matrix
  1 1 1
  1 1 1
  1 1 1
  */
  for (int i = 0; i < sa.startingConfig.arcs.size(); i++)
    for (int j = 0; j < sa.startingConfig.arcs[i].size(); j++)
      for (int k = 0; k < sa.startingConfig.arcs[i][k].size(); k++)
        sa.startingConfig.arcs[i][j][k].value = 1;

  printf("The starting energy is [%f]\n", sa.startingConfig.getEnergy());
  for (int i = 0; i < 10; i++) {
    sa.run();
    printf("The ending energy is [%f]\n", sa.endingConfig.getEnergy());
  }
}
