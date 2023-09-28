#include <stdio.h>

// count lines in input
// TODO get proper printf

int main(){
    int nl = 0;
    int blanks = 0;
    int tabs = 0;
    int c = 0;

    while ((c = getchar()) != EOF){
        if (c == '\n'){
            ++nl;
        } else if (c == ' '){
            ++blanks;
        } else if (c == '\t'){
            ++tabs;
        }
    }
    
    printf("new lines: %d\nnew blanks: %d\nnew tabs: %d\n", nl, blanks, tabs);

    return 0;

}