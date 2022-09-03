/*
 * Filename: snake.c
 *
 * Description: A rendition of the snake game found on Nokia's 6610.
 * 
 * Author: Steven Wong
 * Last Modified: August 30, 2022
 */


#include <stdio.h> 
#include <stdlib.h> 

#include "frontend.h"
#include "backend.h" 

// create new instance of the game
int main(int argc, char **argv)
{
   initscr();
   cbreak();
   noecho();


   // Testing the initialize of a Ncurses window 
   // WINDOW *gameWindow = initializeWindow(60, 60, 0, 0);
   // getch();

   // // Testing the clearBoard() function
   // clearBoard(gameWindow);
   // getch();

   // // Testing the draw menu function
   // drawMainMenu(gameWindow);
   // getch();

   // // Testing the add Element function
   // clearBoard(gameWindow);

   // Create a new window 
   WINDOW *gameWindow = initializeWindow(500, 500, 0, 0);
   // Testing the print string in middle function

   // Why does the text not show when I pass in gameWindow as the first argument?
   printStringInMiddle(gameWindow, 10, 10, 60, "WELCOME TO SNAKE GAME!");
   printStringInMiddle(NULL, 1, 0, 20, "Hello World");


   getchar();  
   getch();

   return 0;
}