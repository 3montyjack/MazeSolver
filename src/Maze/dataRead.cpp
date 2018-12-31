#include "dataRead.h"


DataRead::DataRead(std::string fileLocation) {
  solvable = false;
  DataRead::f_location = fileLocation;
}

Graph * DataRead::makeMap(std::string FileName) {
  ifstream myFile;

  myFile.open((f_location + "\\" + FileName).c_str());

  string str = "-1";
  bool flag	 = true;

  vector<vector<char> > * maze(0);

  std::cout << FileName << std::endl;
  while (getline(myFile, str)) {
    if (flag) {
      maze = new vector<vector<char> >(1, vector<char>(str.size() + 2, '0'));
      flag = false;
    }
    char * fileLine = (char *) ("0" + str + "0").c_str();
    vector<char> temp(fileLine, fileLine + str.size() + 2);
    maze->push_back(temp);
  }
  myFile.close();
  maze->push_back(vector<char>((*maze)[0].size(), '0'));
  // printMaze(maze);
  return makeNodes(maze);
} // DataRead::makeMap

Graph * DataRead::makeNodes(vector<vector<char> > * maze) {
  int start[2] = { 1, 1 };

  if (maze != 0) {
    int end[2];
    int needToFind = 2;
    int found	   = 0;

    for (int i = 0; i < maze->size(); i++) {
      for (int j = 0; j < (*maze)[i].size(); j++) {
        char temp = (*maze)[i][j];
        if (temp == 'E') {
          end[0] = i;
          end[1] = j;
          found++;
          if (needToFind == found) {
            goto exitLoops;
          }
        } else if (temp == 'S') {
          start[0] = i;
          start[1] = j;
          found++;
          if (needToFind == found) {
            goto exitLoops;
          }
        }
      }
    }
  }
exitLoops:
  Graph * g = new Graph();
  g->addNode(start[0], start[1]);
  initialNode(g, maze, start[0], start[1]);
  return g;
} // DataRead::makeNodes

bool DataRead::findNode(Graph * g, vector<vector<char> > * maze, int newX, int newY, int oldX, int oldY,
  int distance) {
  // 0 north, 1 east, 2 south, 3 west

  int ammount = 0;
  vector<int> temp;

  // If the node where we are currently at is a node allready do nothing
  if ((*maze)[newX][newY] != 'N') {
    if ((*maze)[newX][newY + 1] == '1' || (*maze)[newX][newY + 1] == 'E') {
      temp.push_back(0);
    }
    if ((*maze)[newX + 1][newY] == '1' || (*maze)[newX + 1][newY] == 'E') {
      temp.push_back(1);
    }
    if ((*maze)[newX][newY - 1] == '1' || (*maze)[newX][newY - 1] == 'E') {
      temp.push_back(2);
    }
    if ((*maze)[newX - 1][newY] == '1' || (*maze)[newX - 1][newY] == 'E') {
      temp.push_back(3);
    }
    if ((*maze)[newX][newY + 1] == 'N' || (*maze)[newX][newY + 1] == 'S') {
      temp.push_back(4);
    }
    if ((*maze)[newX + 1][newY] == 'N' || (*maze)[newX + 1][newY] == 'S') {
      temp.push_back(5);
    }
    if ((*maze)[newX][newY - 1] == 'N' || (*maze)[newX][newY - 1] == 'S') {
      temp.push_back(6);
    }
    if ((*maze)[newX - 1][newY] == 'N' || (*maze)[newX - 1][newY] == 'S') {
      temp.push_back(7);
    }
    if ((*maze)[newX][newY + 1] == '2') {
      temp.push_back(-1);
    }
    if ((*maze)[newX + 1][newY] == '2') {
      temp.push_back(-1);
    }
    if ((*maze)[newX][newY - 1] == '2') {
      temp.push_back(-1);
    }
    if ((*maze)[newX - 1][newY] == '2') {
      temp.push_back(-1);
    }
  }

  if (temp.size() > 2) {
    if (distance != 0) {
      // cout << newX << " " << newY << endl;
      g->addNode(oldX, oldY, newX, newY, distance);
    }
    (*maze)[newX][newY] = 'N';
  } else if (temp.size() > 1) {
    (*maze)[newX][newY] = '2';
  } else {
    bool end = (*maze)[newX][newY] == 'E';
    g->addNode(oldX, oldY, newX, newY, distance, (*maze)[newX][newY] == 'E');
    if (end && !solvable) {
      solvable = true;
    }
  }

  // cout << *g << endl;

  while (temp.size() > 0) {
    int t = temp.back();
    temp.pop_back();

    int tempX = oldX;
    int tempY = oldY;
    int tempD = distance;

    if ((*maze)[newX][newY] == 'N') {
      tempD = 0;
      tempY = newY;
      tempX = newX;
    }
    switch (t) {
        case 0:
          findNode(g, maze, newX, newY + 1, tempX, tempY, tempD + 1);
          break;
        case 1:
          findNode(g, maze, newX + 1, newY, tempX, tempY, tempD + 1);
          break;
        case 2:
          findNode(g, maze, newX, newY - 1, tempX, tempY, tempD + 1);
          break;
        case 3:
          findNode(g, maze, newX - 1, newY, tempX, tempY, tempD + 1);
          break;
        case 4:
          if ((*maze)[newX][newY] == 'N') {
            bool errorConnecting = g->addConnection(newX, newY, newX, newY + 1, 1);
            if (!errorConnecting) {
              cout << "Error N" << endl;
              printMaze(maze, newX, newY, newX, newY, newX, newY + 1);
              cout << *g << endl;
            }
          } else if (!(oldX == newX && oldY == newY + 1)) {
            bool errorConnecting = g->addConnection(oldX, oldY, newX, newY + 1, distance + 1);
            if (!errorConnecting) {
              cout << "Error N" << endl;
              printMaze(maze, oldX, oldY, newX, newY, newX, newY + 1);
              cout << *g << endl;
            }
          }
          break;
        case 5:
          if ((*maze)[newX][newY] == 'N') {
            bool errorConnecting = g->addConnection(newX, newY, newX + 1, newY, distance + 1);
            if (!errorConnecting) {
              cout << "Error E" << endl;
              printMaze(maze, newX, newY, newX, newY, newX + 1, newY);
              cout << *g << endl;
            }
          } else if (!(oldX == newX + 1 && oldY == newY)) {
            bool errorConnecting = g->addConnection(oldX, oldY, newX + 1, newY, distance + 1);
            if (!errorConnecting) {
              cout << "Error E" << endl;
              printMaze(maze, oldX, oldY, newX, newY, newX + 1, newY);
              cout << *g << endl;
            }
          }
          break;
        case 6:
          if ((*maze)[newX][newY] == 'N') {
            bool errorConnecting = g->addConnection(newX, newY, newX, newY - 1, distance + 1);
            if (!errorConnecting) {
              cout << "Error S" << endl;
              printMaze(maze, newX, newY, newX, newY, newX, newY - 1);
              cout << *g << endl;
            }
          } else if (!(oldX == newX && oldY == newY - 1)) {
            bool errorConnecting = g->addConnection(oldX, oldY, newX, newY - 1, distance + 1);
            if (!errorConnecting) {
              cout << "Error S" << endl;
              printMaze(maze, oldX, oldY, newX, newY, newX, newY - 1);
              cout << *g << endl;
            }
          }
          break;
        case 7:
          if ((*maze)[newX][newY] == 'N') {
            bool errorConnecting = g->addConnection(newX, newY, newX - 1, newY, distance + 1);
            if (!errorConnecting) {
              cout << "Error W" << endl;
              printMaze(maze, newX, newY, newX, newY, newX - 1, newY);
              cout << *g << endl;
            }
          } else if (!(oldX == newX - 1 && oldY == newY)) {
            bool errorConnecting = g->addConnection(oldX, oldY, newX - 1, newY, distance + 1);
            if (!errorConnecting) {
              cout << "Error W" << endl;
              printMaze(maze, oldX, oldY, newX, newY, newX - 1, newY);
              cout << *g << endl;
            }
          }
          break;
        default:
          break;
    }
  }

  return true;
}; // DataRead::foundNode

bool DataRead::initialNode(Graph * g, vector<vector<char> > * maze, int oldX, int oldY) {
  g->addNode(oldX, oldY);
  // cout << "Here: " << *g << endl;
  findNode(g, maze, oldX, oldY, oldX, oldY, 0);

  printMaze(maze);

  return true;
};
void DataRead::printMaze(vector<vector<char> > * maze) {
  if (maze != 0) {
    for (vector<vector<char> >::const_iterator i = maze->begin(); i != maze->end(); ++i) {
      for (vector<char>::const_iterator j = i->begin(); j != i->end(); ++j) {
        cout << *j << ' ';
      }
      cout << endl;
    }
  }
}

void DataRead::printMaze(vector<vector<char> > * maze, int oldX, int oldY, int x, int y, int x2, int y2) {
  cout << " OX: " << oldX << " OY: " << oldY << " NX: " << x << " NY: " << y << " AX: " << x2
       << " AY: " << y2 << endl;
  if (maze != 0) {
    int i1 = 0;
    for (vector<vector<char> >::const_iterator i = maze->begin(); i != maze->end(); ++i) {
      int j1 = 0;
      for (vector<char>::const_iterator j = i->begin(); j != i->end(); ++j) {
        if ((oldX == i1 && oldY == j1)) {
          cout << "\x1b[32m" + string(1, *j) + "\x1b[0m" << ' ';
        } else if ((x == i1 && y == j1) || (x2 == i1 && y2 == j1)) {
          // Wanted cool colors for what we are looking at but nah
          cout << "\x1b[31m" + string(1, *j) + "\x1b[0m" << ' ';
          // cout << *j << 'X' << ' ';
        } else {
          cout << *j << ' ';
        }
        j1++;
      }
      i1++;
      cout << endl;
    }
  }
}
