#include "Ising2dTransverse.h"
#include <cmath>
#include <limits>
#include <algorithm>

Ising2dTransverse::Ising2dTransverse() {
  numberOfreplicas = 3;
  tranverseField   = 1;
  periodicBoundary = false;
}

void Ising2dTransverse::generate() {
  slices = std::vector<Ising2d>(numberOfreplicas, mainReplica);
}

double Ising2dTransverse::getEnergy() const {
  double energy = 0;
  for (int i = 0; i < slices.size(); i++) {
    energy += slices[i].getEnergy();
    for (int j = 0; j < slices[i].nodes.size(); j++)
      for (int k = 0; k < slices[i].nodes[j].size(); k++)
        if (periodicBoundary || i != slices.size() - 1)
          energy += -tranverseField * slices[i].nodes[j][k].spin * slices[(i + 1) % slices.size()].nodes[j][k].spin;
  }
  return energy;
}

double Ising2dTransverse::getIsingDiscreteEnergy() const {
  double energy = std::numeric_limits<double>::max();
  if (slices.size() <= 0) return 0;
  for (auto& slice : slices)
    energy = std::min(energy, slice.getEnergy());
  return energy;
}

double Ising2dTransverse::getIsingContinueEnergy() const {
  double energy = 0;
  if (slices.size() <= 0) return 0;
  for (auto& slice : slices)
    energy += slice.getEnergy();
  return energy / slices.size();
}

double Ising2dTransverse::getDelta(const Ising2dTransverse& ising) const {
  double myEnergy    = getEnergy();
  double otherEnergy = ising.getEnergy();
  return (myEnergy > otherEnergy ? 1 : -1) * abs(myEnergy - otherEnergy);
}