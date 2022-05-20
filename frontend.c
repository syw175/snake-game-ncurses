/* Program: snake-game in c
   Author: Steven Wong
   Date last modified: May 19, 2022
*/

// will include all the drawing of the snake game onto terminal using the ncurses library 
// ncurses documentation ----->>>>> https://jbwyatt.com/ncurses.html#using

#include <stdio.h> 
#include <ncurses.h>

// Print menu with the following options: Start game, how to play, high scores 

// Print menu of how to play: Move snake with the arrow keys, Eat the food to grow, Eat the apple to double speed temporarily for 30s and grow events are doubled 


// Print high scores: Retro style just like in the old arcades 




// WINDOW * win = newwin(25, 25, 0, 0)  // nlines, ncols, y0, x0


// Test creating a window in ncurses
int main(void) { 
   initscr();
   addstr("hah \n ahah\n");
   refresh(); 
   getch();
   endwin(); 

   return 0;
}

// Draw fruit items randomly within the screen 



// Draw Bonus Item Sportically within the screen 