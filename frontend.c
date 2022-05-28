/* Program: snake-game in c
   Author: Steven Wong
   Date last modified: May 19, 2022
*/

// ncurses documentation ----->>>>> https://jbwyatt.com/ncurses.html#using

// To Do
// Print menu of how to play: Move snake with the arrow keys, Eat the food to grow, Eat the apple to double speed temporarily for 30s and grow events are doubled 
// Print high scores: Retro style just like in the old arcades 
// Draw fruit items randomly within the screen 
// Draw Bonus Item Sportically within the screen 


#include <stdio.h> 
#include <ncurses.h>
#include <string.h>


   // move the cursor to the specified location, taking 2 parameters y, then x 
   // move(20, 20);  // 

   // mvprintw(0, 0, "hello");

   // get current yx coordinate. Takes parameter of window, and two variables to place the information getyx(stdscr, int y, int x);
   // getyx();   

   // get beginning xy corner coordinate
   // getbegyx();

   // print text in the window at the current position
   // wprintw(menuWin, "This is a window");

   // // clears the screen
   // clear();

   // int c = getch();  // get char... waits for user input, returns int value of that key...
   // printw("%d", c);

   // int c = wgetch(inputwin);
   // if (c==KEY_UP) { 
      // do something
   // }


   // halfdelay(int tenths of sec) -> prevents infinite buffering for getch(); returns -1 or ERR if no input is given...


void mainMenu() { 

   // Ncurses start 
   clear();
   initscr();  // initialize ncurses, sets up memory, and clears the screen
   noecho();   // character from input will not show up 
   cbreak();   // removes input buffer, ctrl + c to exit
   curs_set(0);  // Hide insertion point from the user

   // Get dimensions of screen
   int screenX, screenY;  
   getmaxyx(stdscr, screenY, screenX);

   // Initialize game board
   WINDOW *menuWin = newwin(screenY, screenX, 0, 0);  // height, width, row location, column location to centre window
   refresh();
   box(menuWin, 0, 0);  

   /* To do: 
   
   Print snake shape for main menu

   */

   mvwprintw(menuWin, screenY/3, screenX/3, "WELCOME TO SNAKE GAME!");
   keypad(menuWin, true);

   char *menuOptions[] = {"START GAME", "HOW TO PLAY", "LEADERBOARD"};
   int highlighted = 0;

   while(true) {
      for (int i = 0; i < 3; i++) { 
         if(i == highlighted) { 
            wattron(menuWin, A_REVERSE);
         }

         mvwprintw(menuWin, screenY/2+i+1, screenX/3, menuOptions[i]);
         wattroff(menuWin, A_REVERSE);
      }
      int userInput = wgetch(menuWin);

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

      if (userInput == 10) { 
         break;
      }
   }

   // NCURSES END
   endwin();  //deallocates memory and ends ncurses...
}

void instructionsMenu(void) { 

   initscr();
   noecho();
   cbreak();

   // Initialize instructions screen
   int yMax, xMax; 
   getyx(stdscr, yMax, xMax);

   // int height, int width, int starty, int startx
   WINDOW *instructionsMenu = newwin(yMax, xMax, 0, 0);
   refresh();
   box(instructionsMenu, 0, 0);
   wrefresh(instructionsMenu);


   char *gameInstructions[] = {"HOW TO PLAY",
                        "1. MOVE WITH THE ARROW KEYS", 
                        "2. EAT THE FOOD (#) TO GROW",
                        "3. BONUS ITEM DOUBLES FOOD AND SPEED FOR 60SEC",
                        "PRESS ESC TO RETURN"};


   // int listSize = sizeof(gameInstructions) / gameInstructions[0];
   // for (int i = 0; i < gameInstructions)

   
   getch();
}

int main(int argc, char **argv) { 
   mainMenu();   

   return 0;
}


