#include<iostream>
#include<string>
#include<ctype.h>
/*Write a function to determine whether a string contains
any capital letters. Write a function to change a string to all lowercase.*/




bool find_uppercase(const std::string &s){
	for(auto ch:s)
		if(isupper(ch))
			return true;
	return false; 

}

void change_to_lowercase(std::string&s){
	for(auto &ch:s)
		if(isupper(ch))
			ch=tolower(ch);

}


int main(){
	std::string str;
	std::cout<<"Please enter a string: "<<std::endl;
	std::cin>>str;
	if(find_uppercase(str))
		std::cout<<"The string contains capital letters"<<std::endl;	    std::cout<<"String before convert to lower string: "<<str;
	change_to_lowercase(str);
	std::cout<<"After converting: "<<str<<std::endl;
	return 0;
}
