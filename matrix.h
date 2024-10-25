
class matrix {
public:
  int* arr;
  int len;
  matrix(): arr(nullptr), len(0) {}
  matrix(int n) :  arr(nullptr), len(n) {}
  
  // N MUST EQUAL LEN
  void initmtrx(int n){
    int* newarr = new int[n*n];
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

  int poke(int n, int m){
    return arr[(n*len) - 1 + m];
  }

};
