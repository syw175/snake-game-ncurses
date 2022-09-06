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

// DONE
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

// DONE
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

// DONE
// Move the snake based on user input
status_t moveSnake(gameBoard_t *board)
{
    gameObject_t *head = board -> snake;
	gameObject_t *next_head = malloc(sizeof(gameObject_t));
	direction_t d = board -> snake -> direction;

    // Get the next position of the head of the snake
	switch(d) {		
		case UP:
			next_head -> xPosition 			= (head -> xPosition);
			next_head -> yPosition 			= (head -> yPosition) - 1;
			next_head -> symbol = '^';
			break;
		case DOWN:
			next_head -> xPosition 			= (head -> xPosition);
			next_head -> yPosition 			= (head -> yPosition) + 1;
			next_head -> symbol = 'v';
			break;
		case LEFT:
			next_head -> xPosition 			= (head -> xPosition) - 1;
			next_head -> yPosition 			= (head -> yPosition);
			next_head -> symbol = '<';
			break;
		case RIGHT:
			next_head -> xPosition 			= (head -> xPosition) + 1;
			next_head -> yPosition 			= (head -> yPosition);
			next_head -> symbol = '>';
			break;
		default:
			next_head -> xPosition 			= (head -> xPosition);
			next_head -> yPosition 			= (head -> yPosition);
			next_head -> symbol = head -> symbol;
			break;
	}

    // Check for collision with the food
    if (next_head -> xPosition == board -> food -> xPosition && next_head -> yPosition == board -> food -> yPosition) 
    {
        // Add the food to the snake
        next_head -> next = head;
        board -> snake = next_head;

        // Update the score
        board -> score += 1;

        // Create a new food item
        board -> food = createObject(rand() % board -> maxX, rand() % board -> maxY, 'o');
    } 
    else 
    {
        // Check for collision with the snake
        gameObject_t *current = head;
        while (current != NULL) 
        {
            if (next_head -> xPosition == current -> xPosition && next_head -> yPosition == current -> yPosition) 
            {
                return DEAD;
            }
            current = current -> next;
        }

        // Check for collision with the walls
        if (next_head -> xPosition < 0 || next_head -> xPosition >= board -> maxX || next_head -> yPosition < 0 || next_head -> yPosition >= board -> maxY) 
        {
            return DEAD;
        }

        // Move the snake
        next_head -> next = head;
        board -> snake = next_head;

        // Remove the tail of the snake
        current = head;
        while (current -> next -> next != NULL) 
        {
            current = current -> next;
        }
        free(current -> next);
        current -> next = NULL;
    }
    return ALIVE;
}

// DONE
// Check if a new object is in the same place as the snake
int isCollision(gameObject_t *newObject, gameObject_t *snake)
{
    // Iterate through the snake, if the objects position hits the object, return true...
    for (gameObject_t *current = snake; current != NULL; current = current->next)
    {
        if (current->xPosition == newObject->xPosition && current->yPosition == newObject->yPosition)
        {
            return 1;
        }
    }
    // At this point, there are no more snake elements to check and there is no collisions
    return 0;
}

// DONE
// Generate a random integer between the minimum and maximum values
int randomCoordinate(int min, int max)
{
    return max + rand() / (RAND_MAX / (min - max + 1) + 1);
}

// DONE
// Add food to the board
void addFood(gameBoard_t *board)
{
    // Create a new food object
    gameObject_t *food = createObject(randomCoordinate(1, board->maxX-3), randomCoordinate(1, board->maxY-3), '*');

    // Check if the food has collided with the snake
    while (isCollision(food, board->snake))
    {
        // If it has, generate a new random coordinate
        food->xPosition = randomCoordinate(1, board->maxX-3);
        food->yPosition = randomCoordinate(1, board->maxY-3);
    }

    // Set the food pointer to the new food object
    board->food = food;
    return;

}

// DONE
// Instantiate a new board for the game
gameBoard_t* createBoard(int maxX, int maxY)
{
    // Generate a random seed for later use
    srand(time(NULL));

    // Create a new board object
    gameBoard_t *newBoard = malloc(sizeof(gameBoard_t));

    // Ensure that memory was correctly allocated before proceeding
    if (!newBoard) return NULL;

    // Set the board's properties and create the snake/food
    newBoard->snake = createSnake();
    newBoard->maxX = maxX;
    newBoard->maxY = maxY;
    newBoard->food = createObject(maxX, maxY, '#');
    newBoard->score = 0;

    // Set the snake's direction to a default direction
    newBoard->snake->direction = HOLD;

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
void destroyBoard(gameBoard_t *board)
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