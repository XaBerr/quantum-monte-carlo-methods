#include "Ising2dTransverse.h"
#include <cstdlib>

Ising2dTransverse::Ising2dTransverse() {
  slices = 0;
  tranverseField = 0;
  slicesLength = 1;
}

Ising2dTransverse::~Ising2dTransverse() {}

void Ising2dTransverse::generate() {
  slices = new Ising2d[slicesLength];
  for (int i = 0; i < slicesLength; i++) {
    slices[i] = mainReplica;
  }
}

double Ising2dTransverse::getEnergy() {
  double energy = 0;
  for (int i = 0; i < slicesLength; i++) {
    energy += slices[i].getEnergy();
    for (int j = 0; j < slices[i].nodesLength; j++) {
      for (int k = 0; k < slices[i].nodesLength - 1; k++) {
        energy += -tranverseField * slices[i].nodes[j][j].spin *
                  slices[i].nodes[j][j].spin;
      }
    }
  }
  return energy;
}

double Ising2dTransverse::getDelta(Ising2dTransverse* ising) {
  return (getEnergy() > ising->getEnergy() ? 1 : -1) *
         abs(getEnergy() - ising->getEnergy());
}