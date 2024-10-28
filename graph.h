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
