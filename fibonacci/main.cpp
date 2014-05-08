#include<iostream>
/*

	fibonacci number using dynamic programming
*/


int fibb1(int n){
	int fib[n+1];
	fib[0] = 0;
	fib[1] = 1;
	for(int i = 2; i <= n; ++i){
		fib[i] = fib[i-1] + fib[i-2];
	}
	return fib[n];
}

int fibb2(int n){
	int a = 0;
	int b = 1;
	int c;
	for(int i = 2; i <= n; ++i){
		c  = a + b;
		a = b;
		b = c;
	}
	return b;

}

int main(){
	int n;
	std::cout<<"Enter the number:";
	std::cin>>n;
	std::cout<<"Fib:"<<fibb1(n)<<std::endl;
	std::cout<<"Fib:"<<fibb2(n)<<std::endl;
	return 0;
}
