#include<iostream>


void swap(int& i , int& j){
	int temp;
	temp = i;
	i = j;
	j = temp;
}

void rotateClockwise(int **arr, int size){
	//matrix transpose
	for(int i = 0; i < size; ++i)
	{
		for(int j = i+1; j < size; ++j)
			swap(arr[i][j],arr[j][i]);
	
	}
	
	//reverse
	for(int i = 0; i < size; ++i){
		int start = 0;
		int end = size-1;
		while(start < end){
			swap(arr[i][start], arr[i][end]);
			start++;
			end--;
		}
	}

}

void rotateAntiClockwise(int **arr, int size){
	for(int i = 0; i < size; ++i){
		int start = 0;
		int end = size-1;
		while(start < end){
			swap(arr[i][start], arr[i][end]);
			start++;
			end--;
		}
	}

	for(int i = 0; i < size; ++i){
		for(int j = i+1; j < size; ++j)
			swap(arr[i][j],arr[j][i]);
	}

}

void printMat(int **arr, int size){
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}

int main(){
	int **arr;
	int size;
	std::cout<<"Enter size:";
	std::cin>>size;
	arr = new int*[size];
	for(int i = 0; i < size; ++i){
		arr[i] = new int[size];
	}
	std::cout<<"Enter matrix values:";
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			std::cin>>arr[i][j];
		}
	}
	std::cout<<"Before Clockwise rotation:\n";
	printMat(arr,size);
	rotateClockwise(arr, size);
	std::cout<<"After Clockwise rotation:\n";
	printMat(arr,size);
	rotateAntiClockwise(arr,size);
	std::cout<<"After Anti-Clockwise rotation:\n";
	printMat(arr,size);

	return 0;
}
