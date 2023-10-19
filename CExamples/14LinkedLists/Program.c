/* 
# Author:        
# Description:   
# Date:          
# Specification:
*/

#include <stdio.h>
#include "Queue.h"

void main() 
{
    printf("Data items added...\n");
    enqueue('A');
    enqueue('B');
    enqueue('C');

    listItems();

    char data = dequeue();
    printf("Data item removed: %c \n", data);

    listItems();
        
    printf("Data item added\n");
    enqueue('D');

    listItems();

	printf("Goodbye...");

    int c = getchar();
}
