#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include "node.h"
#include "edge.h"

class Graph {
private:

  bool only1Node;
  bool solvable;

  Node * start;
  Node * findNode(int x, int y, Node * temp);

  void resetFlags(Node * resetVal);

public:

  Graph(int x, int y);
  Graph();

  void removeStart();
  void setSolvable();

  Node * findNode(int x, int y);

  bool onlyOneNode();

  // Take 2 graphs, get the node coordinances of each of the connections that needs to be made
  // Also take the ptr to the graph that you would like to connect to the current graph
  bool connectGraphs(int thisX, int thisY, Graph * graphToConnect, int newX, int newY, int weight);

  bool addNode(int newX, int newY);

  bool addNode(int oldX, int oldY, int newX, int newY, int weight);
  bool addNode(int oldX, int oldY, int newX, int newY, int weight, bool end);


  bool addConnection(int oldX, int oldY, int newX, int newY, int weight);

  friend std::ostream&operator << (std::ostream& stream, Graph& graph) {
    if (&graph == 0) {
      return stream << "Invalid Object";
    }
    if (graph.start == 0) {
      return stream << "Empty";
    }
    graph.start->printNode(stream);
    graph.resetFlags(graph.start);
    if (graph.solvable) {
      stream << endl << "Is Solvable";
    } else {
      stream << endl << "Is Not Solvable";
    }
    return stream;
  }
};


#endif // ifndef MAP_H
