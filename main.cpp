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
#define TILESIZE 6
//reads file and puts connections into graph
graph* createGFromFile(char* str){
  return nullptr;
}

//reads file and stores the tile type at each point
//if dealing with ints for tile tracking is too much then implement matrix template<T>
matrix<char>* createMFromFile(char* str){
  return nullptr;
}


void initTiles(char** tileData){
  //some setup for the directories as always
  char* tName = (char*)"gdata/tiles/t";
  char* dir = new char[14];
  for(int i = 0; i < 13; i++) dir[i] = tName[i];

  for(int i = 1;i < 8; i++){
    //getting cast to 1 instead of '1', needs to be fixed
    dir[13] = static_cast<char>(i);
    /*dir[13] = (char)i;*/
    
    //error in these two lines VV (i believe missing file)
    //open and read file into correct position in array
    FILE* tileFile = fopen(dir, "r");
    if (tileFile == nullptr) {fprintf(stderr,"%d ",dir[13]);perror("the tile file t doesnt exist (yet?)\t"); }
    fgets(tileData[i], 7, tileFile);


  }
}
//function that calls createfromfile for matrix and graph
//if pointers don't work then return as enum <graph,matrix>
void initMap(graph* connections, matrix<char>* tiles, char* fName, char** tileData){
  //doesnt print unless specified to where
  //"gdata/maps/"
  char* dir = new char[CHARCOUNT + 11];
  //create tchar because we cant use a string literal casted to a char*
  char* tchar = (char*)"gdata/maps/";
  for(int i = 0; i < 11; i++) dir[i] = tchar[i];
  dir[11] = fName[0];
  dir[12] = fName[1];

  //fopen to assign /dir/ to FILE* map
  FILE* map = fopen(dir, "r");

  //error handling in case file doesnt exist
  if (map == nullptr) perror("\t");
  char* content;

  //should leave out the \0 at the end
  fgets(content, SIZE, map);
  tiles = createMFromFile(content);
  connections = createGFromFile(content);
  initTiles(tileData);
}

//function to print based off of the map data
//comment out to hide warnings 



/*
void tileprint(matrix* tiles){
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
void updatePos(matrix<char>){
}

int main(){
  char* mapSelect = new char[CHARCOUNT]; //make sure that gets doesnt overflow with the \0 at the end
  //7 is number of types of tile, 6 is characters per tile
  char** tileData = new char*[7];
  for(int i = 0; i < 7; i++) tileData[i] = new char[TILESIZE];
  matrix<char>* tileMatrix;
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
  initMap(connectionMatrix, tileMatrix, mapSelect, tileData);
  return 1;
}

//empty space so that i can scroll comfortably, delete when done








































