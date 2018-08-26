#include "Node.h"

Node::Node() {
  id = "0-0";
  value = 1;
  spin = 1;
}

Node::Node(const std::string _id, int _spin, double _value) {
  id = _id;
  spin = _spin;
  value = _value;
}

void Node::flip() { spin *= -1; }