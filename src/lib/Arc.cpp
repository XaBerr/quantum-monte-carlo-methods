#include "Arc.h"

Arc::Arc(Node* _node1, Node* _node2, double _value) {
  node1 = _node1;
  node2 = _node2;
  value = _value;
}

Arc::~Arc() {}