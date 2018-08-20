#include "Node.h"
#ifndef Arc2_h
#define Arc2_h
class Arc2 {
 public:
  Arc2();
  Arc2(Node* _node1, Node* _node2, double _value);
  ~Arc2();
  Node* node1;
  Node* node2;
  double value;
};

#endif