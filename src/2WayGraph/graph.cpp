#include "graph.h"

Graph::Graph(int x, int y) {
  start		= new Node(x, y);
  only1Node = true;
  solvable	= false;
  // cout << "Location Main: " << start << endl;
};

Graph::Graph() {
  start		= 0;
  only1Node = true;
  solvable	= false;
  // start = new Node(x, y);
  // cout << "Location Main: " << start << endl;
};

void Graph::removeStart() {
  start = 0;
};

bool Graph::onlyOneNode() {
  return only1Node;
};

void Graph::setSolvable() {
  solvable = true;
}

bool Graph::connectGraphs(int thisX, int thisY, Graph * graphToConnect, int newX, int newY, int weight) {
  bool flag = false;
  Node * foundMatching = findNode(thisX, thisY);
  Node * newGraphAddr  = graphToConnect->findNode(newX, newY);

  // cout << "Found coord: " << newGraphAddr << endl;
  if (newGraphAddr != 0 && foundMatching != 0) {
    flag = foundMatching->addConnection(newGraphAddr, weight);
    // cout << "Flag Status: " << flag << endl;
    if (graphToConnect->getSolvable()) {
      setSolvable();
    }
    graphToConnect->removeStart();
    delete graphToConnect;
  }

  return flag;
};

Node * Graph::findNode(int x, int y) {
  Node * temp = findNode(x, y, start);

  resetFlags(start);
  return temp;
};

Node * Graph::findNode(int x, int y, Node * temp) {
  int tX = temp->x;
  int tY = temp->y;

  // cout << "Here: " << temp << endl;
  if (x == tX) {
    if (y == tY) {
      // cout << "Returning actual value 1: " << tX << "," << tY << " " << temp << endl;
      return temp;
    }
  }
  temp->searched = true;
  for (int i = 0; i < temp->getNumConnections(); i++) {
    // std::cout << temp << std::endl;
    if (!temp->getConnectedNode(i)->searched) {
      // cout << "Connected Node Ptr: " << temp->getConnectedNode(i) << endl;
      // Bug here
      Node * temp2 = findNode(x, y, temp->getConnectedNode(i));
      if (temp2 != 0) {
        // cout << "Found and returning: " << tX << "," << tY << " " << temp2 << endl;
        return temp2;
      }
    }
  }
  // cout << "Did Not find " << endl;
  return 0;
};

bool Graph::addNode(int newX, int newY) {
  if (start == 0) {
    start = new Node(newX, newY);
    return true;
  }
  return false;
};

bool Graph::addNode(int oldX, int oldY, int newX, int newY, int weight) {
  return addNode(oldX, oldY, newX, newY, weight, false);
};

bool Graph::addNode(int oldX, int oldY, int newX, int newY, int weight, bool end) {
  if ((oldX == newX) && (oldY == newY)) {
    cout << "Same Node: " << oldX << " " << oldY << endl;
    // Make this false if removing the comment for debugging
    return true;
  }
  Node * foundOldNode = findNode(oldX, oldY);
  if (foundOldNode != 0) {
    bool addedConnection = foundOldNode->addConnection(new Node(newX, newY, end), weight);
    if (addedConnection && end) {
      setSolvable();
    }
    // cout << newX << "," << newY << " " << foundOldNode << " " << addedConnection << endl;
    return addedConnection;
  }
  // cout << "Couldnt add: " << oldX << "," << oldY << " " << newX << "," << newY << endl;
  return false;
};

bool Graph::addConnection(int oldX, int oldY, int newX, int newY, int weight) {
  if (!(oldX == newX && oldY == newY)) {
    Node * foundOldNode	   = findNode(oldX, oldY);
    Node * foundSecondNode = findNode(newX, newY);

    if (foundOldNode != 0 && foundSecondNode != 0) {
      if (foundOldNode->getConnectedNode(foundSecondNode)) {
        cout << "Edge allready Exists: " << oldX << "," << oldY << " " << newX << "," << newY << endl;
        // Make this return false if needed for making this fail
        return true;
      }
      return foundOldNode->addConnection(foundSecondNode, weight);
    } else {
      cout << "One of the nodes doesnt exist" << endl;
    }
    cout << "Neither of the nodes found" << endl;
  }
  cout << "Same Node" << endl;
  return false;
};

void Graph::resetFlags(Node * resetVal) {
  // cout << "Resetting: " << resetVal->x << "," << resetVal->y << endl;
  resetVal->searched = false;
  // std::cout << "Here 808";
  for (int i = 0; i < resetVal->getNumConnections(); i++) {
    Node * temp = resetVal->getConnectedNode(i);
    if (temp != 0 && temp->searched) {
      // std::cout << "Helllllooooo";
      resetFlags(temp);
    }
  }
};
