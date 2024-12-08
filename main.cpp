//move all includes from headers and place here so its easier to keep track of (no duplicates of cstdio etc.)
//it wont matter if the headers are missing their includes but we should keep track of which headers need which other headers if we want to make them portable to other projects
//i.e. graph.h needs Matrix.h to work, so we will have to place it here and leave it commented in the header for that


#include <cstdio> //used by Matrix.h for fprintf (for printing to stderr, not sure if we need to use an ifdef to change away from stderr on windows)
                  //used by graph.h for printfgraph
#include <climits> //used by graph.h
#include <cfloat>
#include <iostream> //;w;
#include <stdexcept> //used by matrix.h
#include <tuple> //used by main
#include "include/matrix.h" //used by graph.h
#include "include/priorityQ.h" //used by graph.h
#include "include/queue.h" //used by graph.h
#include "include/graph.h"
#include "include/runner.h"


//the defines stay after includes to make sure they are only local and dont override others we may use
//SIZE is equal to the map side length squared
#define SIZE 380
#define H_SIZE 19
#define V_SIZE 20
//i dont remember 
#define CHARCOUNT 2
//TILESIZE is the amount of chars in a single tile 
#define TILESIZE 6
//reads file and puts connections into graph


//function to print based off of the map data
//comment out to hide warnings 


//handle movement of player and enemy per turn (may get relocated to djakstra.h and enemy.h respectivly)
/*void updatePos(Matrix<char>) {
}*/
int main(){
  runner run;
  setlocale(LC_ALL, "en_US.UTF-32");
  char* mapSelect = new char[CHARCOUNT]; //make sure that gets doesnt overflow with the \0 at the end
  //7 is number of types of tile, 6 is characters per tile
  char** tileData = new char*[7];
  for(int i = 0; i < 7; i++) tileData[i] = new char[TILESIZE];
  Matrix<char>* tileMatrix;
  graph* connectionMatrix;
  //make static char*[5] that contains all the places the maps are located
  //potentially change last digit of the address in original pointer so we dont need more pointers
  printf("Press a number from 1 to 5 and then press enter to select a map ");

  //must be fgets instead of gets because of bufferoverflow reasons (doesnt exist past c++11)
  fgets(mapSelect, CHARCOUNT, stdin);
  printf("%c\n",mapSelect[0]);
  mapSelect[1] = mapSelect[0];
  mapSelect[0] = 'm';

  //for WINDOWS
  /*system("CLS");*/

  //for LINUX
  /*system("clear");*/

  //Post-Process will kill EOL/EOF char and make it something like an ('m', int) in order to maintain structure of directory positions
    
  //just here to see if its getting read right
  //segfault :(
  run.initMap(connectionMatrix, tileMatrix, mapSelect, tileData);
  return 0;
}

//empty space so that i can scroll comfortably, delete when done








































