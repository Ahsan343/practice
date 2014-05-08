#include<iostream>

int maxDivide(int a, int b){
	while(a % b == 0)
		a = a/b;
	return a;
}

bool isUgly(int n){
	n = maxDivide(n,2);
	n = maxDivide(n,3);
	n = maxDivide(n,5);
	return (n == 1);
}

int getNthUglyNum(int n){
	int count = 0;
	int x = 1;
	while(count < n){
		++x;
		if(isUgly(x))	
			++count;
	}
	return x;
}

int main(){
	std::cout<<"150th ugly number is :"<<getNthUglyNum(150)<<std::endl;
	return 0;
}
