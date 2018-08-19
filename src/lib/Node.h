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
  char* getId();
  void setId(char* _id);
  int getValue();
  void setValue(int _value);
};
#endif