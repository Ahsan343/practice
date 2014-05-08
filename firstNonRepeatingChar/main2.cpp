#include<iostream>
#include<map>

char nonRepeating(const std::string& str){
	unsigned int i = 0; 
	std::map<char,int> m;
	std::map<char,int>::iterator it;
	while( i < str.length()){
		it = m.find(str[i]);
		if(it != m.end()){
			m[str[i]] = ++(it->second);
		}
		else
			m[str[i]] = 1;
		++i;
	}

	for( i = 0; i < str.length(); ++i){
		it = m.find(str[i]);
		if(it != m.end()){
			if(it->second == 1)
				return str[i];
		}	
	}
	return -1;
}

int main(){
	std::string str;
	std::cout<<"Enter string:";
	std::cin>>str;
	std::cout<<"First Non - repeating char :"<<nonRepeating(str)<<std::endl;
	return 0;
}
