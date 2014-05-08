/*Ex 1-3 
 * Modify the temperature conversion program to print a heading above the table.
 */

#include<stdio.h>

int main(void){
    float fahr, celcius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    printf("  F\t   C\n");
    while(fahr <= upper){
        celcius = (5.0/9.0)*(fahr- 32.0);
        printf("%3.0f\t%6.1f\n",fahr, celcius);
        fahr += step;
    }
    return 0;
}
