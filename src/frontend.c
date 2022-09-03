/*
 * Filename: frontend.c
 *
 * Description: Implementation of functions related to the View aspect 
 *              of the snake game in terms of the MVC design pattern.
 * 
 * Author: Steven Wong
 * Last Modified: August 30, 2022
 */


#include "frontend.h"
#include "backend.h"


// Allocate memory for a ncurses window and return a pointer to it
WINDOW* initializeWindow(int height, int width, int centreY, int centreX)
{
   // Initialize game board onto the heap
   WINDOW *window = newwin(height, width, centreY, centreX);  // height, width, row location, column location to centre window 

   // Return a pointer to the newly created window
   return window;
}

// NEEDS WORK
void drawMainMenu(WINDOW *board)
{
   // Menu Options
   char *menuOptions[] = {"START GAME", "HOW TO PLAY", "LEADERBOARD"};
   int screenX, screenY;  
   int highlighted = 0;

   // Ensure that a valid pointer was given
   if (!board) return;

   // Clear the menu and draw a box 
   clearBoard(board);
   keypad(board, true);

   // Get the dimensions of the client computer's screen
   getmaxyx(stdscr, screenY, screenX);

   // Print the options to the screen and allow navigation through the menu
   mvwprintw(board, screenY/3, screenX/3, "WELCOME TO SNAKE GAME!");
   while(true) {
      for (int i = 0; i < 3; i++) { 
         if(i == highlighted) { 
            wattron(board, A_REVERSE);
         }

         mvwprintw(board, screenY/2+i+1, screenX/3, menuOptions[i]);
         wattroff(board, A_REVERSE);
      }
      int userInput = wgetch(board);

      switch (userInput)
      {
         case KEY_UP:
            if (highlighted > 0) { 
               highlighted--;
            }
            break;
         case KEY_DOWN:  
            if (highlighted < 2) {
               highlighted++;
            } 
            break;
         default:
            break;
      }

      // If "Enter" is pressed.. break out of the menu
      if (userInput == 10) { 
         break;
      }
   }
}

// Draw the gameplay instructions onto the screen and return to menu upon pressing 1
void drawInstructionsMenu(WINDOW *board) 
{
   // Ensure that a valid pointer was given
   if (!board) return;

   // Initialize instructions screen
   // int yMax, xMax; 
   // getyx(stdscr, yMax, xMax);

   // Clear the screen 
   clearBoard(board);

   // char *gameInstructions[] = {"HOW TO PLAY",
   //                      "1. MOVE WITH THE ARROW KEYS", 
   //                      "2. EAT THE FOOD (#) TO GROW",
   //                      "3. BONUS ITEM DOUBLES FOOD AND SPEED FOR 60SEC",
   //                      "PRESS ESC TO RETURN"};
}

// Draw the historical record of highscores located in the current directory
// Function stub: Remove when I have successfully implemented this function
void drawHighScoresMenu(WINDOW *board)
{
   // Function stub: Remove when I have successfully implemented this function]
   return;
}

// Clear the board and redraw the borders
void clearBoard(WINDOW *board)
{
   // Ensure that a valid pointer was given
   if (!board) return; 

   // Clear the board and draw a box around the board using the default characters
   clear();
   box(board, 0, 0);  
   refresh();
}

// Exit the game 
void exitGame(void)
{
   // Function stub: Remove when I have successfully implemented this function
   return;
}

// Start the main game loop
void startGame(WINDOW *board)
{
   // Function stub: Remove when I have successfully implemented this function
   return;
}

// Function adapted from the Ncurses HOW-TO page
// Source: https://github.com/nasciiboy/NCURSES-Programming-HOWTO/blob/master/ncurses_programs/JustForFun/tt.c
void printStringInMiddle(WINDOW *win, int startY, int startX, int width, char* string)
{
   // Initialize variables
	int length, x, y;
	float temp;

   // If win is NULL, set win to the standard screen
	if(win == NULL) win = stdscr;

   // Get the current x and y coordinates
	getyx(win, y, x);

   // If startX does not equal 0, then use the given startX
	if(startX != 0) x = startX;
   // If startY does not equal 0, then use the given startY
	if(startY != 0) y = startY;
   // If the width is 0, then set a default width of 80
   if(width == 0) width = 80;

   // Calculate the length of the string and the x coordinate to center the string
	length = strlen(string);
	temp = (width - length)/ 2;
	x = startX + (int)temp;

   // Print the string to the screen
	mvwprintw(win, y, x, "%s", string);

   // Refresh the screen
	refresh();
}


void print_in_middle(int startx, int starty, int width, char *string, WINDOW *win)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}

// Get the current Direction
// May need to address the case where user does not enter a key at all
// Untested
direction_t getDirection(direction_t currentDirection)
{
   int userInput = getch();

   // If the user presses the up arrow key, then return UP
   if (userInput == KEY_UP) {
      return UP;
   }
   // If the user presses the down arrow key, then return DOWN
   else if (userInput == KEY_DOWN) {
      return DOWN;
   }
   // If the user presses the left arrow key, then return LEFT
   else if (userInput == KEY_LEFT) {
      return LEFT;
   }
   // If the user presses the right arrow key, then return RIGHT
   else if (userInput == KEY_RIGHT) {
      return RIGHT;
   }
   // If the user presses the escape key, then return HOLD
   else if (userInput == 27) {
      return HOLD;
   }
   // If the user presses any other key, then return the current direction
   else {
      return currentDirection;
   }

}

// Refresh the board and display its contents
void refreshBoard(board_t *board, WINDOW *win)
{
   // Function stub: Remove when I have successfully implemented this function
   return;
}

// Get input from user and return a chtype
chtype getInput(WINDOW *board)
{
    // Return the input as a chtype
   return wgetch(board);
}

// Add element at a given position on the board
void addElement(WINDOW *board, char element, int xPosition, int yPosition)
{
   // Ensure that a valid pointer was given
   if (!board) return;

   // Get the dimensions of the client computer's screen
   int screenX, screenY;  
   getmaxyx(stdscr, screenY, screenX);

   // Check that the position is in range 
   if (xPosition > screenX || yPosition > screenY) return;
   if (xPosition < 0 || yPosition < 0) return;

   // Add the character at the position
   mvaddch(yPosition, xPosition, element);
}