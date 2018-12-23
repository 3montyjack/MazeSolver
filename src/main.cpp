#include <iostream>
#include <string>
#include "2WayGraph/maze.h"
#include "2WayGraph/graph.h"
#include "getData.h"
#define NUM_CONNECTIONS = 4;

using namespace std;

int main()
{
    Maze * m = new Maze("Hello");
    Graph * g = new Graph(1, 2);

    cout << m->makeMap() << endl;
    Graph * edges = new Graph(2, 1);
    edges->addNode(2, 1, 3, 1);

    cout << "Adding nodes Graph 2: " << g->connectGraphs(1, 2, edges, 2, 1) << endl;
    cout << "Connected Graph: " << *g << endl;
    cout << "Finding Node (2,1): " << g->findNode(2, 1) << endl;

    return 0;
}
