/*
 * Filename: backend.h
 *
 * Description: Function prototypes related to the Model and 
 *              Controller aspect of the snake game in terms of the 
 *              MVC design pattern.
 * 
 * Author: Steven Wong
 * Last Modified: August 27, 2022
 */

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








