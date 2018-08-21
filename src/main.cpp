#include "include.h"

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
  for (int i = 0; i < sa.startingConfig.nodesLength; i++) {
    for (int j = 0; j < sa.startingConfig.nodesLength; j++) {
      sa.startingConfig.nodes[i][j].value = 1;
      sa.startingConfig.nodes[i][j].spin = (uniform() < 0.5) ? 1 : -1;
    }
  }
  /*
  Arcs value matrix
  1 1 1
  1 1 1
  1 1 1
  */
  for (int i = 0; i < sa.startingConfig.arcsLength; i++) {
    sa.startingConfig.arcs[i].value = 1;
  }

  printf("L'energia iniziale e' [%f]\n", sa.startingConfig.getEnergy());
  for (int i = 0; i < 10; i++) {
    sa.run();
    printf("L'energia finale e' [%f]\n", sa.endingConfig.getEnergy());
  }
}
