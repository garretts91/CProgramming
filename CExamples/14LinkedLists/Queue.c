//https://en.cppreference.com/w/c/header

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Node* head = NULL;
int nodeCount = 0;

void enqueue(char item) 
{
    if(head == NULL)
    {
        head = (struct Node*) malloc(sizeof(struct Node));

        if (head != NULL)
        {
            head->data = item;
            head->next = NULL;

            nodeCount++;
        }
    }
    else
    {
        struct Node* current = head;
            
        // Traverse the list to get to the last node
        while(current->next != NULL)
        {
            current = current->next;
        }
            
        // Add the node to the list
        struct Node* node = (struct Node*) malloc(sizeof(struct Node));
        
        if (node != NULL)
        {
            node->data = item;
            node->next = NULL;

            current->next = node;

            nodeCount++;
        }
    }
}

char dequeue() 
{
    char data = 0;

    if (head != NULL)
    {
        data = head->data;
            
        head = head->next;
            
        nodeCount--;
    } 
    else 
    {
        // The queue was empty, return null and don't change the count
        data = 0;
    }

    return data;
}

void listItems()
{
    struct Node* current = head;

    while (current != NULL)
    {
        printf("Data: %c \n", current->data);

        current = current->next;
    }
}
