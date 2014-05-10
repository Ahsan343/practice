/*Ex 1-10
 * Write a program to copy its input to its output, replacing each tab by \t , each backspace by \b , and each backslash by \\ . This makes tabs and backspaces visible in an unambiguous way.
 *
 */

#include<stdio.h>
#define SP_CHAR '\\'

int main(){
    int c ;
    while((c=getchar()) != EOF){
        switch(c){
            case '\b':
                putchar(SP_CHAR);
                putchar('b');
                break;

            case '\t':
                putchar(SP_CHAR);
                putchar('t');
                break;

            case SP_CHAR:
                putchar(SP_CHAR);
                putchar(SP_CHAR);
                break;

            default:
                putchar(c);
                break;
        }
    }
    return 0;
}
