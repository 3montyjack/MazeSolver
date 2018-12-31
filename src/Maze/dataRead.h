#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <fstream>
#include <dirent.h>
#include ".\\..\\2WayGraph\\graph.h"

using namespace std;

class DataRead {
private:
  string f_location;
  bool solvable;
public:
  DataRead(string fileLocation);

  Graph * makeMap(string FileName);
  Graph * makeNodes(vector<vector<char> > * maze);
  bool findNode(Graph * g, vector<vector<char> > * maze, int newX, int newY, int oldX, int oldY,
    int distance);
  bool initialNode(Graph * g, vector<vector<char> > * maze, int oldX, int oldY);
  void printMaze(vector<vector<char> > * maze);
  void printMaze(vector<vector<char> > * maze, int oldX, int oldY, int x, int y, int x2, int y2);
};
#endif // ifndef DATA_H
