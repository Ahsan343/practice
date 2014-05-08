#include<iostream>
#include<vector>

std::vector<int> calWindow(std::vector<int> vec, int windowSize){
	std::vector<int> result;
	int sum = 0;
	for(int i =0; i < windowSize; ++i){
		sum += vec[i];
	}
	result.push_back(sum);
	std::cout<<"SUM first:"<<sum<<std::endl;
	for(unsigned int i = 1; i <= vec.size()-windowSize; ++i){
		std::cout<<vec[i]<<":"<<vec[i+1]<<std::endl;
		sum  = (sum - vec[i] + vec[i+1]);
		result.push_back(sum);
	}
	return result;
}

int main(){
	std::vector<int> vec;
	int windowSize,size;
	std::cout<<"Enter window Size:";
	std::cin>>windowSize;
	std::cout<<"Enter vector size:";
	std::cin>>size;
	std::cout<<"Enter vector elements:";
	int el;
	for(int i = 0; i < size; ++i){
		std::cin>>el;	
		vec.push_back(el);
	}
	std::vector<int> result;
 	result = calWindow(vec, windowSize);
	std::cout<<"Result:";
	for(unsigned int i = 0; i < result.size(); ++i){
		std::cout<<result[i]<<" ";
	}
	std::cout<<std::endl;
	
	return 0;
}
