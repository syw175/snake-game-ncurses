/* Program: snake-game in c
   Author: Steven Wong
   Date last modified: May 18, 2022
*/

// will include all the drawing of the snake game onto terminal using the ncurses library 
// ncurses documentation ----->>>>> https://jbwyatt.com/ncurses.html#using

#include <stdio.h> 
#include <ncurses.h>

WINDOW * win = newwin(25, 25, 0, 0)  // nlines, ncols, y0, x0