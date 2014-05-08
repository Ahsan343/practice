/*Ex 1-4
 * * A temperature conversion program to print C to F
 * */

#include<stdio.h>

int main(void){
    float fahr, celcius;
    int lower,upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    celcius = lower;
    printf("  C\t   F\n");
    while(celcius <= upper){
        fahr = (9.0/5.0) * (celcius + 32.0);
        printf("%3.0f\t%6.1f\n",celcius, fahr);
        celcius += step;
    }
    return 0;

}
