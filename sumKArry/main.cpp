#include<iostream>
#include<map>
#define MAX 10000

bool checkSum(int *arr, int sum, int size){
	int check[MAX] = {0};
	int temp;
	for(int i = 0; i < size; ++i){
		temp = sum - arr[i];
		if(temp >= 0 && check[temp] ==1)
		{	
			std::cout<<"Pair with given sum("<<sum<<") found:"<<temp<<","<<arr[i]<<std::endl;
			return true;
		}
		check[arr[i]] = 1;
	}
	return false;

}


int main(){
	int size;
	std::cout<<"Enter size:";
	std::cin>>size;
	int *arr = new int[size];
	std::cout<<"Enter Array:";
	for(int i =0; i < size; ++i){
		std::cin>>arr[i];
	}

	int sum;
	std::cout<<"Enter pair sum:";
	std::cin>>sum;
	if(checkSum(arr, sum, size))
		std::cout<<"match found\n:";
	else
		std::cout<<"match not found\n";
	
	return 0;

}
