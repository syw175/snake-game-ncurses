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

typedef enum option_t {
    OPEN, 
    CLOSED
};

// Representation of game objects
typedef struct gameObject_t {
    int xPosition;
    int yPosition;
    char symbol;
    time_t time;
    direction_t direction;
    struct gameObject_t *next;
} gameObject_t;

// Representation of the game board
typedef struct {
    gameObject_t *snake;
    gameObject_t *food;
    int score;
    int maxX;
    int maxY;
    enum option_t option;
} gameBoard_t;

// Create a game object such as a food item or new snake item
gameObject_t *createObject(int xValue, int yValue, char symbol);

// Instiate a snake to start the game 
gameObject_t *createSnake(); 

// Move the snake based on user input and return dead or alive 
status_t moveSnake(gameBoard_t *board); 

// Check if there is the object has collided with the snake 
int isCollision(gameObject_t *object, gameObject_t *snake);

// Generate a random integer between min and max
int randomCoordinate(int min, int max);

// Add food to the board
void addFood(gameBoard_t *board);

// Create a board on the heap 
gameBoard_t* createBoard(int maxX, int maxY, enum option_t option);

// Opposite direction check
int oppositeDirection(gameObject_t *nextHead, gameObject_t *snake); 

// Destroy the board and free any memory associated with the game 
void destroyBoard(gameBoard_t *board);



