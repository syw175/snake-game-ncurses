# Snake Game with Ncurses
Welcome to the Snake Game implemented using the Ncurses library! This repository contains a classic version of the Snake game, where the player controls a snake that grows in length as it consumes food items. The game ends if the snake collides with the screen boundary or itself.

# Features
- Classic Snake gameplay
- Use of Ncurses library for terminal-based graphics
- Modular code structure with separate files for backend, frontend, and snake logic

# Getting Started
## Prerequisites
- GCC (GNU Compiler Collection)
- Ncurses library

## Compilation and Execution
1. Clone the repository:
```bash git clone https://github.com/syw175/snake-game-ncurses.git```

2. Navigate to the repository directory:
```bash cd snake-game-ncurses```

3. Compile the source files:
```gcc src/*.c -lncurses -o snake_game```

4. Run the game:
```bash ./snake_game```

# Code Structure
- backend.c: Contains the backend logic for the game.
- frontend.c: Handles the frontend display using the Ncurses library.
- snake.c: Contains the logic for the snake's movement and growth.

# Contributing
Feel free to fork the repository, make changes, and submit a pull request. Any contributions are welcome!
