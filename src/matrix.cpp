
#include "../include/matrix.h"

template <typename T>
void Matrix<T>::Clean() {
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;
}

template <typename T>
Matrix<T>::Matrix() {
    n = 0;
    m = 0;
    A = nullptr;
}

template <typename T>
Matrix<T>::Matrix(int n1, int m1) {
    n = n1;
    m = m1;
    A = new T * [n];
    for (int i = 0; i < n; i++) {
        A[i] = new T[m];
        for (int j = 0; j < m; j++) {
            A[i][j] = 0;
        }
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix& M) {
    n = M.n;
    m = M.m;
    A = new T* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new T[m];
        for (int j = 0; j < m; j++) {
            A[i][j] = M.A[i][j];
        }
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    Clean();
}

template <typename T>
void Matrix<T>::Init(T x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = x;
        }
    }
}

template <typename T>
void Matrix<T>::Identity() {
    if (n == m) {
        Init(0);
        for (int i = 0; i < n; i++) {
            A[i][i] = 1;
        }
    }
}

template <typename T>
void Matrix<T>::Display() {
    std::cout << "Size: " << n << " X " << m << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << A[i][j] << " ";
        } std::cout << std::endl;
    }
}

template <typename T>
int Matrix<T>::GetRows() const {
    return n;
}

template <typename T>
int Matrix<T>::GetCols() const {
    return m;
}

template <typename T>
T Matrix<T>::GetCell(int i, int j) {
    try {
        return A[i][j];
    }
    catch (std::exception& e) {
      std::cout << "Issue with Index: " << e.what() << std::endl;
    }
}

template <typename T>
void Matrix<T>::SetCell(int i, int j, T x) {
    try {
        A[i][j] = x;
    }
    catch (std::exception& e) {
        std::cout << "Issue with Index: " << e.what() << std::endl;
    }
}

template <typename T>
T& Matrix<T>::operator()(int i, int j) {
    return A[i][j];
}

template <typename T>
T Matrix<T>::operator()(int i, int j) const {
    return A[i][j];
}

template <typename T>
void Matrix<T>::operator=(Matrix& a) {
    Clean();
    n = a.n;
    m = a.m;
    A = new T* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new T[m];
        for (int j = 0; j < m; j++) {
            A[i][j] = a.A[i][j];
        }
    }
}

template <typename T>
Matrix<T> Matrix<T>::Add(Matrix& a) {
    Matrix out(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out(i, j) = this->A[i][j] + a.A[i][j];
        }
    }
    return out;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix& a) {
    Matrix out(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out(i, j) = A[i][j] + a.A[i][j];
        }
    }
    return out;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(double x) {
    Matrix out(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out(i, j) = A[i][j] + x;
        }
    }
    return out;
}

template <typename T>
Matrix<T> Matrix<T>::Sub(Matrix& a) {
    Matrix out(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out(i, j) = A[i][j] - a.A[i][j];
        }
    }
    return out;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix& a) {
    Matrix out(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out.SetCell(i, j, A[i][j] - a.A[i][j]);
        }
    }
    return out;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(double x) {
    Matrix out(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out.SetCell(i, j, A[i][j] - x);
        }
    }
    return out;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix& a) {
    if (this->m != a.n) {
        std::cout << "Improper Dimesions" << std::endl;
        return *this;
    }
    else {
        double temp;
        Matrix out(n, a.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a.m; j++) {
                temp = 0;
                for (int k = 0; k < m; k++) {
                    temp += A[i][k] * a(k, j);
                }
                out.A[i][j] = temp;
            }
        }
        return out;
    }

}

template <typename T>
Matrix<T> Matrix<T>::operator*(double x) {
    Matrix out(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out.SetCell(i, j, A[i][j] * x);
        }
    }
    return out;
}

template <typename T>
std::tuple<double, int, int> Matrix<T>::GetMin() {
    double minVal = DBL_MAX;
    int argi = 0; int argj = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((A[i][j] < minVal) && (A[i][j] > 0)) {
                minVal = A[i][j];
                argi = i;
                argj = j;
            }
        }
    }
    A[argi][argj] = 0;
    return std::make_tuple(minVal, argi, argj);
}

template class Matrix<char>;