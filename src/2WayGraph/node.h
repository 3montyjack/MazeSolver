#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "edge.h"

class Node {
private:
  bool end;
  Edge * connections[4];
  int connectionNum;

public:
  int x;
  int y;
  bool searched;

  Node();
  Node(int x, int y);

  ~Node();

  int getNumConnections();

  Node * getConnectedNode(int index);

  bool getConnectedNode(Node * nodePtr);

  bool addConnection(Node * newNode);

  bool addConnection(Node * newNode, bool input);

  void printNode(std::ostream& stream);

  friend std::ostream& operator << (std::ostream& stream, Node& node){
    // return stream << &node;
    bool first = true;

    stream << node.x << "," << node.y << " : ";
    for (int i = 0; i < 4; i++) {
      if (node.connections[i]->getConnected()) {
        Node * temp = node.connections[i]->getOtherEnd(&node);
        if (!first) {
          stream << " | " << temp->x << "," << temp->y;
        } else {
          stream << " " << temp->x << "," << temp->y;
          first = false;
        }
      }
    }
    return stream;
  }
};
#endif // ifndef NODE_H
