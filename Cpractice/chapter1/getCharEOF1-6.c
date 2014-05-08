/*
 *Ex 1.6
 *Verify that the expression getchar() != EOF is 0 or 1
 * This program will verify the expression getchar() != EOF, it will prompt for input and then it will capture character from input.
 * if EOF is signalled (generally through Ctrl-Z or Ctrl-C (not neccessarily), the program should print 0 otherwise it should print 1
 * If your input stream is buffered (and it probably is), then
 * you will need to press the ENTER key before the program will
 * respond.
 */

#include<stdio.h>
int main(){
    printf("Press any key like say ENTER\n");
    printf("Expression getchar() != EOF evaluates to %d\n", getchar()!=EOF);
    return 0;
}
