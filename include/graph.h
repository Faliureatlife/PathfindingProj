/*#include <cstdio>*/

#include "matrix.h"
#include "queue.h"
#include "priorityQ.h"

#pragma once
class graph {
private:
    int n;
    double* M;
    int* current;
public:
    graph();
    graph(int n1);
    ~graph();
    int getNumberVertices();
    int getDegree(int u);
    int getIndex(int u, int v);
    bool edgeExist(int u, int v);
    double getEdgeWeight(int u, int v);
    void setDirectedE(int u, int v, double w);
    void setDirectedE(int u, int v);
    void setUndirectedE(int u, int v, double w);
    void setUndirectedE(int u, int v);
    void removeDirectedE(int u, int v);
    void removeUndirectedE(int u, int v);
    void setCurrentVertex(int u);
    bool getNextAdjacent(int u, int& vout);
    void display();
    void displayDirected();
    void displayUndirected();

    void dijkstra(int s, double*& d, int*& pi);

};