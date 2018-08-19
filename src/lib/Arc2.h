#include "Node.h"
#ifndef Arc2_h
#define Arc2_h
class Arc2 {
 private:
  Node* node1;
  Node* node2;
  double value;

 public:
  Arc2();
  Arc2(Node* _node1, Node* _node2, double _value);
  ~Arc2();
  double getValue();
  void setValue(double _value);
  Node* getNode1();
  void setNode1(Node* _node);
  Node* getNode2();
  void setNode2(Node* _node);
};

#endif