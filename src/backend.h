// Function prototypes for backend 

#include <time.h> 
#include <stdio.h> 
#include <stdlib.h> 

typedef enum direction_t {
    UP, 
    DOWN, 
    LEFT, 
    RIGHT
} direction_t; 

typedef enum status_t {
    ALIVE,
    DEAD
} status_t; 

// typedef struct 
// {
//     int xPosition;
//     int yPosition;
//     char *next;
// }

// Get the current game status 
status_t getGameStatus();

// Check if two objects are in the same place 








