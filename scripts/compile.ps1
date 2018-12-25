cd ..
g++ -c -o ./build/maze.o .\src\Maze\maze.cpp
g++ -c -o ./build/map.o .\src\2WayGraph\graph.cpp
g++ -c -o ./build/edge.o .\src\2WayGraph\edge.cpp
g++ -c -o ./build/node.o .\src\2WayGraph\node.cpp
g++ -c -o ./build/main.o .\src\main.cpp
g++ -c -o ./build/dataRead.o .\src\Maze\dataRead.cpp

g++ -o MazeSolver.exe .\build\main.o .\build\maze.o .\build\map.o .\build\edge.o .\build\node.o .\build\dataRead.o
cd scripts
