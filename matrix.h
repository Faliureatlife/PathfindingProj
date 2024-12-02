
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
*/
  }
  void setzero(int n, int m){
    if (n >= len) fprintf(stderr, "OOBE\n");
    
    arr[(n*len) - 1 + m] = 0;
  }

  T poke(int n, int m){
    return arr[(n*len) - 1 + m];
  }

};

/*class Matrix {
private:
int n, m;
double** A;
void Clean() {
for (int i = 0; i < n; i++) {
delete[] A[i];
} delete[] A;
}
public:
Matrix() {
n = 0;
m = 0;
A = nullptr;
}
Matrix(int n1, int m1) {
n = n1;
m = m1;
A = new double* [n];
for (int i = 0; i < n; i++) {
A[i] = new double[m];
for (int j = 0; j < m; j++) {
A[i][j] = 0;
}
}
}
Matrix(const Matrix& M) {
n = M.n;
m = M.m;
A = new double* [n];
for (int i = 0; i < n; i++) {
A[i] = new double[m];
for (int j = 0; j < m; j++) {
A[i][j] = M.A[i][j];
}
}
}
~Matrix() {
Clean();
}
void Init(double x) {
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
A[i][j] = x;
}
}
}
void Identity() {
if (n == m) {
Init(0);
for (int i = 0; i < n; i++) {
A[i][i] = 1;
}
}
}
void Display() {
cout << "Size: " << n << " X " << m << endl;
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
cout << A[i][j] << " ";
} cout << endl;
}
}
int GetRows() const {
return n;
}
int GetCols() const {
return m;
}
double GetCell(int i, int j) {
try {
return A[i][j];
}
catch (exception& e) {
cout << "Issue with Index: " << e.what() << endl;
}
}
void SetCell(int i, int j, double x) {
try {
A[i][j] = x;
}
catch (exception& e) {
cout << "Issue with Index: " << e.what() << endl;
}
}
double operator()(int i, int j) const{
return A[i][j];
}
double& operator()(int i, int j){
return A[i][j];
}
void operator=(Matrix& a) {
Clean();
n = a.n;
m = a.m;
A = new double* [n];
for (int i = 0; i < n; i++) {
A[i] = new double[m];
for (int j = 0; j < m; j++) {
A[i][j] = a.A[i][j];
}
}
}
Matrix Add(Matrix& a) {
Matrix out(n, m);
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
out(i, j) = this->A[i][j] + a.A[i][j];
}
}
return out;
}
Matrix operator+(Matrix& a) {
Matrix out(n, m);
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
out(i, j) = A[i][j] + a.A[i][j];
}
}
return out;
}
Matrix operator+(double x) {
Matrix out(n, m);
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
out(i, j) = A[i][j] + x;
}
}
return out;
}
Matrix Sub(Matrix& a) {
Matrix out(n, m);
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
out(i, j) = A[i][j] - a.A[i][j];
}
}
return out;
}
Matrix operator-(Matrix& a) {
Matrix out(n, m);
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
out.SetCell(i, j, A[i][j] - a.A[i][j]);
}
}
return out;
}
Matrix operator-(double x) {
Matrix out(n, m);
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
out.SetCell(i, j, A[i][j] - x);
}
}
return out;
}
Matrix operator*(Matrix& a) {
if (this->m != a.n) {
cout << "Improper Dimesions" << endl;
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
Matrix operator*(double x) {
Matrix out(n, m);
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
out.SetCell(i, j, A[i][j] * x);
}
}
return out;
}
tuple<double, int, int> GetMin() {
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
return make_tuple(minVal, argi, argj);
}
};*/
