#include "getData.h"
#include <string>


Maze::Maze(std::string fileLocation) {
  Maze::f_location = fileLocation;
}
std::string Maze::makeMap()
{
  return f_location;
}
