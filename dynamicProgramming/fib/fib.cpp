#include<iostream>
using namespace std;

int fibBottomUp(int n){
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n;++i){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int fibTopDown(int n, int * fib){
    if(n == 0 || n == 1){
        return n;
    }
    if(fib[n] != -1)
        return fib[n];
    else{
        fib[n] = fibTopDown(n-1, fib) + fibTopDown(n-2, fib);
        return fib[n];
    }
}

int best(int n){
    int a = 0;
    int b = 1;
    int sum = 0;
    for(int i = 2; i <=n; ++i){
        sum = a + b;
        a = b;
        b = sum;
    }
    return b;
}

int main(){
    int n;
    std::cout<<"Which fibonacci term:";
    std::cin>>n;
    int fib[n+1];
    for(int i = 0; i <= n; ++i){
        fib[i] = -1;
    }
    std::cout<<"TopDown:"<<fibTopDown(n, fib)<<std::endl;
    std::cout<<"BottomUp:"<<fibBottomUp(n)<<std::endl;
    std::cout<<"best:"<<best(n)<<std::endl;
    return 0;
}
