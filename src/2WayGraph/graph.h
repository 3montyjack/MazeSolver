#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
#include "node.h"
#include "edge.h"
#include "headlessEdges.h"

class Graph {

private:
Node * start;

Node * findNode(int x, int y, Node * temp)
{
  Node * finalValue = 0;
  int tX = temp->x;
  int tY = temp->y;

  cout << "Here: " << temp << endl;
  if (x == tX)
  {
    if (y == tY)
    {
      cout << "Returning actual value: " << tX << "," << tY << " " << temp << endl;
      return finalValue;
    }
  }
  temp->searched = true;
  for (int i = 0; i < temp->getNumConnections(); i++)
  {
    if (!temp->getConnectedNode(i)->searched)
    {
      cout << "Connected Node Ptr: " << temp->getConnectedNode(i) << endl;
      //Bug here
      Node * temp2 = findNode(x, y, temp->getConnectedNode(i));
      if (temp2 != 0)
      {
        cout << "Returning actual value: " << tX << "," << tY << " " << temp << endl;
        return finalValue;
      }
    }
  }
  cout << "Final Value: " << finalValue << endl;
  return finalValue;
}

resetFlags(Node* resetVal) {
  cout << "Resetting: " << resetVal->x << "," << resetVal->y << endl;
  resetVal->searched = false;
  for (int i = 0; i < resetVal->getNumConnections(); i++) {
    Node* temp = resetVal->getConnectedNode(i);
    if (temp != 0 && temp->searched) {
      resetFlags(temp);
    }
  }
}

public:

Graph(int x, int y)
{

    start = new Node(x, y);
    cout << "Location Main: " << start << endl;
    start->setLocation(start);

}

bool findNode(int x, int y) {
  bool temp = findNode(x, y, start) != 0;
  resetFlags(start);
  return temp;
}
// TODO need connections to be added as well
bool addNode(HeadlessEdges * edges)
{
  bool flag = false;
    Node * temp = findNode(edges->x, edges->y, start); // 0
    if (temp != 0)
    {
      cout << "Found Value: " << temp << endl;
        flag = true;
        for (int i = 0; i < 4; i++)
        {
            Node * duplicate = edges->getEdge(i);
            cout << duplicate << endl;
            if (duplicate != 0)
            {
                Node * foundEdge = findNode(duplicate->x, duplicate->y, start);
                if (foundEdge != 0)
                {
                    cout << foundEdge << endl;
                    edges->replaceEdge(i, foundEdge);
                }
            }
        }
        temp->addEdges(edges->getEdges());
    }
    else
    {
      cout << "Hitting Here: " << temp << endl;
      Node* newHead = new Node(edges->x, edges->y);
        for (int i = 0; i < 4; i++)
        {
            Node * edge = edges->getEdge(i);
            cout << "Edge: " << i << " " << edge << endl;
            if (edge != 0)
            {
              //TODO Logic is better but not done here
              newHead->addConnection(edge);
              Node* temp2 = findNode(edge->x, edge->y, start);
              if (temp2 != 0) {
                flag = true;
                cout << "Here 201: " << temp2 << endl;
                temp2->addConnection(newHead);
              }

            }
            // cout << "Adding A node: " << temp << " " << start << endl;
            // cout << "Added To: " << "Temp replace later" << endl;
        }
    }

    // Node* temp = new Node(x,y);
    return flag;
}

};
#endif
