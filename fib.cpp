
// A fibonacci program to print till nth term.
#include<iostream>

void fibSeries(int n){
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < n ; ++i){
        fib[i] = fib[i-1] + fib[i-2];
    }
    for(int i = 0; i < n; ++i){
        std::cout<<fib[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    int n;
    std::cout<<"How many terms of fib series you want to print?";
    std::cin>>n;
    std::cout<<"Fibonnaci series upto term "<<n<<":"<<std::endl;
    fibSeries(n);
    return 0;
}
