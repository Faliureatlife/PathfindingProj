
#include "../include/runner.h"

graph* runner::createGFromM(Matrix<char>* mtrx, int* entPos) {
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
            c = mtrx->GetCell(i, j);
            if ( c == '0' || c == 'v' || c == '^' || c == '=' || c == '>') {
                if (c == 'v') {
                  entPos[1+ecnt] = (i * V_SIZE + j);
                  ecnt++;
                } else if(c == '^'){
                    entPos[0] = (i * H_SIZE + j);
                }
                    //add catch
                  try {
                      (n = mtrx->GetCell(i - 1, j ));
                        /*fprintf(stderr, "aaa (%d,%d) to  (%d, %d), or at %d in the graph\n",i,j,i-1, j+k, ((i-1) * H_SIZE) + j + k);*/
                        //(i-1*H_SIZE) - j + k should give the output 
                      if (n == '0' || n == 'v' || n == '^' || n == '>')
                          graff->setUndirectedE((i * V_SIZE + j), ((i - 1) * V_SIZE + j), 1);
                      else if (n == '=')
                          graff->setUndirectedE((i * V_SIZE + j), ((i - 1) * V_SIZE + j), 3);
                    }
                  catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }
                  try {
                      /*fprintf(stderr, "bbb %d,%d\n",i+1,j+k);*/
                      (n = mtrx->GetCell(i + 1, j));
                      if (n == '0' || n == 'v' || n == '^' || n == '>')
                          graff->setUndirectedE((i * V_SIZE + j), ((i + 1) * V_SIZE + j), 1);
                      else if (n == '=')
                          graff->setUndirectedE((i * V_SIZE + j), ((i + 1) * V_SIZE + j), 3);
                  }
                  catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }
                try {
                    /*fprintf(stderr, "ccc\n");*/
                    n = mtrx->GetCell(i, j + 1);
                    if (n == '0' || n == 'v' || n == '^' || n == '>')
                        graff->setUndirectedE((i * V_SIZE + j), (i * V_SIZE + j + 1), 1);
                    else if (n == '=')
                        graff->setUndirectedE((i * V_SIZE + j), (i * V_SIZE + j + 1), 3);
                }
                catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }
                try {
                    /*fprintf(stderr, "ddd\n");*/
                    n = mtrx->GetCell(i, j - 1);
                    if (n == '0' || n == 'v' || n == '^' || n == '>')
                        graff->setUndirectedE((i * V_SIZE + j), (i * V_SIZE + j - 1), 1);
                    else if (n == '=')
                        graff->setUndirectedE((i * V_SIZE + j), (i * V_SIZE + j - 1), 3);
                }
                catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }
            }
        }
    }
    return graff;
}

graph* runner::createGFromM2(Matrix<char>* mtrx, int* entPos) {
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
            c = mtrx->GetCell(i, j);
            if ( c == '0' || c == 'v' || c == '^' || c == '=' || c == '>') {
                if (c == 'v') {
                  entPos[1+ecnt] = (i * V_SIZE + j);
                  ecnt++;
                } else if(c == '^'){
                    entPos[0] = (i * H_SIZE + j);
                }
                    //add catch
                  try {
                      (n = mtrx->GetCell(i - 1, j ));
                        /*fprintf(stderr, "aaa (%d,%d) to  (%d, %d), or at %d in the graph\n",i,j,i-1, j+k, ((i-1) * H_SIZE) + j + k);*/
                        //(i-1*H_SIZE) - j + k should give the output 
                      if (n == '0' || n == '^' || n == '>')
                          graff->setUndirectedE((i * V_SIZE + j), ((i - 1) * V_SIZE + j), 1);
                      else if (n == '=')
                          graff->setUndirectedE((i * V_SIZE + j), ((i - 1) * V_SIZE + j), 3);
                    }
                  catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }
                  try {
                      /*fprintf(stderr, "bbb %d,%d\n",i+1,j+k);*/
                      (n = mtrx->GetCell(i + 1, j));
                      if (n == '0' || n == '^' || n == '>')
                          graff->setUndirectedE((i * V_SIZE + j), ((i + 1) * V_SIZE + j), 1);
                      else if (n == '=')
                          graff->setUndirectedE((i * V_SIZE + j), ((i + 1) * V_SIZE + j), 3);
                  }
                  catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }
                try {
                    /*fprintf(stderr, "ccc\n");*/
                    n = mtrx->GetCell(i, j + 1);
                    if (n == '0' || n == '^' || n == '>')
                        graff->setUndirectedE((i * V_SIZE + j), (i * V_SIZE + j + 1), 1);
                    else if (n == '=')
                        graff->setUndirectedE((i * V_SIZE + j), (i * V_SIZE + j + 1), 3);
                }
                catch (std::exception& e) { std::cout << "exception: " << e.what() << std::endl; }
                try {
                    /*fprintf(stderr, "ddd\n");*/
                    n = mtrx->GetCell(i, j - 1);
                    if (n == '0' || n == '^' || n == '>')
                        graff->setUndirectedE((i * V_SIZE + j), (i * V_SIZE + j - 1), 1);
                    else if (n == '=')
                        graff->setUndirectedE((i * V_SIZE + j), (i * V_SIZE + j - 1), 3);
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
    system("clear -x"); //look man i use linux okay
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
    
    //if its annoying use memcpy

    //create tchar because we cant use a string literal casted to a char*
    char* tchar = (char*)"gdata/maps/";

    //remember to remove 'terminating nul'
    sprintf(dir, "gdata/maps/%c%c", fName[0], fName[1]);
    FILE* map = fopen(dir, "r");

    //grab the tiles from the files that define them
    initTiles(tileData);

    //read map into tiles and connections
    tiles = createMFromFile(map);
    
    entData = new int[4];

    connections = createGFromM(tiles,entData);
}

//will need to sum up weight of movement and return score
int runner::moveEnt(Matrix<char>*& tiles, Matrix<char>*& tiles2, int* endIndic, char entType, int i1, int j1, int i2, int j2){
  int score = 0;
  if(i1 >= H_SIZE || i2 >= H_SIZE || j1 >= V_SIZE || j2 >= V_SIZE)
    fprintf(stderr, "Invalid move position: Tried to move from (%d,%d) to (%d,%d) \n", i1,j1,i2,j2);

  int c = tiles->GetCell(i2,j2);
  int h;
  if (c == '0') {//if moving onto empty
    tiles->SetCell(i2,j2,entType);//set the empty to the type
    tiles->SetCell(i1,j1,'0');//then set it to empty 
    score = 1;
  } else if (c == '=') {
    tiles->SetCell(i2,j2,entType);
    if((h = tiles->GetCell(i1,j1)) == '^' || h == 'v'){
      tiles->SetCell(i1,j1,'=');
    }
    score = 3;
  } else if (c == '>'){
    *endIndic = 1;
  } else if (c == '"' && entType == '^'){
    if (i1 == 1) {
      tiles->SetCell(17,j2,entType);
      tiles->SetCell(i1,j1,'0');
    }else if (i1 == 17) {
      tiles->SetCell(1,j2,entType);
      tiles->SetCell(i1,j1,'0');
    }
    score = 2;
  }
  if (entType == 'v' && c == '^') *endIndic = -1;
  return score;
}

void runner::runLoop(graph*& connections, Matrix<char>*& tiles, char** tileData, int*& entData, int mode){
  if (mode == '1'){
    Matrix<char>* m2(tiles);
    int endIndic = 0;
    int score = 0;
    //should only need to be double*[3] but on windows results in access violation
    //therefore we give windows a double*[SIZE] because thats what works (unclear why)
    #if __linux__
      double** dist = new double*[3];
      for(int i = 0; i < SIZE; i++) dist[i] = new double[SIZE];
      int** pred = new int*[3];
      for(int i = 0; i < SIZE; i++) pred[i] = new int[SIZE];
    #elif _WIN32
      double** dist = new double*[SIZE];
      for(int i = 0; i < SIZE; i++) dist[i] = new double[SIZE];
      int** pred = new int*[SIZE];
      for(int i = 0; i < SIZE; i++) pred[i] = new int[SIZE];
    #endif


    //if win then 1, if lose then -1
    while (endIndic == 0){
      tileprint(tiles,tileData);
      //2 bc windows terminal is 2 bytes (char is one byte)
      char* inputBuf = new char[2];
      printf("\n\n Press {w,a,s,d} followed by enter to move or q to Quit \n Or press space+enter to skip turn\033[34D\n\n Your move:");
      fgets(inputBuf, sizeof(inputBuf), stdin);
      //make sure H and V aren't swapped 
      if(inputBuf[0] == 'w') score += moveEnt(tiles, m2, &endIndic, '^', entData[0] / H_SIZE, entData[0] % H_SIZE, (entData[0] / H_SIZE) - 1, (entData[0] % H_SIZE));
      else if(inputBuf[0] == 's') score += moveEnt(tiles, m2, &endIndic, '^', entData[0] / H_SIZE, entData[0] % H_SIZE, (entData[0] / H_SIZE) + 1, (entData[0] % H_SIZE));
      else if(inputBuf[0] == 'a') score += moveEnt(tiles, m2, &endIndic, '^', entData[0] / H_SIZE, entData[0] % H_SIZE, (entData[0] / H_SIZE), (entData[0] % H_SIZE) - 1);
      else if(inputBuf[0] == 'd') score += moveEnt(tiles, m2, &endIndic, '^', entData[0] / H_SIZE, entData[0] % H_SIZE, (entData[0] / H_SIZE), (entData[0] % H_SIZE + 1));
      else if(inputBuf[0] == 'q') endIndic = -1;
      //entData enemies are 1..3, dist & pred are double[double[]] and int[int[]]
      //pred might be removable
      for(int i = 1; i < 4; i++){
        connections->dijkstra(entData[i],dist[i-1],pred[i-1]);
        for (int j = 0; j < 20; j++)
          connections->dijkstraPost(entData[i],dist[i-1],pred[i-1]);
      }
      printf("\n");
      //print out enemy locations
      connections = createGFromM(tiles, entData);

      for (int i = 1; i < 4; i++){
        //math underneath, disregard
        //(x - (x % 19)) / i = j
        //x = entData[0]
        //good is x = (i * 20) + j
        //x = (i * 20) + (x - (x % ))
        int cursor = ((( entData[0] - (entData[0] % H_SIZE)) / H_SIZE) * V_SIZE) + ( entData[0] % H_SIZE );
        int timeoutCount = 0;
        while (cursor != -1 &&  pred[i - 1][cursor] != entData[i] && timeoutCount < SIZE) {
          /*printf("trying to reach %d:  %d --> %d\n",entData[i], cursor, pred[i-1][cursor]);*/

		  cursor = pred[i - 1][cursor];
          timeoutCount++;
        }
        //check to make sure exit was due to finding end and not due to timeout
        /*for( int z = 0 ; z < 20;z++) {for (int q = 0; q < 19; q++){ printf("%d " ,dist[i][(z * 20) + q]); }printf("\n\n");}*/
        if (timeoutCount < SIZE){
          /*printf("Trying to move from (%d,%d) to (%d,%d)\n", entData[i] / V_SIZE, entData[i] % V_SIZE, cursor / V_SIZE, cursor % V_SIZE);*/
          moveEnt(tiles, m2, &endIndic, 'v', entData[i] / V_SIZE, entData[i] % V_SIZE, cursor / V_SIZE, cursor % V_SIZE);
        } /*else { 
          fprintf(stderr, "timeout \n");
          for( int z = 0 ; z < 20;z++) {for (int q = 0; q < 19; q++){ printf("%d  " ,pred[i-1][(z * 20) + q]); }printf("\n\n");}
        } */

      }
      inputBuf[0] = ' ';
      printf("\n");

    }
    if (endIndic == 1) printf("Good job on completing the trial, you did it!                      \nScore(Lower is better): %d\n", score);
    else printf("You got caught by an enemy ... better luck next time!");

  } else if (mode == '2'){ 
    Matrix<char>* m2(tiles);
    int endIndic = 0;
    int score = 0;
    //should only need to be double*[3] but on windows results in access violation
    //therefore we give windows a double*[SIZE] because thats what works (unclear why)
    #if __linux__
      double** dist = new double*[3];
      for(int i = 0; i < SIZE; i++) dist[i] = new double[SIZE];
      int** pred = new int*[3];
      for(int i = 0; i < SIZE; i++) pred[i] = new int[SIZE];
    #elif _WIN32
      double** dist = new double*[SIZE];
      for(int i = 0; i < SIZE; i++) dist[i] = new double[SIZE];
      int** pred = new int*[SIZE];
      for(int i = 0; i < SIZE; i++) pred[i] = new int[SIZE];
    #endif

    connections = createGFromM2(tiles, entData);
    //if win then 1, if lose then -1
    while (endIndic == 0){
      tileprint(tiles,tileData);
      //2 bc windows terminal is 2 bytes (char is one byte)
      char* inputBuf = new char[2];
      printf("\n\n Press {w,a,s,d} followed by enter to move or q to Quit \n Or press space+enter to skip turn\033[34D\n\n Your move:");
      fgets(inputBuf, sizeof(inputBuf), stdin);
      //make sure H and V aren't swapped 
      if(inputBuf[0] == 'w') score += moveEnt(tiles, m2, &endIndic, '^', entData[0] / H_SIZE, entData[0] % H_SIZE, (entData[0] / H_SIZE) - 1, (entData[0] % H_SIZE));
      else if(inputBuf[0] == 's') score += moveEnt(tiles, m2, &endIndic, '^', entData[0] / H_SIZE, entData[0] % H_SIZE, (entData[0] / H_SIZE) + 1, (entData[0] % H_SIZE));
      else if(inputBuf[0] == 'a') score += moveEnt(tiles, m2, &endIndic, '^', entData[0] / H_SIZE, entData[0] % H_SIZE, (entData[0] / H_SIZE), (entData[0] % H_SIZE) - 1);
      else if(inputBuf[0] == 'd') score += moveEnt(tiles, m2, &endIndic, '^', entData[0] / H_SIZE, entData[0] % H_SIZE, (entData[0] / H_SIZE), (entData[0] % H_SIZE + 1));
      else if(inputBuf[0] == 'q') endIndic = -1;
      //entData enemies are 1..3, dist & pred are double[double[]] and int[int[]]
      //pred might be removable
      for(int i = 1; i < 4; i++){
        connections->dijkstra(entData[i],dist[i-1],pred[i-1]);
        for (int j = 0; j < 20; j++)
          connections->dijkstraPost(entData[i],dist[i-1],pred[i-1]);
      }
      printf("\n");
      //print out enemy locations
      connections = createGFromM2(tiles, entData);

      for (int i = 1; i < 4; i++){
        //math underneath, disregard
        //(x - (x % 19)) / i = j
        //x = entData[0]
        //good is x = (i * 20) + j
        //x = (i * 20) + (x - (x % ))
        int cursor = ((( entData[0] - (entData[0] % H_SIZE)) / H_SIZE) * V_SIZE) + ( entData[0] % H_SIZE );

        int timeoutCount = 0;
        while(pred[i-1][cursor] != entData[i] && timeoutCount < SIZE){
          /*printf("trying to reach %d:  %d --> %d\n",entData[i], cursor, pred[i-1][cursor]);*/
          
          cursor = pred[i-1][cursor];
          timeoutCount++;
        }
        //check to make sure exit was due to finding end and not due to timeout
        /*for( int z = 0 ; z < 20;z++) {for (int q = 0; q < 19; q++){ printf("%d " ,dist[i][(z * 20) + q]); }printf("\n\n");}*/
        if (timeoutCount < SIZE){
          /*printf("Trying to move from (%d,%d) to (%d,%d)\n", entData[i] / V_SIZE, entData[i] % V_SIZE, cursor / V_SIZE, cursor % V_SIZE);*/
          moveEnt(tiles, m2, &endIndic, 'v', entData[i] / V_SIZE, entData[i] % V_SIZE, cursor / V_SIZE, cursor % V_SIZE);
        } /*else { 
          fprintf(stderr, "timeout qwq\n");
          for( int z = 0 ; z < 20;z++) {for (int q = 0; q < 19; q++){ printf("%d  " ,pred[i-1][(z * 20) + q]); }printf("\n\n");}
        } */

      }
      inputBuf[0] = ' ';
      printf("\n");

    }
    if (endIndic == 1) printf("Good job on completing the trial, you did it!                      \nScore(Lower is better): %d\n", score);
    else printf("You got caught by an enemy ... better luck next time!");
  }
  

  //make matrix into graph
  //print matrix
  //prompt user to move {w,a,s,d} + enter
  //run algo for enemy movement 
  //update matrix with new player Pos and new enemy Pos
}

