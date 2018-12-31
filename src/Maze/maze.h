#ifndef MAZE_H
#define MAZE_H
#include <string>
#include "dataRead.h"
#include "./../2WayGraph/graph.h"

using namespace std;
// This still needs to be moves to the .cpp file
class Maze {
private:
  string f_location;
  DataRead * data;
  vector<Graph *> * h;
  Graph * g;
public:
  Maze(std::string fileLocation) {
    g = 0;
    h = new vector<Graph *>(0);
    DIR * pDIR;
    struct dirent * entry;


    if (pDIR = opendir(fileLocation.c_str()) ) {
      while (entry = readdir(pDIR)) {
        data = new DataRead(fileLocation);
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
          cout << "Parsing: " << entry->d_name << "\n";
          string temp = entry->d_name;
          h->push_back(makeMap(entry->d_name)); // Initialize the graph in here
          // delete data;
          cout << *h->back() << endl;
        }
      }
      closedir(pDIR);
    }

    // testMaze();
    cout << "Finished" << endl;
    // testMaze();
  }

  void testMaze() {
    // Graph * g = new Graph(1, 0);
    cout << *g << endl;
    g->addNode(10, 7, 1, 0, 1);
    g->addNode(1, 0, 1, 1, 1);
    g->addNode(1, 1, 2, 1, 1);
    cout << *g << endl;
    // cout << m->makeMap() << endl;
    Graph * edges = new Graph(2, 3);

    edges->addNode(2, 3, 4, 3, 1);
    edges->addNode(4, 3, 4, 4, 1);

    cout << *edges << endl;

    cout << "Adding nodes Graph 2: " << g->connectGraphs(2, 1, edges, 4, 3, 1) << endl;
    // Seg falt here (unsure if seg or not)
    cout << "Connected Graph: " << *g << endl;
    cout << "Finding Node: " << (g->findNode(2, 1)) << endl;

    g->addConnection(1, 1, 2, 3, 1);
    g->addConnection(2, 1, 2, 3, 1);

    cout << *g << endl;
  }

  Graph * makeMap(std::string name) {
    g = data->makeMap(name);

    return g;
  }
};

#endif // ifndef MAZE_H
