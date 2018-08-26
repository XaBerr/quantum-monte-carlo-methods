#ifndef Node_h
#define Node_h

#include <string>

class Node {
 public:
  Node();
  Node(const std::string _id, int _spin, double _value);
  void flip();

  std::string id;
  int spin;
  double value;
};
#endif