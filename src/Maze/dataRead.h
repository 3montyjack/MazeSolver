#ifndef DATA_H
#define DATA_H
#include <string>

// using namespace cv;

class DataRead {
private:
    string f_location;
public:
    DataRead(std::string fileLocation);

    std::string
    makeMap();
    bool
    readFile()
    { }
};
#endif // ifndef DATA_H
