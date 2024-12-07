#include <cstdio>

int main(){
  FILE* test = fopen("t1", "rb");
  rewind(test);
  int c;
  int i = 0;
  char* C = new char[25];
  while ((c = fgetc(test)) != EOF){
    C[i] = c;
    i++;
  }
  printf("%s\n\n",C);
  printf("⎦∵⎣\n⎤ᐜ⎡\n");

  return 1;
}
