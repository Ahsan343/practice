/* Ex 1-5
 * Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
 */

#include<stdio.h>

int main(void){
    float fahr, celcius;
    int lower, upper, step;
    lower= 0;
    upper = 300;
    step = 20;

    fahr = upper;
    printf("  F\t   C\n");
    while(fahr >= lower){
        celcius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f\t%6.1f\n", fahr, celcius);
        fahr -= step;
    }
    return 0;
}
