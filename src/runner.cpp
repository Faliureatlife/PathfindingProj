
#include "../include/runner.h"

graph* runner::createGFromM(Matrix<char>* mtrx, int* entPos ) {
    //cursor
    char c;
    //cursor's cursor
    graph* graff = new graph(SIZE + 1);
    //graph is 380x380
    //eqn for current
    //(i*H_SIZE) + j
    char n;
    int ecnt = 0;
    for (int i = 0; i < H_SIZE; i++) {
        for (int j = 0; j < V_SIZE; j++) {
            //still need to add in support for = and "
            if ((c = mtrx->GetCell(i, j)) == '0' || c == 'v' || c == '^') {
                if (c == 'v') {
                entPos[1+ecnt] = 1;
                ecnt++;
                } else if (c == '^') entPos[0] == 1;
                for (int k = -1; k < 2; k++) {
                    //add catch
                    try {
                        (n = mtrx->GetCell(i - 1, j + k));
                        /*fprintf(stderr, "aaa (%d,%d) to  (%d, %d), or at %d in the graph\n",i,j,i-1, j+k, ((i-1) * H_SIZE) + j + k);*/

                        //(i-1*H_SIZE) - j + k should give the output 
                        if (n == '0' || n == 'v' || n == '^' || n == '>')
                            graff->setUndirectedE((i * H_SIZE + j), ((i - 1) * H_SIZE + j + k), 1);
                        else if (n == '=')
                            graff->setUndirectedE((i * H_SIZE + j), ((i - 1) * H_SIZE + j + k), 3);
                    }
                    catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }
                    try {
                        /*fprintf(stderr, "bbb %d,%d\n",i+1,j+k);*/
                        (n = mtrx->GetCell(i + 1, j + k));
                        if (n == '0' || n == 'v' || n == '^' || n == '>')
                            graff->setUndirectedE((i * H_SIZE + j), ((i + 1) * H_SIZE + j + k), 1);
                        else if (n == '=')
                            graff->setUndirectedE((i * H_SIZE + j), ((i + 1) * H_SIZE + j + k), 3);
                    }
                    catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }
                }
                try {
                    /*fprintf(stderr, "ccc\n");*/
                    n = mtrx->GetCell(i, j + 1);
                    if (n == '0' || n == 'v' || n == '^' || n == '>')
                        graff->setUndirectedE((i * H_SIZE + j), (i * H_SIZE + j + 1), 1);
                    else if (n == '=')
                        graff->setUndirectedE((i * H_SIZE + j), (i * H_SIZE + j + 1), 3);
                }
                catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }
                try {
                    /*fprintf(stderr, "ddd\n");*/
                    n = mtrx->GetCell(i, j - 1);
                    if (n == '0' || n == 'v' || n == '^' || n == '>')
                        graff->setUndirectedE((i * H_SIZE + j), (i * H_SIZE + j - 1), 1);
                    else if (n == '=')
                        graff->setUndirectedE((i * H_SIZE + j), (i * H_SIZE + j - 1), 3);
                }
                catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }
            }
        }
    }
    return graff;
}

//reads file and stores the tile type at each point
//if dealing with ints for tile tracking is too much then implement Matrix template<T>
Matrix<char>* runner::createMFromFile(FILE* map) {
    //check for file pointer NE nullptr
    if (map == nullptr) perror("Map does not exist\t");

    Matrix<char>* mtrx = new Matrix<char>(H_SIZE, V_SIZE);

    //read the data into content
    rewind(map);
    int i = 0;
    int c;
    while ((c = fgetc(map)) != EOF) {
        mtrx->SetCell(i % H_SIZE, i / H_SIZE, c);
        i++;
    }

    //translate data into matrix

    return mtrx;
}


void runner::initTiles(char** tileData) {
    //some setup for the directories as always
    char* dir = new char[14];

    for (int i = 1; i < 8; i++) {
        sprintf(dir, "gdata/tiles/t%d", i);

        //open and read file into correct position in array
        FILE* tileFile = fopen(dir, "rb");
        if (tileFile == nullptr) perror("The tile file doesnt exist (yet?)\t");

        int jter = 0;
        int c;
        rewind(tileFile);
        while (((c = fgetc(tileFile)) != EOF) && jter < 29) {
            tileData[i - 1][jter] = c;
            jter++;
        }
        fclose(tileFile);
    }
}


void runner::tileprint(Matrix<char>* tiles, char** tileData) {
  #if __linux__
    system("clear");
  #elif _WIN32
    system("CLS");
  #endif
    for (int i = 0; i < H_SIZE; i++) {
        for (int j = 0; j < V_SIZE; j++) {
            //would use switch for readability but not allowed to use break
            //and then we print ending with ,tileData[n] + 12
            //using ansi escape [A for up line and then [C for right on line
            if (tiles->GetCell(i, j) == '#') printf("%.9s ", tileData[0]);
            else if (tiles->GetCell(i, j) == '0') printf("%.9s ", tileData[1]);
            else if (tiles->GetCell(i, j) == '^') printf("%.3s ", tileData[2]);
            else if (tiles->GetCell(i, j) == 'v') printf("%.3s ", tileData[3]);
            else if (tiles->GetCell(i, j) == '>') printf("%.3s ", tileData[4]);
            else if (tiles->GetCell(i, j) == '"') printf("%.3s ", tileData[5]);
            else if (tiles->GetCell(i, j) == '=') printf("%.9s ", tileData[6]);
            else printf("no valid character match found");
        }
        printf("\n");
        for (int j = 0; j < V_SIZE; j++) {
            //would use switch for readability but not allowed to use break
            //and then we print ending with ,tileData[n] + 12
            //using ansi escape [A for up line and then [C for right on line
            if (tiles->GetCell(i, j) == '#') printf("%.9s ", tileData[0] + 9);
            else if (tiles->GetCell(i, j) == '0') printf("%.9s ", tileData[1] + 9);
            else if (tiles->GetCell(i, j) == '^') printf("%.3s ", tileData[2] + 3);
            else if (tiles->GetCell(i, j) == 'v') printf("%.3s ", tileData[3] + 3);
            else if (tiles->GetCell(i, j) == '>') printf("%.3s ", tileData[4] + 3);
            else if (tiles->GetCell(i, j) == '"') printf("%.3s ", tileData[5] + 3);
            else if (tiles->GetCell(i, j) == '=') printf("%.9s ", tileData[6] + 9);
            else printf("no valid character match found");
        }

        printf("\n");
    }
}

//function that calls createfromfile for Matrix and graph
//if pointers don't work then return as enum <graph,Matrix>
void runner::initMap(graph*& connections, Matrix<char>*& tiles, char* fName, char** tileData, int*& entData) {
    //doesnt print unless specified to where
    char* dir = new char[CHARCOUNT + 11];

    entData = new int[50];

    //create tchar because we cant use a string literal casted to a char*
    char* tchar = (char*)"gdata/maps/";

    //remember to remove 'terminating nul'
    sprintf(dir, "gdata/maps/%c%c", fName[0], fName[1]);
    FILE* map = fopen(dir, "r");

    //grab the tiles from the files that define them
    initTiles(tileData);

    //read map into tiles and connections
    tiles = createMFromFile(map);
    tileprint(tiles, tileData);

    connections = createGFromM(tiles,entData);
    fclose(map);

}

runner:: void
void runner::runLoop(graph*& connections, Matrix<char>*& tiles, char** tileData, int*& entData){
  connections = createGFromM(tiles, entData);
  tileprint(tiles,tileData);
  char* inputBuf = new char[4];
  printf("\n\n Press {w,a,s,d} followed by enter to move \n Or press space+enter to skip turn");
  fgets(inputBuf, 4, stdin);
  
  //make matrix into graph
  //print matrix
  //prompt user to move {w,a,s,d} + enter
  //run algo for enemy movement 
  //update matrix with new player Pos and new enemy Pos
}


























