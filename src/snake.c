/*
 * Filename: snake.c
 *
 * Description: A rendition of the snake game found on Nokia's 6610.
 * 
 * Author: Steven Wong
 * Last Modified: August 27, 2022
 */


#include <stdio.h> 
#include <stdlib.h> 

#include "frontend.h"
#include "backend.h" 

// create new instance of the game
int main(int argc, char **argv)
{
   // Think about refactoring the screen dimensions X/Y and saving it
   // Currently lots of redunancy in the functions


   // Testing the initialize of a Ncurses window 
   WINDOW *gameWindow = initializeWindow();
   getch();

   // Testing the clearBoard() function
   clearBoard(gameWindow);
   getch();

   // Testing the draw menu function
   drawMenu(gameWindow);
   getch();

   // Testing the add Element function
   clearBoard(gameWindow);
   addElement(gameWindow, 'x', 5, 5);
   getch();

   endwin();
   return 0;
}