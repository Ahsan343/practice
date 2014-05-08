#include<iostream>
#include<string>
using namespace std;


int cal(string& str, int initSum){
	unsigned int i = 0;
	int sum = initSum;
	int nextBet = 1;
	while(i < str.length()){
		if(str[i] == 'W'){
			sum += nextBet;
			nextBet = 1;	
			std::cout<<"W:"<<sum<<" "<<nextBet<<std::endl;
		}
		else{
			sum -= nextBet;
			nextBet *= 2;
			std::cout<<"L:"<<sum<<" "<<nextBet<<std::endl;
			if(sum <= 0 || sum < nextBet) break;
		}
	++i;
	}
		return sum;
}
int main(){
	string streak;
	int initSum;
	std::cout<<"Enter the game streak:";
	std::cin>>streak;
	std::cout<<"Enter initial Sum:";
	std::cin>>initSum;
	std::cout<<"Total sum at the end is:"<<cal(streak, initSum)<<std::endl;
	return 0;

}
