#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

bool compare(const int& a,const int& b){
	return (abs(a) < abs(b));
}

int partition(int *arr, int start, int end){
	int pivot = arr[start];
	int p = start+1;
	int q = end;
	while(p <= q){
		while(arr[p] <= pivot)
			p++;
		while(arr[q] > pivot)
			q--;
		if(p < q){
		   std::cout<<"arr[p]:arr[q]=="<<abs(arr[p])<<":"<<abs(arr[q])<<std::endl;
	           if(abs(arr[p]) < abs(arr[q])){
			swap(arr[p], arr[q]);
		    }
			++p;
			--q;
		}
	}
	swap(arr[start], arr[q]);

	return q;
}

void quicksort(int *arr, int start, int end){
	if(start<end){
		int pivotIndex = partition(arr, start, end);
		quicksort(arr, start, pivotIndex-1);
		quicksort(arr, pivotIndex+1, end);
	}
}

void printArr(int *arr, int size){
	std::cout<<"Arr:";
	for(int i = 0; i < size; ++i){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

int main(){

	int arr[10] = {1,6, 9,1,4, -11, -13, 6, 11, 2};
	printArr(arr, 10);
	sort(arr, arr+10,compare );
	printArr(arr, 10);
	return 0;

/*
	quicksort(arr, 0, 9);
	printArr(arr, 10);
	return 0;
*/
}
