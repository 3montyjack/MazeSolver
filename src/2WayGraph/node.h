#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "edge.h"

class Node {
private:
bool end;
Edge * connections[4];
int connectionNum;

public:
int x;
int y;
bool searched;

Node();
Node(int x, int y);

~Node();

int getNumConnections()
{
    return connectionNum;
}
Node * getConnectedNode(int index)
{
    return connections[index]->getOtherEnd(this);
}
bool getConnectedNode(Node * nodePtr)
{
  for (int i = 0; i < connectionNum; i++) {
    if (connections[i]->getOtherEnd(this) == nodePtr)
      return true;
  }
  return false;
}
bool addConnection(Node * newNode)
{
    if (connectionNum < 4)
    {
        bool success = connections[connectionNum]->setEdge(newNode);
        newNode->addConnection(this, false);
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

void printNode(std::ostream& stream)
{
    if (!searched)
    {
        searched = true;
        stream << *this << "\n";
        for (int i = 0; i < 4; i++)
        {
            if (connections[i]->getConnected())
            {
                Node * temp = connections[i]->getOtherEnd(this);
                temp->printNode(stream);
            }
        }
    }
}

friend std::ostream& operator<<(std::ostream& stream, Node& node)
{
  // return stream << &node;
    bool first = true;
    stream << node.x << "," << node.y << " : ";
    for (int i = 0; i < 4; i++)
    {
        if (node.connections[i]->getConnected())
        {
            Node * temp = node.connections[i]->getOtherEnd(&node);
            if (!first)
            {
                stream << " | " << temp->x << "," << temp->y;
            }
            else
            {
                stream << " " << temp->x << "," << temp->y;
                first = false;
            }
        }
    }
    return stream;
}

};
#endif
