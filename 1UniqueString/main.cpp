/*
Question 1 Implement an algorithm to determine if a string has all unique characters you can not use additional data structures
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool isUnique(string input){
	 int arr[256] = {0};
	 unsigned int i;
	 for(i = 0; i < input.length(); ++i){
		++arr[int(input.at(i))];
		if(arr[int(input.at(i))] > 1) 
			return false;	
	 }	
	 if(i == input.length()) return true;
	 else return false;
}


int main(){
	string text;
	cout<<"Enter a string:";
	getline(cin, text);
	if(isUnique(text)) cout<<"String contains all unique character\n";
	else cout<<"String does not contain unique characters\n";
	return 0;
} 
