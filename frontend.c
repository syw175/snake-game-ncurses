/* Program: snake-game in c
   Author: Steven Wong
   Date last modified: May 19, 2022
*/

// will include all the drawing of the snake game onto terminal using the ncurses library 
// ncurses documentation ----->>>>> https://jbwyatt.com/ncurses.html#using

// To Do
// Print menu with the following options: Start game, how to play, high scores 
// Print menu of how to play: Move snake with the arrow keys, Eat the food to grow, Eat the apple to double speed temporarily for 30s and grow events are doubled 
// Print high scores: Retro style just like in the old arcades 
// Draw fruit items randomly within the screen 
// Draw Bonus Item Sportically within the screen 


#include <stdio.h> 
#include <ncurses.h>

// Test creating a window in ncurses
int main(int argc, char **argv) { 
   initscr();  // initialize ncurses
   refresh();  // print onto screen

   // get dimensions of window
   int screenX, screenY;  
   getmaxyx(stdscr, screenY, screenX);
    
   // initialize board in centre of screen
   WINDOW *board_win = newwin(20, 20, (screenY/2)-20/2, (screenX/2)-20/2);  // height, width, row, column to centre window
   box(board_win, '|', '_');  // board, verticalChar, horizontalChar
   wrefresh(board_win);

   getch();  // test only
   endwin(); 

   return 0;
}