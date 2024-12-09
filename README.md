An idiot admires complexity, a genius admires simplicity, a physicist tries to make it simple. Anyway, an idiot, anything the more complicated something is the more he will admire it. If you make something so clusterfucked he can't understand it, he's going to think you are a god because you made it so complicated nobody can understand it. That's how they write journals and academic journals. They try to make it so complicated people think you're a genius. - Terry Davis

git add -A //adds all changed files                      \
git commit -m "message" //adds the commit comment/logs   \
git push //pushes to main                                

Name: Nick Martinez ID: 301776242 \
Name: Mathan Ramos ID: 301632215

Files: \
├── gdata \
│   ├── maps \
│   │   ├── All Maps \
│   │   ├── identities \
│   │   ├── m1 \
│   │   ├── m2 \
│   │   ├── m3 \
│   │   ├── m4 \
│   │   └── m5 \
│   └── tiles \
│       ├── t1 \
│       ├── t2 \
│       ├── t3 \
│       ├── t4 \
│       ├── t5 \
│       ├── t6 \
│       ├── t7 \
│       └── TILE INSTRUCTIONS \
├── include \
│   ├── graph.h \
│   ├── matrix.h \
│   ├── priorityQ.h \
│   ├── queue.h \
│   └── runner.h \
├── main.cpp \
├── Makefile \
├── README.md \
└── src \
    ├── graph.cpp \
    ├── matrix.cpp \
    ├── priorityQ.cpp \
    ├── queue.cpp \
    └── runner.cpp \

Gameplay:
Player spawns in a maze surrounded by walls with the goal of going to the winwin tile, which ends the game. 
Enemies move towards the player using the Dijkstra Shortest Path Algorithm, and upon reaching the Player the game ends.
Around the map there is Dirt that counts as 2 extra moves, reducing the Player's score, after being traversed the player kicks the dirt behind them to make enemies less likely to follow
There are 1-2 Secret Passages that teleports the Player to the Parallel Passage accross the map
If Player is not caught, the length of the Player's is Displayed at the end. If Player is caught, the game ends
If player moves into a wall tile nothing occurs, but turn ends. During movement if enemies collide, they will be treated as walls, and turn ends for both.

Movement: 
Player uses the W , A , S , and D keys in order to move around the map.
Player can press the space bar to to skip their turn.





