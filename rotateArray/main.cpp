/* Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements. */

/* Method 1 
Rotate one by one  */

#include<iostream>

void rotateLeftByOne(int *a, int size){
	int temp,i;
	temp = a[0];
	for(i = 0; i < size-1 ; ++i){
		a[i]= a[i+1];
	}
	a[i] = temp;
}

void rotateLeft(int *a, int size, int d){
	for(int i = 0; i < d; ++i){
		rotateLeftByOne(a,size);
	}
}

void printArray(int *a, int size){
	for(int i = 0; i < size; ++i){
		std::cout<<a[i]<<" ";
	}
	std::cout<<std::endl;
}



int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	rotateLeft(arr,7,2);
	printArray(arr,7);
	return 0;
}


