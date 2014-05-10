/*
 *Ex 1-11
 * How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
 *
 * Hit ctrl+D for EOF
 */

#include<stdio.h>
#define WORD_ON 1
#define WORD_OFF 0

int main(){
    int state;
    int c ;
    int count;
    state = WORD_OFF;
    count = 0;
    while((c=getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
                state = WORD_OFF;
        }
        else if(state == WORD_OFF){
                state = WORD_ON;
                count++;
        }
    }

    printf("Total Words in the text:%d\n", count);
    return 0;
}
