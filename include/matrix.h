#define MATRIX_H

#include <iostream>
#include <cfloat>
#include <tuple>

#pragma once
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
    T operator()(int i, int j) const;
    T& operator()(int i, int j);
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



