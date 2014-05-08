/*Ex No. 1.2
 * Experiment to find out what happens when printf 's argument string contains \c, where c is some character not listed above.
 *
 * Following are the valid escape sequences in C (Source Wikipedia)
 * 
 * \a  - Alarm Beep(Bell)
 * \b  - Backspace
 * \f  - Formfeed(Forces printer to print the content after it on next page)
 * \n  - New Line
 * \r  - Carriage Return- is a control character or mechanism used to reset a device's position to the beginning of a line of text
 * \t  - Horizontal Tab
 * \v  - vertical Tab
 * \\  - Backslash
 * \'  - Single Quotations
 * \"  - Double Quotations
 * \?  - Question Mark
 * \0  - String parameter
 * \ and a new line - Macro new line
 * \0nnn- Octal representation
 * \xhh - hex representation
 * \uhhh - Unicode representation
 * \e    - Escape character, a non standard by GCC
 */

#include<stdio.h>

int main(){
    printf("Lets get an alarm and then new line: \a\n");
    printf("How about a new horizontal tab \t and then a vertical tab \v");
    printf("Lets print a question mark \? and quotations \" \' and backslash \\ \n");
    printf("Now lets try a form feed - \f\n");
    printf("This escape, \r, moves the active position to the initial position of the current line.\n");
    return 0;
}
