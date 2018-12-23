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
Edge(Node* FirstConnection)
{
    holding = false;
    connections[0] = FirstConnection;
    connections[1] = 0;
}
~Edge()
{
  // delete Edge;
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
  bool flag = false;
    if (!inited)
    {
        connections[0] = location;
        inited = true;
        flag = true;
    }
    else if (!holding)
    {
        cout << "Setting EdgeConnection: " << location << " " << connections[0] << endl;
        connections[1] = location;
        holding = true;
        flag =  true;
    }
    return flag;
}
Node * getOtherEnd(Node * oneSide)
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
bool getConnected()
{
  return holding;
}
};


#endif
