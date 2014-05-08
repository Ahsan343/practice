#include<iostream>
#include<vector>

void printA(int *v, int size){
	unsigned int i =0;
	while(i < size){
		std::cout<< v[i]<<" ";
		i++;
	}
	std::cout<<std::endl;
}



int iterateSequence(int *a, int N, int size){
	int sum = 0;
	int i = 0;
	int j = size;
	while(N > 0){
		while( (i + 1) < j){
			a[i] = a[i+1] - a[i];
			i++;
		}
		i =0;
		j--;
		printA(a, j);
		N--;
	} 	
	sum = 0;
	std::cout<<"j:"<<j<<std::endl;
	for(int x = j-1; x >=0; --x){
		sum += a[x];
	}
	return sum;
}

int main(){
	int arr[] = {1,2,5,6};
	int sum = iterateSequence(arr,2,4);
	std::cout<<"Sum:"<<sum<<std::endl;
	return 0;
}
