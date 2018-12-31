#ifndef EDGE_H
#define EDGE_H

#include <iostream>

class Node;

class Edge {
  int weight;
  bool inited;
  bool holding;
  Node * connections[2];
public:
  Edge(Node * FirstConnection);

  ~Edge();
  // TODO Finish this method, would allow for deconstruction of the graph
  void deleteMe(Node * Caller);

  // This one is a doozie, first call sets the initial edge, then the second
  // call sets the connecting node. Any other calls after this results in a fail
  // and a false is returned the weight argument is only used when the second
  // call to the method is done.
  bool setEdge(Node * &location, int weight);

  // This takes in a node pointer and returns the other node pointer the edge
  // is connected to. If there is not one or the node that is passed in isnt in
  // the edge then false is returned, the weight argument is not
  Node * getOtherEnd(Node * oneSide);

  // This method checks to see if the edge is full with a node on either side.
  // Returns false if not
  bool getValidEdge();

  // This is the stored weight for the edge connection
  int getWeight() { return weight; }

  // This returns true of the edge is connected to 2 diffrent nodes, if not then
  // it returns false
  bool getConnected();

  friend std::ostream&operator << (std::ostream& stream, Edge& edge) {
    if (edge.connections[0] != 0) {
      if (edge.connections[1] == 0) {
        stream << "1 Connection";
      } else {
        stream << "2 Connections, Weight: " << edge.weight;
      }
    } else {
      stream << "Edge is empty";
    }
    return stream;
  }
};


#endif // ifndef EDGE_H
