/*#include <cstdio>*/
/*#include "matrix.h" //allow "normal" array indexing i think*/

class GraphAM {
private:
    int n;
    double* M;
    int* current;
public:
    GraphAM() {
        n = 0;
        M = nullptr;
        current = nullptr;
    }
    GraphAM(int n1) {
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
    ~GraphAM() {
        delete[] M;
        delete[] current;
    }
    int GetNumberVertices() {
        return n;
    }
    int GetDegree(int u) {
        int degree = 0;
        for (int v = 0; v < n; v++) {
            if (EdgeExist(u, v)) {
                degree++;
            }
        }
        return degree;
    }
    int GetIndex(int u, int v) {
        return u * n + v;
    }
    bool EdgeExist(int u, int v) {
        return (M[GetIndex(u, v)] != 0);
    }
    double GetEdgeWeight(int u, int v) {
        if (u < 0 || u >= n || v < 0 || v >= n) {
            return -1;
        }
        return M[GetIndex(u, v)];
    }
    void SetDirectedE(int u, int v, double w) {
        M[GetIndex(u, v)] = w;
    }
    void SetDirectedE(int u, int v) {
        M[GetIndex(u, v)] = 1;
    }
    void SetUndirectedE(int u, int v, double w) {
        M[GetIndex(u, v)] = w;
        M[GetIndex(v, u)] = w;
    }
    void SetUndirectedE(int u, int v) {
        M[GetIndex(u, v)] = 1;
        M[GetIndex(v, u)] = 1;
    }
    void RemoveDirectedE(int u, int v) {
        M[GetIndex(u, v)] = 0;
    }
    void RemoveUndirectedE(int u, int v) {
        M[GetIndex(u, v)] = 0;
        M[GetIndex(v, u)] = 0;
    }
    void SetCurrentVertex(int u) {
        current[u] = -1;
    }
    bool GetNextAdjacent(int u, int& vout) {
        int v = current[u] + 1;
        vout = -1;
        bool found = false;
        while ((!found) && (v < n)) {
            if (EdgeExist(u, v)) {
                found = true;
                vout = v;
            }
            v++;
        }
        current[u] = vout;
        return found;

    }
    void Display() {
        int k = 0;
        cout << " :";
        for (int v = 0; v < n; v++) {
            cout << v << "\t";
        } cout << endl;
        for (int u = 0; u < n; u++) {
            cout << u << ":";
            for (int v = 0; v < n; v++) {
                cout << M[k] << "\t";
                k++;
            } cout << endl;
        }
    }
    void DisplayDirected() {
        int k = 0;
        cout << "List of Edges:" << endl;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                cout << "(" << u << "," << v << ") w:" << GetEdgeWeight(u, v) << endl;
            }
        }
    }
    void DisplayUndirected() {
        int k = 0;
        cout << "List of Edges:" << endl;
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (EdgeExist(u, v)) {
                    cout << "(" << u << "," << v << ") w:" << GetEdgeWeight(u, v) << endl;
                }
            }
        }
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