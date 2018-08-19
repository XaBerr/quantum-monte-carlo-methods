#ifndef Node_h
#define Node_h
class Node {
 private:
  char* id;
  int spin;
  double value;

 public:
  Node();
  Node(char* _id, int _spin, double _value);
  ~Node();
  char* getId();
  void setId(char* _id);
  int getSpin();
  void setSpin(int _spin);
  double getValue();
  void setValue(double _value);
};
#endif