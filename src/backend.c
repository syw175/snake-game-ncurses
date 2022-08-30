/*
 * Filename: backend.c
 *
 * Description: Implementation of functions related to the Model and 
 *              Controller aspect of the snake game in terms of the 
 *              MVC design pattern.
 * 
 * Author: Steven Wong
 * Last Modified: August 30, 2022
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
    return ALIVE;
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

}






