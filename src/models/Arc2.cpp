#include "Arc2.h"

Arc2::Arc2() {
  node1 = nullptr;
  node2 = nullptr;
  value = 0;
}

Arc2::Arc2(Node* _node1, Node* _node2, double _value) {
  node1 = _node1;
  node2 = _node2;
  value = _value;
}