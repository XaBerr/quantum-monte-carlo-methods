#include "Ising2dTransverse.h"
#include <cstdlib>

Ising2dTransverse::Ising2dTransverse() {
  slices = 0;
  numberOfReplica = 3;
  tranverseField = 1;
  slicesLength = 0;
  periodicBoundary = false;
}

Ising2dTransverse::Ising2dTransverse(Ising2dTransverse& ising) {
  slices = ising.slices;
  numberOfReplica = ising.numberOfReplica;
  tranverseField = ising.tranverseField;
  slicesLength = ising.slicesLength;
  periodicBoundary = ising.periodicBoundary;
  mainReplica = ising.mainReplica;
  generate();
}

Ising2dTransverse::~Ising2dTransverse() {}

void Ising2dTransverse::generate() {
  slicesLength = numberOfReplica;
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
      for (int k = 0; k < slices[i].nodesLength; k++) {
        if (periodicBoundary || ((i + 1) % slicesLength)) {
          energy += -tranverseField * slices[i].nodes[j][k].spin *
                    slices[(i + 1) % slicesLength].nodes[j][k].spin;
        }
      }
    }
  }
  return energy;
}

double Ising2dTransverse::getDelta(Ising2dTransverse* ising) {
  return (getEnergy() > ising->getEnergy() ? 1 : -1) *
         abs(getEnergy() - ising->getEnergy());
}