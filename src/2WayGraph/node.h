#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "edge.h"

class Node {
private:
  bool end;
  Edge * connections[4];
  int connectionNum;

  // Takes in the x y and end and instanciates each node.
  void init(int x, int y, bool endT);

public:
  int x;
  int y;
  bool searched;

  // The assorted constructiors for the nodes, they all call the init function
  // and either set the xy of the node to not matter, to the second one where it
  // sets xy of the node, and the last one allow for the end flag to be set upon
  // creation of the object.
  Node();
  Node(int x, int y);
  Node(int x, int y, bool end);

  ~Node();
  // Returns the number of connections inside of the Node, usefull for
  // itteration of the connections.
  int getNumConnections();

  // This allows for the pointer of the connected node that is at the index in
  // the array to be returned, returns 0 if there is any kind of error
  Node * getConnectedNode(int index);

  // This checks all of the connected nodes to see if there is another node
  // connected that has the same address of the node specified in the argument.
  bool getConnectedNode(Node * nodePtr);

  // This checks to see if there is space in the connection array to add another
  // node, then checks the node that would be connected to to see if there is
  // space as well, if there is then it tries to connect them, if there is a
  // problem with any of these steps, it stops and leaves the nodes alone and
  // returns false. If not it increments the connectionNum as well.
  bool addConnection(Node * newNode, int wight);

  // This is for the other method above to work, it adds the edge that is on the
  // node that is calling this and over rides the node address on this node and
  // then deletes the edge that is replaced. Returns false if the edge on this
  // node allready has a connection
  bool addConnection(Edge * edge, int weight);

  // This is for the over riding of the operator of graph, to have a more
  // consistant output when printing the graph to make it look cool af
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
