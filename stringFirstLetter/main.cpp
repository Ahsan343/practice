#include<iostream>
#include<string>

std::string getWord(std::string test){
	int i = 0, j = 0;
	char word[test.length()];
	bool newWord=true;
	
	while(test[i]){
		if(test[i] != ' ' && newWord){
			word[j] = test[i];
			newWord = false;
			j++;
		}
		if(test[i] == ' ' && test[i+1] != ' '){
			newWord = true;
		}
	++i;
	}
	word[j] = '\0';
	return std::string(word);
}

int main(){
	std::string test;
	std::cout<<"Enter a string:";
	std::getline(std::cin,test);
	std::string firstLetterWord = getWord(test);
	std::cout<<firstLetterWord<<std::endl;
	return 0;
}
