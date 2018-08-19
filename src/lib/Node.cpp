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

Node::~Node() {}

char* Node::getId() { return id; }

void Node::setId(char* _id) { id = _id; }

double Node::getValue() { return value; }

void Node::setValue(double _value) { value = _value; }

int Node::getSpin() { return spin; }

void Node::setSpin(int _spin) { spin = _spin; }