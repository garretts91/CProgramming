#include <stdio.h>
<<<<<<< HEAD

/* copy input to output; 1st version */

int main(){
    int c;

    printf("Enter some characters (Press Ctrl+C to finish:)\n");
    
    while ((c = getchar()) != EOF){
        putchar(c);
    }
    
=======
/* copy input to output; 1st version */
int main(){
    int c;
    
    c = getchar();
    while (c != EOF){
        putchar(c);
        c = getchar();
    } 
>>>>>>> 6894b4b96dbef30c2a451532d07e7c3ba8bf14c6
}