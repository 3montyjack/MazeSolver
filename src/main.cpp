#include <iostream>
#include <string>
#include "maze.h"
#include "map.h"

using namespace std;

int main() {
  Maze* m = new Maze("Hello");
  Graph* g = new Graph(1,2);
  cout << m->makeMap() << endl;
  vector<int>* tempConnections = new vector<int>(0);

  tempConnections->push_back(1);
  tempConnections->push_back(2);
  tempConnections->push_back(0);
  tempConnections->push_back(1);

  HeadlessEdges* edges = new HeadlessEdges(2,1,tempConnections);
  cout << "Here 101: " << endl;
  cout << "Adding nodes (1,2), (0,1): " << g->addNode(edges) << endl;
  cout << "Finding Node (0,1): " << g->findNode(0,1) << endl;

  return 0;
}
