#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
#include "node.h"
#include "edge.h"
// #include "headlessEdges.h"

class Graph {
private:

    Node * start;
    Node * findNode(int x, int y, Node * temp)
    {
        int tX = temp->x;
        int tY = temp->y;

        // cout << "Here: " << temp << endl;
        if (x == tX) {
            if (y == tY) {
                cout << "Returning actual value 1: " << tX << "," << tY << " " << temp << endl;
                return temp;
            }
        }
        temp->searched = true;
        for (int i = 0; i < temp->getNumConnections(); i++) {
            if (!temp->getConnectedNode(i)->searched) {
                cout << "Connected Node Ptr: " << temp->getConnectedNode(i) << endl;
                // Bug here
                Node * temp2 = findNode(x, y, temp->getConnectedNode(i));
                if (temp2 != 0) {
                    cout << "Found and returning: " << tX << "," << tY << " " << temp2 << endl;
                    return temp2;
                }
            }
        }
        cout << "Did Not find " << endl;
        return 0;
    }

    resetFlags(Node * resetVal)
    {
        // cout << "Resetting: " << resetVal->x << "," << resetVal->y << endl;
        resetVal->searched = false;
        for (int i = 0; i < resetVal->getNumConnections(); i++) {
            Node * temp = resetVal->getConnectedNode(i);
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
    }

    removeStart()
    {
        start = 0;
    }


    Node * findNode(int x, int y)
    {
        Node * temp = findNode(x, y, start);

        resetFlags(start);
        return temp;
    }

    // Take 2 graphs, get the node coordinances of each of the connections that needs to be made
    // Also take the ptr to the graph that you would like to connect to the current graph
    bool connectGraphs(int thisX, int thisY, Graph * graphToConnect, int newX, int newY)
    {
        bool flag = false;
        Node * foundMatching = findNode(thisX, thisY);
        Node * newGraphAddr  = graphToConnect->findNode(newX, newY);

        cout << "Found coord: " << newGraphAddr << endl;
        if (newGraphAddr != 0 && foundMatching != 0) {
            flag = foundMatching->addConnection(newGraphAddr);
            cout << "Flag Status: " << flag << endl;
            graphToConnect->removeStart();
            delete graphToConnect;
        }

        return flag;
    }

    bool addNode(int oldX, int oldY, int newX, int newY)
    {
        Node * foundOldNode = findNode(oldX, oldY);

        if (foundOldNode != 0) {
            return foundOldNode->addConnection(new Node(newX, newY));
        }
        return 0;
    }

    bool addConnection(int oldX, int oldY, int newX, int newY)
    {
        Node * foundOldNode    = findNode(oldX, oldY);
        Node * foundSecondNode = findNode(newX, newY);

        if (foundOldNode != 0 && foundSecondNode != 0) {
            return foundOldNode->addConnection(foundSecondNode);
        }
        return 0;
    }

    friend std::ostream&operator << (std::ostream& stream, Graph& graph)
    {
        stream << "\n";
        graph.start->printNode(stream);
        graph.resetFlags(graph.start);
        return stream;
    }
};


#endif
