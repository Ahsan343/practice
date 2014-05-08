#include<iostream>

void reverse(int *arr, int st, int e){
	int start = st;
	int end = e;	
	int temp;
	while(start < end){
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		++start;
		--end;
	}

}

void printArray(int *arr, int size){
	for(int i = 0; i  < size; ++i){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

void blockSwap(int *arr, int size, int d){
	reverse(arr,0, d-1);
	reverse(arr,d, size-1);
	reverse(arr, 0, size-1);
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8};
	blockSwap(arr, 8, 2);
	printArray(arr, 8);
	return 0;
}
