#include "graph.h"

graph::graph() {
    n = 0;
    M = nullptr;
    current = nullptr;
}
graph::graph(int n1) {
    n = n1;
    M = new double[n * n];
    for (int i = 0; i < n * n; i++) {
        M[i] = 0;
    }
    current = new int[n];
    for (int i = 0; i < n; i++) {
        current[i] = 0;
    }
}
graph::~graph() {
    delete[] M;
    delete[] current;
}
int graph::getNumberVertices() {
    return n;
}
int graph::getDegree(int u) {
    int degree = 0;
    for (int v = 0; v < n; v++) {
        if (edgeExist(u, v)) {
            degree++;
        }
    }
    return degree;
}
int graph::getIndex(int u, int v) {
    return u * n + v;
}
bool graph::edgeExist(int u, int v) {
    return (M[getIndex(u, v)] != 0);
}
double graph::getEdgeWeight(int u, int v) {
    if (u < 0 || u >= n || v < 0 || v >= n) {
        return -1;
    }
    return M[getIndex(u, v)];
}
void graph::setDirectedE(int u, int v, double w) {
    M[getIndex(u, v)] = w;
}
void graph::setDirectedE(int u, int v) {
    M[getIndex(u, v)] = 1;
}
void graph::setUndirectedE(int u, int v, double w) {
    M[getIndex(u, v)] = w;
    M[getIndex(v, u)] = w;
}
void graph::setUndirectedE(int u, int v) {
    M[getIndex(u, v)] = 1;
    M[getIndex(v, u)] = 1;
}
void graph::removeDirectedE(int u, int v) {
    M[getIndex(u, v)] = 0;
}
void graph::removeUndirectedE(int u, int v) {
    M[getIndex(u, v)] = 0;
    M[getIndex(v, u)] = 0;
}
void graph::setCurrentVertex(int u) {
    current[u] = -1;
}
bool graph::getNextAdjacent(int u, int& vout) {
    int v = current[u] + 1;
    vout = -1;
    bool found = false;
    while ((!found) && (v < n)) {
        if (edgeExist(u, v)) {
            found = true;
            vout = v;
        }
        v++;
    }
    current[u] = vout;
    return found;

}
void graph::display() {
    int k = 0;
    std::cout << " :";
    for (int v = 0; v < n; v++) {
        std::cout << v << "\t";
    } std::cout << std::endl;
    for (int u = 0; u < n; u++) {
        std::cout << u << ":";
        for (int v = 0; v < n; v++) {
            std::cout << M[k] << "\t";
            k++;
        } std::cout << std::endl;
    }
}
void graph::displayDirected() {
    int k = 0;
    std::cout << "List of Edges:" << std::endl;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            std::cout << "(" << u << "," << v << ") w:" << getEdgeWeight(u, v) << std::endl;
        }
    }
}
void graph::displayUndirected() {
    int k = 0;
    std::cout << "List of Edges:" << std::endl;
    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) {
            if (edgeExist(u, v)) {
                std::cout << "(" << u << "," << v << ") w:" << getEdgeWeight(u, v) << std::endl;
            }
        }
    }
}

void graph::dijkstra(int s, double*& d, int*& pi) {
    d = new double[n];
    pi = new int[n];
    priorityQueue* V = new priorityQueue(n);
    queue* S = new queue(n);
    for (int u = 0; u < n; u++) {
        d[u] = DBL_MAX;
        pi[u] = -1;
    }
    d[s] = 0;
    for (int u = 0; u < n; u++) {
        V->push(u, d[u]);
    }
    V->display();
    while (!V->isEmpty()) {
        data out = V->pop();
        V->display(); //Dont know what you want with this
        S->enQueue(out.index);
        int u = out.index;
        //cout << "Use: " << out.index << " with d:" << out.value << endl;
        for (int v = 0; v < n; v++) {
            if (edgeExist(u, v)) {
                double w = getEdgeWeight(u, v);
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    pi[v] = u;
                    V->decreaseKey(v, d[v]);
                }
            }
        }
        //DisplayShortestPath(d, pi, n);  
        V->display(); //Dont know what you want with this
    }
    delete V;
    delete S;
}