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


class runner {
public:
    graph* createGFromM(Matrix<char>* mtrx, int* entPos);

    //reads file and stores the tile type at each point
    //if dealing with ints for tile tracking is too much then implement Matrix template<T>
    Matrix<char>* createMFromFile(FILE* map);


    void initTiles(char** tileData);


    void tileprint(Matrix<char>* tiles, char** tileData);

    //function that calls createfromfile for Matrix and graph
    //if pointers don't work then return as enum <graph,Matrix>
    void initMap(graph*& connections, Matrix<char>*& tiles, char* fName, char** tileData, int*& entData);
    void runLoop(graph*& connections, Matrix<char>*& tiles, char** tileData, int*& entData);
};
