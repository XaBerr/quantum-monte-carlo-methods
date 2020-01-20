#ifndef Arc2_h
#define Arc2_h

#include "Node.h"

namespace QMCm {
class Arc2 {
 public:
  Arc2();
  Arc2(Node* _node1, Node* _node2, double _value);
  Node* node1;
  Node* node2;
  double value;
};
};  // namespace QMCm

#endif