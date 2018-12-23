#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "edge.h"

class Node {
private:
bool end;
Node * thisLoca;
Edge * connections[4];
int connectionNum;

public:
int x;
int y;
bool searched;

Node();
Node(int x, int y);

~Node();

bool setLocation(Node * value)
{
    thisLoca = value;
    for (int i = 0; i < 4; i++)
    {
        bool flag = connections[i]->setEdge(thisLoca);
        if (!flag) {
           return false;
        }
    }
    return true;
}
int getNumConnections()
{
    return connectionNum;
}
Node * getConnectedNode(int index)
{
    return connections[index]->getOtherEnd(thisLoca);
}
bool addConnection(Node * newNode)
{
    if (connectionNum < 4)
    {
        bool success = connections[connectionNum]->setEdge(newNode);
        newNode->addConnection(thisLoca, false);
        connectionNum++;
        return success;
    }
    return false;
}
bool addConnection(Node * newNode, bool input)
{
    if (connectionNum < 4)
    {
        bool success = connections[connectionNum]->setEdge(newNode);
        connectionNum++;
        return success;
    }
    return false;
}
// This has to be completelty fucked
bool addEdges(Node ** edges)
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Connection: " << edges[i] << endl;
        if (edges[i] != 0)
        {
            addConnection(edges[i]);
        }
    }
}


};
#endif
