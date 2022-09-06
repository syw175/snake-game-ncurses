/*
 * Filename: frontend.h
 *
 * Description: Function prototypes related to the View aspect 
 *              of the snake game in terms of the MVC design pattern.
 * 
 * Author: Steven Wong
 * Last Modified: September 5, 2022
 */

#include <unistd.h>
#include <stdlib.h>
#include <panel.h> 
#include <menu.h>
#include <stdio.h> 
#include <ncurses.h>
#include <string.h>

#include "backend.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

// Initialize the game board onto the heap and return a pointer to it
WINDOW* initializeWindow(int height, int width, int centreY, int centreX); 

// Draw the main menu information and loop until an option is chosen
void drawMainMenu(void);

// Draw the gameplay instructions onto the screen and return to menu upon pressing 1
void drawInstructionsMenu(void);

// Exit the game 
void exitGame(void);

// Start the main game loop
void startGame(WINDOW *board);

// Print a string in the middle of the window
void printStringInMiddle(WINDOW *win, int startY, int startX, int width, char* string);

// Display the snake, food, and score on the screen
void displayBoard(gameBoard_t *board, WINDOW *win);

// Get the direction of the snake from the user
direction_t getDirection(direction_t current_direction);

// Get input from user and return a chtype
chtype getInput(WINDOW *board);