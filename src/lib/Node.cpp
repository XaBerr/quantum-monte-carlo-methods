#include "Node.h"
Node::Node() {
  id = (char*)"0-0";
  value = 1;
}

Node::Node(char* _id, int _value) {
  id = _id;
  value = _value;
}

Node::~Node() {
  id = (char*)"0-0";
  value = 1;
}

char* Node::getId() { return id; }

void Node::setId(char* _id) { id = _id; }

int Node::getValue() { return value; }

void Node::setValue(int _value) { value = _value; }