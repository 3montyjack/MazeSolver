#include "node.h"

Node::Node(int x, int y)
{
    end           = false;
    searched      = false;
    connectionNum = 0;
    this->x       = x;
    this->y       = y;
    for (int i = 0; i < 4; i++) {
        connections[i] = new Edge(this);
    }
    // cout << "New Node: " << this->x << "," << this->y << endl;
};

Node::Node()
{
    Node(-1, -1);
};

Node::~Node()
{
    for (int i = 0; i < 4; i++) {
        // connections->deleteMe(thisLoca);
        // delete connections[i];
    }
    delete[] connections;
};
