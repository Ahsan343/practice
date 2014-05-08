#include<iostream>

int fibb1(int n){
	if(n == 0 || n == 1)
		return n;
	else if(n > 1)
		return fibb1(n-1) + fibb1(n-2);
	else
		return -1;
}

int fibb(int n){
	if(n == 0) return 0;
	else{
		int a = 1;
		int b = 1;
		for(int i = 3; i <= n;++i){
			int c = a+ b;
			a = b;
			b = c;
		}
		return b;
	}

}

int main(){
	std::cout<<"First 11 numbers of fibb series:";
	for(int i = 0; i < 11; ++i){
		std::cout<<fibb1(i)<<" "<<fibb(i)<<std::endl;
	} 
	return 0;
}
