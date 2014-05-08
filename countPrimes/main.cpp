#include<iostream>
using namespace std;


void mark(bool *arr, int x, int N){
	int i = 2;
	int num;
	while((num = i*x) <= N){
		arr[num-1] = true;
		++i;
	}
}

int countPrimes(int N){
	if(N >= 2){
		int count = 0;
		bool *arr = new bool[N];
		for(int i =0 ; i < N; ++i){
			arr[i] = false;
		}
		for(int i = 1; i < N; ++i){
			if(arr[i] == false){
				count++;
				mark(arr, i+1,N); 
			}
		}
		return count;
	}
	return -1;
}


int main(){
	int N;
	std::cout<<"Enter N:";
	std::cin>>N;
	std::cout<<"Total Number of Primes:"<<countPrimes(N)<<std::endl;
	return 0;
}
