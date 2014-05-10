/*
 *  Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
 */


#include<stdio.h>
#define SEEN 1
#define NOT_SEEN 0
#define MAX 50

int main(void){
    int c;
    int space;
    space = NOT_SEEN;
    while((c = getchar()) != EOF){
        if(c == ' '){
            if(space == NOT_SEEN){
                space = SEEN;
                putchar(c);
            }
        }
        else{
            space = NOT_SEEN;
            putchar(c);
        }
    }

    return 0;
}
