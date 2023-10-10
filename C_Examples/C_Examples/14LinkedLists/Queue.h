//https://en.cppreference.com/w/c/header

struct Node
{
    char data;
    struct Node* next;
};

void enqueue(char item);

char dequeue();

void listItems();

