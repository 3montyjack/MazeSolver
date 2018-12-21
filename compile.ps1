g++ -c -o ./build/main.o .\src\main.cpp
g++ -c -o ./build/maze.o .\src\maze.cpp
g++ -c -o ./build/map.o .\src\map.cpp
g++ -c -o ./build/edge.o .\src\edge.cpp
g++ -c -o ./build/headlessEdges.o .\src\headlessEdges.cpp
g++ -c -o ./build/node.o .\src\node.cpp

g++ -o MazeSolver.exe .\build\main.o .\build\maze.o .\build\map.o .\build\edge.o .\build\headlessEdges.o .\build\node.o
