/*
 *Write a program to count blanks, tabs, and newlines.
 */

#include<stdio.h>

int main(){
    int blanks, tabs, newlines;
    int c,done,lastchar;
    blanks = 0;
    tabs = 0;
    newlines = 0;
    done = 0;
    printf("Write the content, in the end for EOF hit ctrl+D\n");
    while(!done){
        c = getchar();
        if(c == ' '){
            blanks++;
        }
        if(c == '\t'){
            tabs++;
        }
        if(c == '\n'){
            newlines++;
        }
        if(c == EOF){
            //when a text file might not end with new line
            if(lastchar != '\n'){
                newlines++;
            }
            done = 1;
        }
        lastchar = c;
    }

    printf("\nTotal- Blanks: %d, tabs: %d, newlines: %d\n", blanks, tabs, newlines);
    return 0;
}
