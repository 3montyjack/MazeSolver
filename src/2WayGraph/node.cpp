#include "node.h"

Node::Node(int x, int y) {
  end			= false;
  searched		= false;
  connectionNum = 0;
  this->x		= x;
  this->y		= y;
  for (int i = 0; i < 4; i++) {
    connections[i] = new Edge(this);
  }
};

Node::Node() {
  Node(-1, -1);
};

Node::~Node() {
  for (int i = 0; i < 4; i++) {
    // connections->deleteMe(thisLoca);
    // delete connections[i];
  }
  delete[] connections;
};

int Node::getNumConnections() {
  return connectionNum;
};

Node * Node::getConnectedNode(int index) {
  return connections[index]->getOtherEnd(this);
};

bool Node::getConnectedNode(Node * nodePtr) {
  for (int i = 0; i < connectionNum; i++) {
    if (connections[i]->getOtherEnd(this) == nodePtr)
      return true;
  }
  return false;
};

bool Node::addConnection(Node * newNode) {
  if (connectionNum < 4) {
    bool success = connections[connectionNum]->setEdge(newNode);
    newNode->addConnection(this, false);
    connectionNum++;
    return success;
  }
  return false;
};

bool Node::addConnection(Node * newNode, bool input) {
  if (connectionNum < 4) {
    bool success = connections[connectionNum]->setEdge(newNode);
    connectionNum++;
    return success;
  }
  return false;
};

void Node::printNode(std::ostream& stream) {
  // Redundant If searched statements ahhhhhh
  if (!searched) {
    searched = true;
    stream << *this;
    for (int i = 0; i < 4; i++) {
      if (connections[i]->getConnected()) {
        Node * temp = connections[i]->getOtherEnd(this);
        if (!temp->searched) {
          stream << "\n";
          temp->printNode(stream);
        }
      }
    }
  }
};
