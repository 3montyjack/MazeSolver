g++ -c -o ./build/maze.o .\src\maze.cpp
g++ -c -o ./build/map.o .\src\2WayGraph\graph.cpp
g++ -c -o ./build/edge.o .\src\2WayGraph\edge.cpp
g++ -c -o ./build/headlessEdges.o .\src\2WayGraph\headlessEdges.cpp
g++ -c -o ./build/node.o .\src\2WayGraph\node.cpp
g++ -c -o ./build/main.o .\src\main.cpp

g++ -o MazeSolver.exe .\build\main.o .\build\maze.o .\build\map.o .\build\edge.o .\build\headlessEdges.o .\build\node.o
