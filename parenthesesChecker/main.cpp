#include<iostream>
#include<stack>
using namespace std;

bool match(char c1, char c2){
	if( c1 == '(' && c2 == ')' )
		return true;
	if(c1 == '[' && c2 == ']')
		return true;
	if(c1 == '{' && c2 == '}')
		return true;
	return false;
}

bool check(const string& str){
	unsigned int i = 0;
	std::stack<char> s;
	while(i < str.length()){
		if(str[i] == '(' || str[i]== '[' || str[i] == '{'){
			s.push(str[i]);
		}
		if(str[i] == ')' || str[i]== ']' || str[i] == '}'){
			if(!s.empty()){
				if(match(s.top(), str[i])){
					s.pop();
				}	
				else
					return false;
			}
			else
				return false;
	
		}
		i++;
	}
	if(s.empty()){
		return true;
	}
	return false;
}


int main(){	
	string s1;
	std::cout<<"Enter string:";
	std::getline(std::cin, s1);
	if(check(s1)){
		std::cout<<"String is valid\n";
	}
	else
		std::cout<<"Invalid string\n";
	return 0;

}
