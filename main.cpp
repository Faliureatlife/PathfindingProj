//move all includes from headers and place here so its easier to keep track of (no duplicates of cstdio etc.)
//it wont matter if the headers are missing their includes but we should keep track of which headers need which other headers if we want to make them portable to other projects
//i.e. graph.h needs matrix.h to work, so we will have to place it here and leave it commented in the header for that
#include <cstdio> //used by matrix.h for fprintf (for printing to stderr, not sure if we need to use an ifdef to change away from stderr on windows)
                  //used by graph.h for printfgraph
#include "matrix.h" //used by graph.h
#include "graph.h"

//the defines stay after includes to make sure they are only local and dont override others we may use
//SIZE is equal to the map side length squared
#define SIZE 25
#define CHARCOUNT 2
//reads file and puts connections into graph
graph* createGFromFile(char* str){
  return nullptr;
}

//reads file and stores the tile type at each point
//if dealing with ints for tile tracking is too much then implement matrix template<T>
matrix* createMFromFile(char* str){
  return nullptr;
}


//function that calls createfromfile for matrix and graph
//if pointers don't work then return as enum <graph,matrix>
void initMap(graph* connections, matrix* tiles, char* fName){
  //fopen to assign /dir/ to FILE* map
  //doesnt print unless specified to where
  //"gdata/maps/"
  char* dir = new char[CHARCOUNT + 11];
  //string literal to char* for weird c++ reasons
  //create tchar because we cant use a string literal casted to a char*
  char* tchar = (char*)"gdata/maps/";
  for(int i = 0; i < 11; i++) dir[i] = tchar[i];
  dir[11] = fName[0];
  dir[12] = fName[1];

  FILE* map = fopen(dir, "r");

  //error handling in case file doesnt exist
  if (map == nullptr) perror("\t");
  char* content;

  //should leave out the \0 at the end
  fgets(content, SIZE, map);
  tiles = createMFromFile(content);
  connections = createGFromFile(content);

}

//function to print based off of the map data
void tileprint(matrix){
}

//handle movement of player and enemy per turn (may get relocated to djakstra.h and enemy.h respectivly)
void updatePos(matrix){
}

int main(){
  char* mapSelect = new char[CHARCOUNT]; //make sure that gets doesnt overflow with the \0 at the end

  matrix* tileMatrix;
  graph* connectionMatrix;
  //make static char*[5] that contains all the places the maps are located
  //potentially change last digit of the address in original pointer so we dont need more pointers
  printf("Press a number from 1 to 5 and then press enter to select a map");

  //must be fgets instead of gets because of bufferoverflow reasons (doesnt exist past c++11)
  fgets(mapSelect, CHARCOUNT, stdin);
  mapSelect[1] = mapSelect[0];
  mapSelect[0] = 'm';

  //Post-Process will kill EOL/EOF char and make it something like an ('m', int) in order to maintain structure of directory positions
    
  //just here to see if its getting read right
    /*
    for (int i = 0; i < 2; i++)
    printf("%d, %c\n", i, mapSelect[i]);
    */
  //segfault :(
  initMap(connectionMatrix, tileMatrix, mapSelect);
  return 1;
}

//empty space so that i can scroll comfortably, delete when done








































