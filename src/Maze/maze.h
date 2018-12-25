#ifndef MAZE_H
#define MAZE_H
#include <string>
#include "dataRead.h"

class Maze {
private:
        string f_location;
        DataRead* data;
public:
        Maze(std::string fileLocation) {
                data = new DataRead(fileLocation);
        }

        std::string makeMap() {
                return "0";
        }
};

#endif
