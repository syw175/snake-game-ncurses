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

   // move the cursor to the specified location, taking 2 parameters y, then x 
   // move(20, 20);  // 

   // prints a string (const char *) to a window 
   // printw("Hello World");

   // moveprint : combines move and print together into one command
   // mvprintw(0, 0, "hello");

   // get current yx coordinate. Takes parameter of window, and two variables to place the information getyx(stdscr, int y, int x);
   // getyx();   

   // get beginning xy corner coordinate
   // getbegyx();

   // print text in the window at the current position
   // wprintw(menuWin, "This is a window");


int main(int argc, char **argv) { 

   // NCURSES START 
   initscr();  // initialize ncurses, sets up memory, and clears the screen
   noecho();   // character from input will not show up 
   cbreak();  
   refresh();  // refresh screen to match what is in memory

   // clears the screen
   clear();

   // get dimensions of window
   int screenX, screenY;  
   getmaxyx(stdscr, screenY, screenX);
    


   // initialize board in centre of screen
   // new pointer to new window named menuWin
   WINDOW *menuWin = newwin(screenY, screenX, 0, 0);  // height, width, row location, column location to centre window
   refresh();


   // board, verticalChar, horizontalChar... also takes the int representation of the key. I.e. 103 = g char
   box(menuWin, '|', '_');  

   mvprintw(screenY/3, screenX/3, "Welcome to Snake Game!");


   string menuOptions[3] = {
      "START GAME"
      "HOW TO PLAY"
      "SCORE BOARD"
   };

   int choice;
   int highlight = 0;

   for (int i = 0; i < MENUOPTIONS; i++) { 
      mvprintw(menuWin, posy+i+5, posx+i+5, menuOptions[i].c_str());
      wrefresh(menuWin);
   }


   wrefresh(menuWin);  // update box to reflect what is in memory

   // allow ncurses to take function keys and arrow keys
   keypad(menuWin, true);



   // int c = getch();  // get char... waits for user input, returns int value of that key...
   // printw("%d", c);

   // int c = wgetch(inputwin);
   // if (c==KEY_UP) { 
      // do something
   // }

   getch();

   
   // NCURSES END
   endwin();  //deallocates memory and ends ncurses...

   return 0;
}