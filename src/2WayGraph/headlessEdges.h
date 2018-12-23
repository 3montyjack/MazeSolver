#ifndef HEADLESSEDGE_H
#define HEADLESSEDGE_H
#include <vector>
#include "node.h"

class HeadlessEdges {

private:
Node * edges[4];

public:
int x;
int y;
HeadlessEdges(int xT, int yT, vector<int> * elements)
{
    x = xT;
    y = yT;
    cout << "Added: ";
    for (int i = 0; i < 4; i++)
    {
        if (i <= elements->size() / 2)
        {
            int tempLast = elements->back();
            elements->pop_back();
            int tempSecondLast = elements->back();
            elements->pop_back();
            edges[i] = new Node(tempSecondLast, tempLast);
            bool flag = edges[i]->setLocation(edges[i]);
            cout << "Flag " << flag << " : " << tempSecondLast << "," << tempLast << " ";
        }
        else
        {
            edges[i] = 0;
        }
    }
    cout << endl;
}
~HeadlessEdges()
{
    delete[] edges;
}

Node * getEdge(int index)
{
    return edges[index];
}
bool addEdges(HeadlessEdges * edges)
{
    // Add edges based on this, disreguard edges allready in the edges part
}

Node ** getEdges()
{
    return edges;
}
// As long as this doesent get used after this use case then there will be no problems with this function
bool replaceEdge(int index, Node * location)
{
    delete edges[index];
    edges[index] = location;
}
};

#endif
