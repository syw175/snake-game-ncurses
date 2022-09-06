/*
 * Filename: frontend.c
 *
 * Description: Implementation of functions related to the View aspect 
 *              of the snake game in terms of the MVC design pattern.
 * 
 * Author: Steven Wong
 * Last Modified: September 5, 2022
 */


#include "frontend.h"
#include "backend.h"


// DONE
// Allocate memory for a ncurses window and return a pointer to it
WINDOW* initializeWindow(int height, int width, int centreY, int centreX)
{
   // Initialize game board onto the heap
   WINDOW *window = newwin(height, width, centreY, centreX);  // height, width, row location, column location to centre window 

   // Return a pointer to the newly created window
   return window;
}

// NEEDS WORK
void drawMainMenu(void)
{
}

// DONE
// Draw the gameplay instructions onto the screen and return to menu upon pressing 1
void drawInstructionsMenu(void) 
{
   // Initialize the window
   WINDOW *controls_win;  
   int ch;
   controls_win = initializeWindow(10, 30, (LINES - 9) /2, (COLS - 30) /2);
   
   // Enable the keypad for the user's terminal
   keypad(controls_win, TRUE);

   // Print the instructions
   box(controls_win, 0, 0);
   printStringInMiddle(controls_win, 1, 0, 30, "How to Play");
   mvwaddch(controls_win, 2, 0, ACS_LTEE);
   mvwhline(controls_win, 2, 1, ACS_HLINE, 28);
   mvwaddch(controls_win, 2, 29, ACS_RTEE);  
   mvwprintw(controls_win, 3, 1, "Move with the arrows keys");
   mvwprintw(controls_win, 4, 1, "Eat the food to grow.");
   mvwprintw(controls_win, 5, 1, "Food is '#'");

   // Print the controls
   mvwaddch(controls_win, 7, 0, ACS_LTEE);
   mvwhline(controls_win, 7, 1, ACS_HLINE, 28);
   mvwaddch(controls_win, 7, 29, ACS_RTEE);
   wattron(controls_win , A_STANDOUT);
   mvwprintw(controls_win, 8, 11, "* Back");
   wattroff(controls_win ,A_STANDOUT);
   wrefresh(controls_win);

   // Wait for the user to press enter
   while((ch = wgetch(controls_win)) != 10 ) {
   }

   // Clear and delete the window
   wclear(controls_win);
   wrefresh(controls_win);
   delwin(controls_win);
   return;
}

// DONE
// Exit the game 
void exitGame(void)
{
   // Exit the game
   endwin();

   // Exit the program
   exit(0);
   // Function stub: Remove when I have successfully implemented this function
}

// DONE
// Start the main game loop
void startGame(WINDOW *window)
{
   // Initialize variables
   int start_x, start_y, height, width;
   WINDOW *game_win;
   height = 20; width = 50;

   // Get the middle of the screen
   start_y = (LINES - height) / 2;  
   start_x = (COLS - width) / 2;

   // Create a new window
   game_win = initializeWindow(height, width, start_y, start_x);
   gameBoard_t *board = createBoard(width, height);
   status_t status = ALIVE;

   // While the snake is alive, keep playing
   while(status == ALIVE) 
   {
      werase(game_win);
      mvwprintw(window ,start_y - 2, start_x, "Your score: %ld", board -> score);
    
      wrefresh(window);

      if(board -> snake -> direction == RIGHT || board -> snake -> direction == LEFT) 
         timeout(100);
      else  
         timeout(125);

      displayBoard(board, game_win);
      wrefresh(game_win);
      board -> snake -> direction = getDirection(board -> snake -> direction);

      //  If the snake's direction is HOLD, then pause the game
      if(board -> snake -> direction == HOLD) 
      {
         mvwprintw(window ,start_y - 2, start_x + 32, " Game is paused... ");
         continue;
      }
      // Otherwise, indicate to user instructions to pause game
      else
      {
         mvwprintw(window ,start_y - 2, start_x + 32, "Press 'p' to pause ");
      }

      // Move the snake
      status = moveSnake(board);
   }

   // Clear the window
   destroyBoard(board); 
   wclear(game_win); 
   wrefresh(game_win); 

   // Deallocate the memory for the game window
   delwin(game_win);
   return;
}

// DONE
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

// DONE
// Display the snake, food, and score on the screen
void displayBoard(gameBoard_t *board, WINDOW *win)
{
   gameObject_t *head = board->snake;
   // Display the food
  mvwaddch(win, board -> food -> yPosition, board -> food -> xPosition, board -> food -> symbol);

   // Display the snake 
   while(head) 
   {
      mvwaddch(win, head -> yPosition, head -> xPosition, head -> symbol);
      head = head -> next;
   }

   // Display the game borders
   box(win, 0 , 0); 
}

// DONE
// Get the current Direction
// May need to address the case where user does not enter a key at all
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

// DONE
// Get input from user and return a chtype
chtype getInput(WINDOW *board)
{
    // Return the input as a chtype
   return wgetch(board);
}