#include <stdio.h>

/* copy input to output; 1st version */

int main(){
    int c;

    printf("Enter some characters (Press Ctrl+C to finish:)\n");
    
    while ((c = getchar()) != EOF){
        putchar(c);
    }
}