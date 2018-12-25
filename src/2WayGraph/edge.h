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

  void deleteMe(Node * Caller);

  setEdge(Node * &location);

  Node * getOtherEnd(Node * oneSide);

  bool getValidEdge();

  bool getConnected();

  friend std::ostream&operator << (std::ostream& stream, Edge& edge){
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
