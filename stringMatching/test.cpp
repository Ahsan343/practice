#include<iostream>
using namespace std;

int missing(int N, int* arr){
	int diff;
	if( (arr[1]- arr[0]) == (arr[2] - arr[1])){
		diff = int(arr[1]) - int(arr[0]);
		for(int i = 3; i < N ; ++i){
			if(arr[i] - arr[i-1] != diff){
				return arr[i-1] + diff;
			}
		}
	}
		return -1;
}

int main(){
	int N;
	std::cin>>N;
	int *arr = new int[N];
	for(int i = 0; i < N; ++i){
		std::cin>>arr[i];
	}
	std::cout<<missing(N, arr);
	return 0;
}

