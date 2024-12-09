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


int main(){
  runner run;
  setlocale(LC_ALL, "en_US.UTF-32");
  char* mapSelect = new char[CHARCOUNT]; //make sure that gets doesnt overflow with the \0 at the end
  //7 is number of types of tile, 6 is characters per tile
  char** tileData = new char*[7];
  for(int i = 0; i < 7; i++) tileData[i] = new char[TILESIZE];
  Matrix<char>* tileMatrix;
  graph* connectionMatrix;
  int* entData;

  printf("Press a number from 1 to 2 and then press enter to select mode: \n");
  
  printf("Press a number from 1 to 5 and then press enter to select a map: ");
  fgets(mapSelect, CHARCOUNT, stdin);

  // Validate input to ensure it is between '1' and '5'
  while (mapSelect[0] < '1' || mapSelect[0] > '5') {
      printf("Invalid Map Number\n");
      while (getchar() != '\n');
      printf("Press a number from 1 to 5 and then press enter to select a map: ");
      fgets(mapSelect, CHARCOUNT, stdin);
  }

  printf("%c\n",mapSelect[0]);
  mapSelect[1] = mapSelect[0];
  mapSelect[0] = 'm';


  run.initMap(connectionMatrix, tileMatrix, mapSelect, tileData, entData);

  run.runLoop(connectionMatrix,tileMatrix,tileData,entData);

  return 0;
}

//empty space so that i can scroll comfortably, delete when done








































