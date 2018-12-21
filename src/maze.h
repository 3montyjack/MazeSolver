#ifndef MAZE_H
#define MAZE_H
#include <string>

class Maze {
  private:
    string f_location;
  public:
    Maze(std::string fileLocation);

    string makeMap();
};
#endif
