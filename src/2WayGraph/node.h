#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "edge.h"

class Node {
private:
  bool end;
  Edge * connections[4];
  int connectionNum;
  void init(int x, int y, bool endT);

public:
  int x;
  int y;
  bool searched;

  Node();
  Node(int x, int y);
  Node(int x, int y, bool end);

  ~Node();

  int getNumConnections();

  Node * getConnectedNode(int index);

  bool getConnectedNode(Node * nodePtr);

  bool addConnection(Node * newNode, int wight);

  bool addConnection(Edge * edge, int weight);

  void printNode(std::ostream& stream);

  friend std::ostream& operator << (std::ostream& stream, Node * node) {
    // return stream << &node;
    bool first = true;

    if (node != 0) {
      stream << node->x << "," << node->y << " : ";
      for (int i = 0; i < 4; i++) {
        if (node->connections[i]->getConnected()) {
          Node * temp = node->connections[i]->getOtherEnd(node);
          if (!first) {
            stream << " | " << temp->x << "," << temp->y << ":" << node->connections[i]->getWeight() << ":"
                   << node->end;
          } else {
            stream << temp->x << "," << temp->y << ":" << node->connections[i]->getWeight() << ":" << node->end;
            first = false;
          }
        }
      }
    } else {
      stream << "Not a valid node";
    }
    return stream;
  }
};
#endif // ifndef NODE_H
