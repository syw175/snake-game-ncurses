/*
 * Filename: frontend.h
 *
 * Description: Function prototypes related to the View aspect 
 *              of the snake game in terms of the MVC design pattern.
 * 
 * Author: Steven Wong
 * Last Modified: August 30, 2022
 */

#include <unistd.h>
#include <stdlib.h>
#include <panel.h> 
#include <menu.h>
#include <stdio.h> 
#include <ncurses.h>
#include <string.h>


// Initialize the game board onto the heap and return a pointer to it
WINDOW* initializeWindow(int height, int width, int centreY, int centreX); 

// Draw the main menu information and loop until an option is chosen
void drawMainMenu(WINDOW *board);

// Draw the gameplay instructions onto the screen and return to menu upon pressing 1
void drawInstructionsMenu(WINDOW *board);

// Draw the historical record of highscores located in the current directory
void drawHighScoresMenu(WINDOW *board);

// Clear the screen and redraw the borders
void clearBoard(WINDOW *board);

// Exit the game 
void exitGame(void);

// Start the main game loop
void startGame(WINDOW *board);

// Print a string in the middle of the window
void printStringInMiddle(WINDOW *win, int startY, int startX, int width, char* string);

// Get the current Direction
// enum direction_t getDirection(enum direction_t currentDirection);

// Refresh the board and display its contents
// void refreshBoard(enum board_t *board, WINDOW *win);

// Get input from user and return a chtype
chtype getInput(WINDOW *board);

// Add element at a given position on the board
void addElement(WINDOW *board, char element, int xPosition, int yPosition);