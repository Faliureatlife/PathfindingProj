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
/* 
void DisplayShortestPath(double* d, int* pi, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Vertex: " << i << " : d = " << d[i] << " : pi: " << pi[i] << endl;
    }
    cout << endl;
} */

/*class graph {
public:
  matrix<int> mtrx;
  int size;

  graph(int n) {
    /*matrix = new int[n][n];*//*
    mtrx = matrix<int>(n);
    mtrx.initmtrx(n);    
    size = n;
  }

  void addedge(int u, int v){
    mtrx.setone(u,v);
    mtrx.setone(v,u);
  }

  void print(){
    for (int i = 0; i < size; i++){
      for(int j = 0; j < size; j++) {
        printf("%d\t",mtrx.poke(i,j));
      }
      printf("\n");
    }
  }
};*/
