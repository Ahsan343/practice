#include<iostream>
#include<string>

bool match(const std::string& main, const std::string& sub){
	unsigned int i =0, j = 0, first;
	while(main[i]){
		j = 0;
		while(sub[0] != main[i] && i < main.length()){
			i++;
		}
		if(i >= main.length()){
			return false;
		}
		std::cout<<"i:"<<i<<std::endl;
		if(sub[j] == main[i])
			first = i;
		while(sub[j] == main[i]){
			i++;
			j++;
		}
		if(j == sub.length()){
			std::cout<< "Match from "<<first<<" to "<<i<<std::endl;
			return true;
		}
		++i;
	}
	return false;

}

int main(){
	std::string mains,sub;
	std::cout<<"Enter main string:";
	std::getline(std::cin, mains);
	std::cout<<"Enter substring:";
	std::getline(std::cin, sub);
	if(match(mains,sub)){
		std::cout<<"Match found\n";
	}
	else{
		std::cout<<"No match\n";
	}
	return 0;
}
