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

   WINDOW *gameWindow = initializeWindow();
   getch();
   clearBoard(gameWindow);
   getch();

   drawMenu(gameWindow);
   getch();

   clearBoard(gameWindow);
   addElement(gameWindow, 'x', 5, 5);
   getch();

   endwin();
   return 0;
}