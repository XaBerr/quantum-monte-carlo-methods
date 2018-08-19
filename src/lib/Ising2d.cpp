#include "Ising2d.h"

Ising2d::Ising2d() {
  size = 3;
  nodes = 0;
  nodesLength = 0;
  arcs = 0;
  arcsLength = 0;
  favorAlignment = true;
  favorSpinUp = true;
  nodeMaxValue = 0;
  nodeMinValue = 0;
  arcMaxValue = 0;
  arcMinValue = 0;
}

Ising2d::~Ising2d() {}

void Ising2d::generate() {
  nodesLength = size;
  nodes = new Node *[nodesLength];
  for (int i = 0; i < nodesLength; ++i) {
    nodes[i] = new Node[nodesLength];
  }
  arcsLength = (size - 1) * (size - 1) * 2 + (size - 1) * 2;
  arcs = new Arc2[arcsLength];
}

double Ising2d::getEnergy() {
  double energy = 0;
  int alpha = favorSpinUp ? -1 : 1;
  int beta = favorAlignment ? -1 : 1;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      energy += alpha * nodes[i][j].getValue() * nodes[i][j].getSpin();
    }
  }
  for (int i = 0; i < arcsLength; i++) {
    energy += beta * arcs[i].getValue() * (arcs[i].getNode1())->getSpin() *
              (arcs[i].getNode2())->getSpin();
  }
  return energy;
}