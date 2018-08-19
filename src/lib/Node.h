#ifndef Node_h
#define Node_h
class Node {
 private:
  char* id;
  int value;

 public:
  Node();
  Node(char* _id, int _value);
  ~Node();
};
#endif