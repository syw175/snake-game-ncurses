/* Program: snake-game in c
   Author: Steven Wong
   Date last modified: May 18, 2022
*/


// Cotains the overall game logic 

#include<stdio.h> 

// LinkedList structure for snake from https://www.geeksforgeeks.org/linked-list-set-1-introduction/
class Node {
public:
    int data;
    Node* next;
};

