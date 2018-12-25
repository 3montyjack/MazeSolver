#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include "node.h"
#include "edge.h"

class Graph {
private:

  Node * start;
  Node * findNode(int x, int y, Node * temp);

  resetFlags(Node * resetVal);

public:

  Graph(int x, int y);

  removeStart();

  Node * findNode(int x, int y);

  // Take 2 graphs, get the node coordinances of each of the connections that needs to be made
  // Also take the ptr to the graph that you would like to connect to the current graph
  bool connectGraphs(int thisX, int thisY, Graph * graphToConnect, int newX, int newY);

  bool addNode(int oldX, int oldY, int newX, int newY);

  bool addConnection(int oldX, int oldY, int newX, int newY);

  friend std::ostream&operator << (std::ostream& stream, Graph& graph){
    graph.start->printNode(stream);
    graph.resetFlags(graph.start);
    return stream;
  }
};


#endif // ifndef MAP_H
