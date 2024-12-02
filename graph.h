/*#include <cstdio>*/
/*#include "matrix.h" //allow "normal" array indexing i think*/
class graph{
public:
  matrix<int> mtrx;
  int size;

  graph(int n) {
    /*matrix = new int[n][n];*/
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
};

/*
* class GraphAM {
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
cout << "(" << u << "," << v << ") w:" << GetEdgeWeight(u, v) <<
endl;
}
}
}
void DisplayUndirected() {
int k = 0;
cout << "List of Edges:" << endl;
for (int u = 0; u < n; u++) {
for (int v = u + 1; v < n; v++) {
if (EdgeExist(u, v)) {
cout << "(" << u << "," << v << ") w:" << GetEdgeWeight(u, v)
<< endl;
}
}
}
}
void DisplayMST(int* parent) {
cout << "MST Edge Weight" << endl;
for (int i = 1; i < n; i++) {
cout << "(" << parent[i] << "-> " << i << ") w = " << GetEdgeWeight(i,
parent[i]) << endl;
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
void Acyclic(int u, GraphAM& G, int* color, int* pi, int* back, int parent) {
color[u] = 1;
int v, n = G.GetNumberVertices();
G.SetCurrentVertex(u);
while (G.GetNextAdjacent(u, v)) {
if (G.EdgeExist(u, v) && (v != u) && (v != parent)) {
if (color[v] == 0) {
pi[v] = u;
Acyclic(v, G, color, pi, back, u);
}
else {
back[v] = u;
}
}
}
color[u] = 2;
}
bool IsAcyclic(int u, GraphAM& G) {
int n = G.GetNumberVertices();
int* color = new int[n];
int* back = new int[n];
int* pi = new int[n];
for (int i = 0; i < n; i++) {
color[i] = 0;
back[i] = -1;
pi[i] = -1;
}
Acyclic(u, G, color, pi, back, -1);
int i = 0;
bool acyclic = true;
bool found = false;
while ((i < n) && (!found)) {
if ((back[i] == u) &&(pi[i] != u)) {
found = true;
acyclic = false;
}
i++;
}
delete[] color;
delete[] back;
return acyclic;
}
void Kruskal() {
GraphAM A(n);
Matrix S(n, n);
S.Init(0);
for (int i = 0; i < n; i++) {
for (int j = i + 1; j < n; j++) {
S(i, j) = GetEdgeWeight(i, j);
}
}
int total = 0;
for (int i = 0; i < n; i++) {
for (int j = i + 1; j < n; j++) {
if (S(i, j) != 0) {
total++;
}
}
}
int argi, argj;
double val;
tie(val, argi, argj) = S.GetMin();
S(argi, argj) = 0;
A.SetUndirectedE(argi, argj, val);
for (int i = 0; i < total; i++) {
tie(val, argi, argj) = S.GetMin();
S(argi, argj) = 0;
A.SetUndirectedE(argi, argj, val);
if (!IsAcyclic(argi, A)) {
A.RemoveUndirectedE(argi, argj);
}
}
cout << "- Display Graph -" << endl;
A.DisplayUndirected();
}
};
*/