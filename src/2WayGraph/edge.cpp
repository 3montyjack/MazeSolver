#include "edge.h"

class Node;

Edge::Edge(Node * FirstConnection) {
  holding		 = false;
  connections[0] = FirstConnection;
  connections[1] = 0;
};

Edge::~Edge() {
  // delete Edge;
};

void Edge::deleteMe(Node * Caller) {
  if (connections[0] == Caller) {
    // delete connections[1];
  }
}

Edge::setEdge(Node * &location)
{
  bool flag = false;

  if (!inited) {
    connections[0] = location;
    inited		   = true;
    flag = true;
  } else if (!holding) {
    // cout << "Setting EdgeConnection: " << location << " " << connections[0] << endl;
    connections[1] = location;
    holding		   = true;
    flag = true;
  }
  return flag;
};

Node * Edge::getOtherEnd(Node * oneSide) {
  if (connections[0] == oneSide) {
    return connections[1];
  } else if (connections[1] == oneSide) {
    return connections[0];
  }
  return (Node *) -1;
};

bool Edge::getValidEdge() {
  return inited;
};

bool Edge::getConnected() {
  return holding;
};
