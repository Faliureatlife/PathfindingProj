Name: Nick Martinez ID: 301776242
Name: Mathan Ramos ID: 301632215

Files:
├── gdata
│   ├── maps
│   │   ├── All Maps
│   │   ├── identities
│   │   ├── m1
│   │   ├── m2
│   │   ├── m3
│   │   ├── m4
│   │   └── m5
│   └── tiles
│       ├── t1
│       ├── t2
│       ├── t3
│       ├── t4
│       ├── t5
│       ├── t6
│       ├── t7
│       └── TILE INSTRUCTIONS
├── include
│   ├── graph.h
│   ├── matrix.h
│   ├── priorityQ.h
│   ├── queue.h
│   └── runner.h
├── main.cpp
├── Makefile
├── README.md
└── src
    ├── graph.cpp
    ├── matrix.cpp
    ├── priorityQ.cpp
    ├── queue.cpp
    └── runner.cpp

Gameplay:
Player spawns in a maze surrounded by walls with the goal of going to the winwin tile, which ends the game. 
Enemies move towards the player using the Dijkstra Shortest Path Algorithm, and upon reaching the Player the game ends.
Around the map there is Dirt that slows the Player down, as well as Secret Passages that teleports the Player to the Parallel Passage accross the map.
If Player is not caught, the length of the Player's is Displayed at the end. If Player is caught, Enemies Path Length Displayed at the end.
If player moves into a wall tile nothing occurs, but turn ends. During movement if enemies collide, they will be treated as walls, and turn ends for both.

Movement: 
Player uses the W , A , S , and D keys in order to move around the map.
Player can press the space bar to to skip their turn.






