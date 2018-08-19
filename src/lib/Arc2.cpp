#include "Arc2.h"

Arc2::Arc2() {
  node1 = 0;
  node2 = 0;
  value = 0;
}

Arc2::Arc2(Node* _node1, Node* _node2, double _value) {
  node1 = _node1;
  node2 = _node2;
  value = _value;
}

Arc2::~Arc2() {}

double Arc2::getValue() { return value; }

void Arc2::setValue(double _value) { value = _value; }