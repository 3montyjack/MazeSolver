#ifndef EDGE_H
#define EDGE_H

#include <iostream>

class Node;

class Edge {
int weight;
bool inited;
bool holding;
Node * connections[2];
public:
Edge()
{
    inited = false;
    holding = false;
    connections[0] = 0;
    connections[1] = 0;
}
~Edge()
{

}
void deleteMe(Node * Caller)
{
    if (connections[0] == Caller)
    {
        // delete connections[1];
    }
}

setEdge(Node * &location)
{
    if (!inited)
    {
        connections[0] = location;
        inited = true;
        return true;
    }
    else if (!holding)
    {
        cout << "Setting EdgeConnection: " << location << " " << connections[0] << endl;
        connections[1] = location;
        holding = true;
        return true;
    }
    else
    {
        return false;
    }
}
Node * getOtherEnd(Node *& oneSide)
{
    if (connections[0] == oneSide)
    {
        return connections[1];
    }
    else if (connections[1] == oneSide)
    {
        return connections[0];
    }
    return (Node *) -1;
}

bool getValidEdge()
{
    return inited;
}
};
#endif
