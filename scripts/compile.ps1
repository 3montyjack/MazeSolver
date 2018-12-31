Set-Location ..
g++ -c -o ./build/cpp/maze.o .\src\Maze\maze.cpp
g++ -c -o ./build/cpp/graph.o .\src\2WayGraph\graph.cpp
g++ -c -o ./build/cpp/edge.o .\src\2WayGraph\edge.cpp
g++ -c -o ./build/cpp/node.o .\src\2WayGraph\node.cpp
g++ -c -o ./build/cpp/main.o .\src\main.cpp
g++ -c -o ./build/cpp/dataRead.o .\src\Maze\dataRead.cpp

# gdb ./build/cpp/main.o

g++ -o MazeSolver.exe .\build\cpp\main.o .\build\cpp\maze.o .\build\cpp\graph.o .\build\cpp\edge.o .\build\cpp\node.o .\build\cpp\dataRead.o 

# gdb MazeSolver.exe

Set-Location scripts
