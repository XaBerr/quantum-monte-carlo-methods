#include "Arc2.h"

#ifndef Ising2d_h
#define Ising2d_h
class Ising2d {
 public:
  Ising2d();
  Ising2d(Ising2d& ising);
  ~Ising2d();
  void generate();
  void setNodeValue(int i, int j, int value);
  double getEnergy();
  int getNodesLength();
  int getArcsLength();
  Node* getNode(int i, int j);
  Arc2* getArc(int i);
  double getDelta(Ising2d* ising);
  void setSize(int _size);
  int getSize();
  void setFavorAlignment(bool _favorAlignment);
  bool getFavorAlignment();
  void setFavorSpinUp(bool _favorSpinUp);
  bool getFavorSpinUp();
  void setNodeMaxValue(double _nodeMaxValue);
  double getNodeMaxValue();
  void setNodeMinValue(double _nodeMinValue);
  double getNodeMinValue();
  void setArcMaxValue(double _arcMaxValue);
  double getArcMaxValue();
  void setArcMinValue(double _arcMinValue);
  double getArcMinValue();

 private:
  Node** nodes;
  Arc2* arcs;
  int nodesLength;
  int arcsLength;
  int size;
  bool favorAlignment;
  bool favorSpinUp;
  double nodeMaxValue;
  double nodeMinValue;
  double arcMaxValue;
  double arcMinValue;
};
#endif