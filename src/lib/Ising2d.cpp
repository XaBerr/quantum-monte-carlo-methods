#include "Ising2d.h"
#include <cstdlib>

Ising2d::Ising2d() {
  size = 3;
  nodes = 0;
  nodesLength = 0;
  arcs = 0;
  arcsLength = 0;
  favorAlignment = true;
  favorSpinUp = true;
  nodeMaxValue = 1;
  nodeMinValue = -1;
  arcMaxValue = 1;
  arcMinValue = -1;
}

Ising2d::Ising2d(Ising2d& ising) {
  size = ising.getSize();
  favorAlignment = ising.getFavorAlignment();
  favorSpinUp = ising.getFavorSpinUp();
  nodeMaxValue = ising.getNodeMaxValue();
  nodeMinValue = ising.getNodeMinValue();
  arcMaxValue = ising.getArcMaxValue();
  arcMinValue = ising.getArcMinValue();
  generate();
  for (int i = 0; i < nodesLength; i++) {
    for (int j = 0; j < nodesLength; j++) {
      nodes[i][j].setValue((ising.getNode(i, j))->getValue());
      nodes[i][j].setSpin((ising.getNode(i, j))->getSpin());
    }
  }
  for (int i = 0; i < arcsLength; i++) {
    arcs[i].setValue((ising.getArc(i)->getValue()));
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
      nodes[i][j].setId((char*)(i + " " + j));
      nodes[i][j].setValue(rand() * (nodeMaxValue - nodeMinValue) +
                           nodeMinValue);
      if (i > 0) {
        arcs[cont].setNode1(&(nodes[i - 1][j]));
        arcs[cont].setNode2(&(nodes[i][j]));
        arcs[cont++].setValue(rand() * (arcMaxValue - arcMinValue) +
                              arcMinValue);
      }
      if (j > 0) {
        arcs[cont].setNode1(&(nodes[i][j - 1]));
        arcs[cont].setNode2(&(nodes[i][j]));
        arcs[cont++].setValue(rand() * (arcMaxValue - arcMinValue) +
                              arcMinValue);
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
      energy += alpha * nodes[i][j].getValue() * nodes[i][j].getSpin();
    }
  }
  for (int i = 0; i < arcsLength; i++) {
    energy += beta * arcs[i].getValue() * (arcs[i].getNode1())->getSpin() *
              (arcs[i].getNode2())->getSpin();
  }
  return energy;
}

int Ising2d::getNodesLength() { return nodesLength; }

int Ising2d::getArcsLength() { return arcsLength; }

Node* Ising2d::getNode(int i, int j) { return &nodes[i][j]; }

Arc2* Ising2d::getArc(int i) { return &arcs[i]; }

double Ising2d::getDelta(Ising2d* ising) {
  return (getEnergy() > ising->getEnergy() ? 1 : -1) *
         abs(getEnergy() - ising->getEnergy());
}

void Ising2d::setSize(int _size) { size = _size; }

int Ising2d::getSize() { return size; }

void Ising2d::setFavorAlignment(bool _favorAlignment) {
  favorAlignment = _favorAlignment;
}

bool Ising2d::getFavorAlignment() { return favorAlignment; }

void Ising2d::setFavorSpinUp(bool _favorSpinUp) { favorSpinUp = _favorSpinUp; }

bool Ising2d::getFavorSpinUp() { return favorSpinUp; }

void Ising2d::setNodeMaxValue(double _nodeMaxValue) {
  nodeMaxValue = _nodeMaxValue;
}

double Ising2d::getNodeMaxValue() { return nodeMaxValue; }

void Ising2d::setNodeMinValue(double _nodeMinValue) {
  nodeMinValue = _nodeMinValue;
}

double Ising2d::getNodeMinValue() { return nodeMinValue; }

void Ising2d::setArcMaxValue(double _arcMaxValue) {
  arcMaxValue = _arcMaxValue;
}

double Ising2d::getArcMaxValue() { return arcMaxValue; }

void Ising2d::setArcMinValue(double _arcMinValue) {
  arcMinValue = _arcMinValue;
}

double Ising2d::getArcMinValue() { return arcMinValue; }
