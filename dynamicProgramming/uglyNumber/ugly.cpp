#include<iostream>
using namespace std;


int min1(int a, int b){
    return(a < b ? a : b); 
}

int min(int a, int b, int c){
    return ( c < min1(a,b) ? c : min1(a,b)); 
}

int nthugly(int n){
    int ugly[n];
    ugly[0] = 1;
    int i2, i3, i5;
    i2 = i3 = i5 = 0;
    
    int next_multiple_of_2 = 2;
    int next_multiple_of_3 = 3;
    int next_multiple_of_5 = 5;
    int next_ugly_number = ugly[0];

    for(int i = 1; i < n; ++i){
        next_ugly_number =  min(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5);
        ugly[i] = next_ugly_number;
        if(next_ugly_number == next_multiple_of_2){
            i2 += 1;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if(next_ugly_number == next_multiple_of_3){
            i3 += 1;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if(next_ugly_number == next_multiple_of_5){
            i5 += 1;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }
    return next_ugly_number;

}


int main(){
    int n;
    std::cout<<"Enter the which ugly number do you want(rank)?:";
    std::cin>>n;
    std::cout<<"Ugly number at rank "<<n<<" is:"<<nthugly(n)<<std::endl;
    return 0;
}
