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
#include "matrix.h" //used by graph.h
#include "priorityQ.h" //used by graph.h
#include "queue.h" //used by graph.h
#include "graph.h"


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
graph* createGFromM(Matrix<char>* str){
  return nullptr;
}

//reads file and stores the tile type at each point
//if dealing with ints for tile tracking is too much then implement Matrix template<T>
Matrix<char>* createMFromFile(FILE* map){
  //check for file pointer NE nullptr
  if (map == nullptr) perror("Map does not exist\t");

  Matrix<char>* mtrx = new Matrix<char>(H_SIZE,V_SIZE);

  //read the data into content
  rewind(map);
  int i = 0; 
  int c;
  while ((c = fgetc(map)) != EOF){
    mtrx->SetCell(i % 19, i/19, c);
    i++;
  }
  
  //translate data into matrix

  return mtrx;
}


void initTiles(char** tileData){
  //some setup for the directories as always
  /*char* tName = (char*)"gdata/tiles/t";*/
  char* dir = new char[14];

  for(int i = 1;i < 8; i++){
    //getting cast to 1 instead of '1', needs to be fixed
    sprintf(dir, "gdata/tiles/t%d",i);
    
    //open and read file into correct position in array
    FILE* tileFile = fopen(dir, "r");
    if (tileFile == nullptr) perror("The tile file doesnt exist (yet?)\t");
    fclose(tileFile);
  }
}
//function that calls createfromfile for Matrix and graph
//if pointers don't work then return as enum <graph,Matrix>
void initMap(graph* connections, Matrix<char>* tiles, char* fName, char** tileData){
  //doesnt print unless specified to where
  //"gdata/maps/"
  char* dir = new char[CHARCOUNT + 11];
  //create tchar because we cant use a string literal casted to a char*
  char* tchar = (char*)"gdata/maps/";

  //remember to remove 'terminating nul'
  sprintf(dir, "gdata/maps/%c%c",fName[0],fName[1]);
  /*dir[12] = fName[1];*/
  /*std::ifstream map(dir, std::ios::in)*/
  FILE* map = fopen(dir, "r");

  //grab the tiles from the files that define them
  initTiles(tileData);

  //marker
  fprintf(stderr, "tiles Initialized\n");

  //read map into tiles and connections
  tiles = createMFromFile(map);
  tiles->Display();

  connections = createGFromM(tiles);
  fclose(map);
  
}

//function to print based off of the map data
//comment out to hide warnings 

/*
void tileprint(Matrix* tiles){
  //using (i,j) notation is kinda redundant i should just access the array inside but this is more "in the spirit" of the class heirarchy
  for (int i = 0; i < tiles->len; i++){
    for (int j = 0; j < tiles->len; j++){
      char currtile = tiles->poke(i,j); 
      if (currtile == "#"){
        
      } else if (currtile == "0"){

      } else if (currtile == "P"){

      } else if (currtile == "E"){

      } else if (currtile == "G"){

      } else if (currtile == "S"){

      } else if (currtile == "D"){

      } 

    }
  } 
}
*/

//handle movement of player and enemy per turn (may get relocated to djakstra.h and enemy.h respectivly)
void updatePos(Matrix<char>){
}

int main(){
  char* mapSelect = new char[CHARCOUNT]; //make sure that gets doesnt overflow with the \0 at the end
  //7 is number of types of tile, 6 is characters per tile
  char** tileData = new char*[7];
  for(int i = 0; i < 7; i++) tileData[i] = new char[TILESIZE];
  Matrix<char>* tileMatrix;
  graph* connectionMatrix;
  //make static char*[5] that contains all the places the maps are located
  //potentially change last digit of the address in original pointer so we dont need more pointers
  printf("Press a number from 1 to 5 and then press enter to select a map");

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
  initMap(connectionMatrix, tileMatrix, mapSelect, tileData);
  return 1;
}

//empty space so that i can scroll comfortably, delete when done








































