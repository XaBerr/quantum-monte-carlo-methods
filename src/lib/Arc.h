#include "Node.h"
#ifndef Arc_h
#define Arc_h
class Arc {
 private:
  Node* node1;
  Node* node2;
  double value;

 public:
  Arc(Node* _node1, Node* _node2, double _value);
  ~Arc();
};

#endif