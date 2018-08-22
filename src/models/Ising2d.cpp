#include "Ising2d.h"
#include <cstdlib>
#include "../lib/functions.h"

Ising2d::Ising2d() {
  size = 3;
  nodes = 0;
  nodesLength = 0;
  arcs = 0;
  arcsLength = 0;
  favorAlignment = true;
  favorSpinUp = true;
  periodicBoundary = false;
  nodeMaxValue = 1;
  nodeMinValue = -1;
  arcMaxValue = 1;
  arcMinValue = -1;
}

Ising2d::Ising2d(Ising2d& ising) {
  size = ising.size;
  favorAlignment = ising.favorAlignment;
  favorSpinUp = ising.favorSpinUp;
  nodeMaxValue = ising.nodeMaxValue;
  nodeMinValue = ising.nodeMinValue;
  arcMaxValue = ising.arcMaxValue;
  arcMinValue = ising.arcMinValue;
  periodicBoundary = ising.periodicBoundary;
  generate();
  for (int i = 0; i < nodesLength; i++) {
    for (int j = 0; j < nodesLength; j++) {
      nodes[i][j].value = ising.nodes[i][j].value;
      nodes[i][j].spin = ising.nodes[i][j].spin;
    }
  }
  for (int i = 0; i < arcsLength; i++) {
    arcs[i].value = ising.arcs[i].value;
  }
}

Ising2d::~Ising2d() {}

void Ising2d::generate() {
  int cont = 0;
  nodesLength = size;
  arcsLength = (size - 1) * (size - 1) * 2 + (size - 1) * 2;
  arcs = new Arc2[arcsLength];
  nodes = new Node*[nodesLength];
  for (int i = 0; i < nodesLength; i++) {
    nodes[i] = new Node[nodesLength];
    for (int j = 0; j < nodesLength; j++) {
      nodes[i][j].id = (char*)(i + " " + j);
      nodes[i][j].value =
          uniform() * (nodeMaxValue - nodeMinValue) + nodeMinValue;
      if (i > 0) {
        arcs[cont].node1 = &(nodes[i - 1][j]);
        arcs[cont].node2 = &(nodes[i][j]);
        arcs[cont++].value =
            uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
      }
      if (periodicBoundary && (i == nodesLength - 1)) {
        arcs[cont].node1 = &(nodes[i][j]);
        arcs[cont].node2 = &(nodes[0][j]);
        arcs[cont++].value =
            uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
      }
      if (j > 0) {
        arcs[cont].node1 = &(nodes[i][j - 1]);
        arcs[cont].node2 = &(nodes[i][j]);
        arcs[cont++].value =
            uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
      }
      if (periodicBoundary && (j == nodesLength - 1)) {
        arcs[cont].node1 = &(nodes[i][j]);
        arcs[cont].node2 = &(nodes[i][0]);
        arcs[cont++].value =
            uniform() * (arcMaxValue - arcMinValue) + arcMinValue;
      }
    }
  }
}

double Ising2d::getEnergy() {
  double energy = 0;
  int alpha = favorSpinUp ? -1 : 1;
  int beta = favorAlignment ? -1 : 1;
  for (int i = 0; i < nodesLength; i++) {
    for (int j = 0; j < nodesLength; j++) {
      energy += alpha * nodes[i][j].value * nodes[i][j].spin;
    }
  }
  for (int i = 0; i < arcsLength; i++) {
    energy += beta * arcs[i].value * arcs[i].node1->spin * arcs[i].node2->spin;
  }
  return energy;
}

double Ising2d::getDelta(Ising2d* ising) {
  return (getEnergy() > ising->getEnergy() ? 1 : -1) *
         abs(getEnergy() - ising->getEnergy());
}