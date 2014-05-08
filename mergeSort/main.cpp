#include<iostream>

int merge(int *arr, int start, int mid, int end){
	int *temp = new int[end-start+1];
	int i = start;
	int j = mid+1;
	int k = 0;
	int count = 0;
	while(i <= mid && j<=end){
		if(arr[i] < arr[j]){
			temp[k] = arr[i];
			++i;
		}
		else{
			temp[k] = arr[j];
			count += mid-i + 1;
			++j;
		}
		++k;
	}
	while(i<=mid){
		temp[k] = arr[i];
		++i;
		++k;
	}
	while(j<=end){
		temp[k] = arr[j];
		++i;
		++k;
	}
	for(int i = start; i <= end; ++i){
		arr[i] = temp[i-start];
	}
	delete[] temp;
	return count;
}

int mergeSort(int *arr, int start, int end){
	int count = 0;
	if(start < end){
		int mid = (start+end)/2;	
		count += mergeSort(arr,start,mid);
		count += mergeSort(arr,mid+1,end);
		count += merge(arr,start, mid, end);
	}
	return count;
}

void print(int *arr, int size){
	for(int i = 0; i < size; ++i)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

int main(){
	int arr[] = {10,9,8,7,6,5,4,3,2,1};
	print(arr,10);
	int count = mergeSort(arr,0, 9);
	print(arr,10);
	std::cout<<"Total inversions:"<<count<<std::endl;
	return 0;
}
