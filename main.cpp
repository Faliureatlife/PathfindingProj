//move all includes from headers and place here so its easier to keep track of (no duplicates of cstdio etc.)
//it wont matter if the headers are missing their includes but we should keep track of which headers need which other headers if we want to make them portable to other projects
//i.e. graph.h needs matrix.h to work, so we will have to place it here and leave it commented in the header for that
#include <cstdio> //used by matrix.h for fprintf (for printing to stderr, not sure if we need to use an ifdef to change away from stderr on windows)
                  //used by graph.h for printfgraph
#include "matrix.h" //used by graph.h
#include "graph.h"

//the defines stay after includes to make sure they are only local and dont override others we may use
//SIZE is equal to the map side length squared
#DEFINE SIZE 25

//function that calls createfromfile for matrix and graph
void initMap(char* dir){
  //fopen to assign /dir/ to FILE* map
  FILE* map;
  char* content;
  fgets(content, SIZE, map);
  matrix tiles = createMFromFile(content);
  const graph connections = createGFromFile(content);
}

//reads file and puts connections into graph
graph createGFromFile(char* str){

}

//reads file and stores the tile type at each point
//if dealing with ints for tile tracking is too much then implement matrix template<T>
matrix createMFromFile(char* str){

}

//function to print based off of the map data
void tileprint(matrix){


}

//handle movement of player and enemy per turn (may get relocated to djakstra.h and enemy.h respectivly)
void updatePos(matrix){


}


int main(){
  char* mapSelect = new char[2]; //make sure that gets doesnt overflow with the \0 at the end
                                 //also make sure to handle difference between LF and CRLF before its runnable 
  
  //make static char*[5] that contains all the places the maps are located
  //potentially change last digit of the address in original pointer so we dont need more pointers
  printf("Press a number from 1 to 5 and then press enter to select a map");
  gets(mapSelect,stdio);
  //Post-Process will kill EOL/EOF char and make it something like an ('m', int) in order to maintain structure of directory positions
  
  initMap(mapSelect);
  return 1;
}
