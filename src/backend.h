/*
 * Filename: backend.h
 *
 * Description: Function prototypes related to the Model and 
 *              Controller aspect of the snake game in terms of the 
 *              MVC design pattern.
 * 
 * Author: Steven Wong
 * Last Modified: August 30, 2022
 */


typedef enum direction_t {
    UP, 
    DOWN, 
    LEFT, 
    RIGHT,
    HOLD
} direction_t; 

typedef enum status_t {
    ALIVE,
    DEAD
} status_t; 

// Struct to represent game objects with an (x,y) coordinate in the game
typedef struct gameObject_t {
    int xPosition;
    int yPosition;
    char symbol;
    direction_t direction;
    struct gameObject_t *next;
} gameObject_t;


// Struct to represent the game board 
typedef struct {
    gameObject_t *snake;
    gameObject_t *food;
    int maxX;
    int maxY;
    int score;
    status_t gameStatus; 

} board_t;


// Create a game object such as a food item or new snake item
gameObject_t *createObject(int xValue, int yValue, char symbol);

// Instiate a snake to start the game 
gameObject_t *createSnake(); 

// Move the snake based on user input and return dead or alive 
status_t moveSnake(board_t *board); 

// Check if there is the object has collided with the snake 
int isCollision(gameObject_t *object, gameObject_t *snake);

// Generate a random integer between min and max
int randomCoordinate(int min, int max);

// Add food to the board
void addFood(board_t *board);

// Create a board on the heap 
board_t* createBoard(int maxX, int maxY);

// Opposite direction check
// May not need
int oppositeDirection(gameObject_t *next, gameObject_t *snake); 

// Destroy the board and free any memory associated with the game 
void destroyBoard(board_t *board);



