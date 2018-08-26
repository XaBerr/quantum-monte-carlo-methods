#include "Node.h"
Node::Node() {
  id = (char*)"0-0";
  value = 1;
  spin = 1;
}

Node::Node(char* _id, int _spin, double _value) {
  id = _id;
  spin = _spin;
  value = _value;
}

void Node::flip() { spin *= -1; }