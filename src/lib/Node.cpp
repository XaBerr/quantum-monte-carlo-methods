#include "Node.h"
Node::Node() {
  id = (char*)"0-0";
  // new char(strlen("0-0") + 1);
  // strcpy(pw, "0-0");
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