/*#include <cstdio>*/
/*#include "matrix.h" //allow "normal" array indexing i think*/

class graph {
private:
    int n;
    double* M;
    int* current;
public:
    graph() {
        n = 0;
        M = nullptr;
        current = nullptr;
    }
    graph(int n1) {
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
    ~graph() {
        delete[] M;
        delete[] current;
    }
    int getNumberVertices() {
        return n;
    }
    int getDegree(int u) {
        int degree = 0;
        for (int v = 0; v < n; v++) {
            if (edgeExist(u, v)) {
                degree++;
            }
        }
        return degree;
    }
    int getIndex(int u, int v) {
        return u * n + v;
    }
    bool edgeExist(int u, int v) {
        return (M[getIndex(u, v)] != 0);
    }
    double getEdgeWeight(int u, int v) {
        if (u < 0 || u >= n || v < 0 || v >= n) {
            return -1;
        }
        return M[getIndex(u, v)];
    }
    void setDirectedE(int u, int v, double w) {
        M[getIndex(u, v)] = w;
    }
    void setDirectedE(int u, int v) {
        M[getIndex(u, v)] = 1;
    }
    void setUndirectedE(int u, int v, double w) {
        M[getIndex(u, v)] = w;
        M[getIndex(v, u)] = w;
    }
    void setUndirectedE(int u, int v) {
        M[getIndex(u, v)] = 1;
        M[getIndex(v, u)] = 1;
    }
    void removeDirectedE(int u, int v) {
        M[getIndex(u, v)] = 0;
    }
    void removeUndirectedE(int u, int v) {
        M[getIndex(u, v)] = 0;
        M[getIndex(v, u)] = 0;
    }
    void setCurrentVertex(int u) {
        current[u] = -1;
    }
    bool getNextAdjacent(int u, int& vout) {
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
    void display() {
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
    void DisplayDirected() {
        int k = 0;
        std::cout << "List of Edges:" << std::endl;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                std::cout << "(" << u << "," << v << ") w:" << getEdgeWeight(u, v) << std::endl;
            }
        }
    }
    void displayUndirected() {
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
    void displayMST(int* parent) {
        std::cout << "MST Edge Weight" << std::endl;
        for (int i = 1; i < n; i++) {
            std::cout << "(" << parent[i] << "-> " << i << ") w = " << getEdgeWeight(i, parent[i]) << std::endl;
        }
    }
    int minK(int* key, bool* mstSet) {
        int min = INT_MAX;
        int min_index = INT_MAX;
        for (int v = 0; v < n; v++) {
            if ((mstSet[v] == false) && (key[v] < min)) {
                min = key[v];
                min_index = v;
            }
        }
        return min_index;
    }
};

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
