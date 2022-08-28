/*
 * Filename: frontend.c
 *
 * Description: Implementation of functions related to the View aspect 
 *              of the snake game in terms of the MVC design pattern.
 * 
 * Author: Steven Wong
 * Last Modified: August 27, 2022
 */

// ncurses documentation ----->>>>> https://jbwyatt.com/ncurses.html#using

   // move the cursor to the specified location, taking 2 parameters y, then x 
   // move(20, 20);  // 

   // mvprintw(0, 0, "hello");

   // get current yx coordinate. Takes parameter of window, and two variables to place the information getyx(stdscr, int y, int x);
   // getyx();   

   // get beginning xy corner coordinate
   // getbegyx();

   // print text in the window at the current position
   // wprintw(menuWin, "This is a window");

   // noecho();   // character from input will not show up 
   // curs_set(0);  // Hide insertion point from the user
   // cbreak();   // removes input buffer, ctrl + c to exit


#include "frontend.h"
#include "backend.h"


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


// Allocate memory for a ncurses window and return a pointer to it
WINDOW* initializeWindow(void)
{
   // Initialize ncurses, sets up memory, and clears the screen
   initscr();  
   clear();
   refresh();

   // Get the dimensions of the client computer's screen
   int screenX, screenY;  
   getmaxyx(stdscr, screenY, screenX);

   // Initialize game board and return it
   WINDOW *window = newwin(screenY, screenX, 0, 0);  // height, width, row location, column location to centre window 

   // Return the window
   return window;
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

// NEEDS WORK
void drawMenu(WINDOW *board)
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

// Draw game instructions onto a game board
void drawInstructions(WINDOW *board) 
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

// Get input from user and return a chtype
chtype getInput(WINDOW *board)
{
   // Validate that board is valid
   if (!board) return;

   // Return the input as a chtype
   return wgetch(board);
}