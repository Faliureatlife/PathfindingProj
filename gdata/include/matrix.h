#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cfloat> 
#include <tuple>

template <typename T>  
class Matrix {
private:
    int n, m;
    T** A;
    void Clean();
public:
    Matrix();
    Matrix(int n1, int m1);
    Matrix(const Matrix& M);
    ~Matrix();
    void Init(T x);
    void Identity();
    void Display();
    int GetRows() const; 
    int GetCols() const; 
    T GetCell(int i, int j);
    void SetCell(int i, int j, T x);
    double operator()(int i, int j) const;
    double& operator()(int i, int j);
    void operator=(Matrix& a);
    Matrix Add(Matrix& a);
    Matrix operator+(Matrix& a);
    Matrix operator+(double x);
    Matrix Sub(Matrix& a);
    Matrix operator-(Matrix& a); 
    Matrix operator-(double x);
    Matrix operator*(Matrix& a); 
    Matrix operator*(double x);
    std::tuple<double, int, int> GetMin();
};

#endif

/*
template <typename T>
class matrix {
public:
  T* arr;
  int len;
  matrix(): arr(nullptr), len(0) {}
  matrix(int n) :  arr(nullptr), len(n) {}
  
  // N MUST EQUAL LEN
  void initmtrx(int n){
    T* newarr = new T[n*n];
    arr = newarr;
  }
  void setone(int n, int m){
    if (n >= len) fprintf(stderr, "OOBE\n");
    
    arr[(n*len) - 1 + m] = 1;
/* all off by one teehee
 *   0   1   2   3   4
 *   5   6   7   8   9
 *   10  11  12  13  14
 *   15  16  17  18  19
 *   20  21  22  23  24 
*//*
  }
  void setzero(int n, int m){
    if (n >= len) fprintf(stderr, "OOBE\n");
    
    arr[(n*len) - 1 + m] = 0;
  }

  T poke(int n, int m){
    return arr[(n*len) - 1 + m];
  }

};

*/
