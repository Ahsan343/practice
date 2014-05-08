#include<iostream>

void printMatrix(int **arr, int size){
	std::cout<<"Current Matrix:"<<std::endl;
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}

}

void swap(int& n1, int& n2){
	int temp;
	temp = n1;
	n1  = n2;
	n2 = temp;
}

void rotateClock(int **arr, int size){
	//transpose
	for(int i =0; i < size; ++i){
		for(int j = i; j < size; ++j){
			swap(arr[i][j],arr[j][i]);
		}
	}
	std::cout<<"Transposed:"<<std::endl;	
	printMatrix(arr, size);
	
	for(int i = 0; i < size; ++i){
		int start = 0;
		int end = size-1;
		while(start < end){
			swap(arr[i][start],arr[i][end]);
			start++;
			end--;
		}
	}
	std::cout<<"Rotated Clock wise Matrix:"<<std::endl;
	printMatrix(arr, size);

}

void rotateAntiClock(int **arr, int size){
	
	for(int i = 0; i < size; ++i){
		int start = 0;
		int end = size-1;
		while(start < end){
			swap(arr[i][start],arr[i][end]);
			start++;
			end--;
		}
	}
	//transpose
	for(int i =0; i < size; ++i){
		for(int j = i; j < size; ++j){
			swap(arr[i][j],arr[j][i]);
		}
	}

	std::cout<<"Rotated AntiClock wise Matrix:"<<std::endl;
	printMatrix(arr, size);

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
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < size; ++j){
				std::cin>>arr[i][j];
			}
		}
		printMatrix(arr, size);
		rotateAntiClock(arr,size);
		return 0;
}
