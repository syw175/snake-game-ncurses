/*
 * Filename: frontend.h
 *
 * Description: Function prototypes related to the View aspect 
 *              of the snake game in terms of the MVC design pattern.
 * 
 * Author: Steven Wong
 * Last Modified: August 27, 2022
 */


#include <stdio.h> 
#include <ncurses.h>
#include <string.h>


// Initialize the game board
WINDOW* initializeWindow(); 

// Clear the screen and redraw the borders
void clearBoard(WINDOW *board);


// Draw the main menu information and loop until an option is chosen
void drawMenu(WINDOW *board);

// Draw the gameplay instructions onto the screen and return to menu upon pressing 1
void drawInstructions(WINDOW *board);