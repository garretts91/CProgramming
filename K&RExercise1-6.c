#include <stdio.h>
int main() /* count new lines in input */
{
    int c, nl, blanks;
    nl = 0;
  	blanks = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n'){
            ++nl;
        } else if (c == ' '){
           ++blanks;
        }
    printf("%d %d\n", blanks, nl);
}