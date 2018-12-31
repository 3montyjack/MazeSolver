#include "node.h"

Node::Node(int x, int y) {
  init(x, y, false);
};

Node::Node(int x, int y, bool endT) {
  init(x, y, endT);
};

Node::Node() {
  init(-1, -1, false);
};

void Node::init(int x, int y, bool endT) {
  end			= endT;
  searched		= false;
  connectionNum = 0;
  this->x		= x;
  this->y		= y;
  for (int i = 0; i < 4; i++) {
    connections[i] = new Edge(this);
  }
}

Node::~Node() {
  for (int i = 0; i < 4; i++) {
    // connections->deleteMe(thisLoca);
    // delete connections[i];
  }
  // delete[] connections;
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

bool Node::addConnection(Node * newNode, int weight) {
  if (newNode != this) {
    if ((connectionNum < 4) && (newNode->getNumConnections() < 4)) {
      if (connections[connectionNum]->setEdge(newNode, weight)) {
        Edge * edge = connections[connectionNum];
        newNode->addConnection(edge, weight);
        connectionNum++;
        return true;
      }
    } else {
      cout << "One or both of the nodes are too full" << endl;
    }
  } else {
    cout << "Tried to connect the same nodes together" << endl;
  }
  return false;
};

bool Node::addConnection(Edge * edge, int weight) {
  if (connectionNum < 4) {
    delete connections[connectionNum];
    connections[connectionNum] = edge;
    connectionNum++;
    return true;
  }
  cout << "There is no way that you can hit here, dont even try" << endl;
  return false;
};

void Node::printNode(std::ostream& stream) {
  // Redundant If searched statements ahhhhhh
  if (!searched) {
    searched = true;
    stream << this;
    for (int i = 0; i < 4; i++) {
      // std::cout << *this;
      if (connections[i]->getConnected()) {
        Node * temp = connections[i]->getOtherEnd(this);
        if (!temp->searched) {
          stream << "\n";
          temp->printNode(stream);
        }
      } else {
        break;
      }
    }
  }
};
