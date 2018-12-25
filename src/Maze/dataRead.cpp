#include "dataRead.h"
#include <string>


DataRead::DataRead( std::string fileLocation )
{
    DataRead::f_location = fileLocation;
}

std::string DataRead::makeMap()
{
    return f_location;
}
