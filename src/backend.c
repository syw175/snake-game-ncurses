/*
 * Filename: backend.c
 *
 * Description: Implementation of functions related to the Model and 
 *              Controller aspect of the snake game in terms of the 
 *              MVC design pattern.
 * 
 * Author: Steven Wong
 * Last Modified: September 3, 2022
 */


#include<stdio.h> 
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h> 

#include "backend.h"
#include "frontend.h" // May not need here 

// Create an object on the heap
gameObject_t *createObject(int xValue, int yValue, char symbol)
{
    gameObject_t *newObject = malloc(sizeof(gameObject_t));
    
    // If malloc failed, return NULL
    if (!newObject) return NULL; 

    // Set the coordinates and symbol of the new object 
    newObject->xPosition = xValue;
    newObject->yPosition = yValue;
    newObject->symbol = symbol; 

    // Return it
    return newObject;
}


// Instantiate a new snake for the game
gameObject_t *createSnake()
{
    // Create the initial snake with 3 component 
    gameObject_t *head = createObject(1, 4, 'x');
    gameObject_t *mid = createObject(1, 3, 'o');
    gameObject_t *tail = createObject(1, 2, 'o'); 

    // Ensure that memory was correctly allocated before proceeding
    if (!head || !mid || !tail) return NULL;

    // Set the pointrs and directions for each component
    head->direction = LEFT; 
    mid->direction = LEFT;
    tail->direction = LEFT; 

    // Link the components of the snake 
    head->next = mid;
    mid->next = tail;
    tail->next = NULL;

    // Return a pointer to the head of the snake
    return head;
}

// Move the snake based on user input
// TO DO LATER
status_t moveSnake(board_t *board)
{
    // Get the head of the snake
    gameObject_t *head = board->snake;

    // Add a new head to the snake based on the direction of the current head
    gameObject_t *nextHead = malloc(sizeof(gameObject_t));

    // If malloc failed, return DEAD
    // if (!nextHead) return DEAD;

    // Get the current direction of the head
    direction_t direction = head->direction;

    switch (d)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }    


}

// Check if an object has collided with the snake
int isCollision(gameObject_t *object, gameObject_t *snake)
{
    // Iterate through the snake, if the objects position hits the object, return true...
    for (gameObject_t *current = snake; current != NULL; current = current->next)
    {
        if (current->xPosition == object->xPosition && current->yPosition == object->yPosition)
        {
            return true;
        }
    }
    // At this point, there are no more snake elements to check and there is no collisions
    return false;
}

// Generate a random integer between the minimum and maximum values
int randomCoordinate(int min, int max)
{
    return max + rand() / (RAND_MAX / (min - max + 1) + 1);
}

// Add food to the board
void addFood(board_t *board)
{
    // Create a new food object
    gameObject_t *food = createObject(randomCoordinate(1, board->maxX), randomCoordinate(1, board->maxY), '*');

    // Check if the food has collided with the snake
    while (isCollision(food, board->snake))
    {
        // If it has, generate a new random coordinate
        food->xPosition = randomCoordinate(1, board->maxX);
        food->yPosition = randomCoordinate(1, board->maxY);
    }

    // Set the food pointer to the new food object
    board->food = food;
    return;

}

// Instantiate a new board for the game
board_t* createBoard(int maxX, int maxY)
{
    // Generate a random seed for later use
    srand(time(NULL));

    // Create a new board on the heap
    board_t *newBoard = malloc(sizeof(board_t));

    // Ensure that memory was correctly allocated before proceeding
    if (!newBoard) return NULL;

    // Set the max x and y values
    newBoard->maxX = maxX;
    newBoard->maxY = maxY;

    // Create the snake and food
    newBoard->snake = createSnake();
    newBoard->food = createObject(0, 0, 'F');

    // Ensure that memory was correctly allocated before proceeding
    if (!newBoard->snake || !newBoard->food) return NULL;

    // Set the score and game status
    newBoard->score = 0;
    newBoard->gameStatus = ALIVE;

    // Return the new board
    return newBoard;
}

// DONE
// Check if a game object is facing the opposite direction of the snake
int oppositeDirection(gameObject_t *nextHead, gameObject_t *snake)
{
    // If the next direction is the opposite of the current direction, return 1
    if (nextHead->direction == UP && snake->direction == DOWN) return 1;
    if (nextHead->direction == DOWN && snake->direction == UP) return 1;

    // If the next direction is the opposite of the current direction, return 1
    if (nextHead->direction == LEFT && snake->direction == RIGHT) return 1;
    if (nextHead->direction == RIGHT && snake->direction == LEFT) return 1;

    // Otherwise, return 0
    return 0;
}

// DONE
// Destroy the board and free any memory associated with the game 
void destroyBoard(board_t *board)
{
    // Free the food 
    free(board->food);

    // Free the snake
    gameObject_t *current = board->snake;
    while (current != NULL)
    {
        gameObject_t *next = current->next;
        free(current);
        current = next;
    }

    // Free the board
    free(board);
}