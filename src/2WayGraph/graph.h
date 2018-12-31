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

  // This starts at the node in the argument, looks at all of the connections,
  // and recursively calles itself lookinf for nodes that are not marked to be
  // searched allready, then marks the node that is being called on as searched,
  // and recursively calls on all of the connected nodes not allready marked.
  Node * findNode(int x, int y, Node * temp);

  // This goes through the graph and finds all the nodes marked as searched and
  // unmarks them, this is really inefficent and need to think about how to make this more streamilned.
  void resetFlags(Node * resetVal);

  // This is called only when there is an end added to the graph,
  void setSolvable();

public:
  // These are the consturctors, they deal with instanciating a node if there is
  // a xy put into the arguments, if not then no node is made for the start of the graph.
  Graph(int x, int y);
  Graph();

  // Remove start removes the head of the graph, this will lead to a memory leak
  // if called and there are no other refrences to the graph
  void removeStart();

  // The public method of finding nodes, leaves out the node to start at, can if need to expose the other method so that you can start the search from anywhrere. This is to simplify the implementation for users, read description of the other find node for what it does.
  Node * findNode(int x, int y);

  // This one is pretty obv tbh
  bool getSolvable() { return solvable; };

  // And this one as well
  bool onlyOneNode();

  // Take 2 graphs, get the node coordinances of each of the connections that needs to be made
  // Also take the ptr to the graph that you would like to connect to the current graph
  // Deletes the graph object that is fed to it and if the graph is solvable
  // then it makes this solvable
  bool connectGraphs(int thisX, int thisY, Graph * graphToConnect, int newX, int newY, int weight);


  // These are all similar, first one only adds a node to the start, this can
  // only happen if there is not a node allready being pointed to at the start.
  bool addNode(int newX, int newY);

  // This finds a node address, and then tries to add a node to the next xy that
  // is specified by creating another node and then pointing the connections to
  // the newly created node TODO possible memory leak with this method
  // Returns true if the node was successifly added and false if it could not be
  // added
  bool addNode(int oldX, int oldY, int newX, int newY, int weight, bool end);
  bool addNode(int oldX, int oldY, int newX, int newY, int weight);

  // Add connection by searching for both of the nodes and then connecting them
  // together. This is currently done super inefficently by searching 2 seperate
  // times for these objects, but will fix TODO Make searching way more efficent
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
