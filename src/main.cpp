#include <iostream>
#include <string>
#include "2WayGraph/graph.h"
#include "Maze/maze.h"
#define NUM_CONNECTIONS = 4;

using namespace std;

int main() {
  Maze * m	= new Maze("Hello");
  Graph * g = new Graph(1, 0);

  g->addNode(1, 0, 1, 1);
  g->addNode(1, 1, 2, 1);
  cout << *g << endl;
  // cout << m->makeMap() << endl;
  Graph * edges = new Graph(2, 3);

  edges->addNode(2, 3, 4, 3);
  edges->addNode(4, 3, 4, 4);

  cout << *edges << endl;

  cout << "Adding nodes Graph 2: " << g->connectGraphs(2, 1, edges, 4, 3) << endl;
  cout << "Connected Graph: " << *g << endl;
  cout << "Finding Node: " << *(g->findNode(2, 1)) << endl;

  g->addConnection(1, 1, 2, 3);
  g->addConnection(2, 1, 2, 3);

  cout << *g << endl;

  return 0;
}
