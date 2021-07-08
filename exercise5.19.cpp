#include<iostream>
#include<string>

/*Write a program that uses a do while loop to repetitively
request two strings from the user and report which string is less than
the other.*/

void compareStrings(std::string str1,std::string  str2){
	if(str1>str2)
		std::cout<<"str1>str2"<<std::endl;
	else if(str2>str1)
		std::cout<<"str2>str1"<<std::endl;
	else
		std::cout<<"str1==str2"<<std::endl;


}


int main(){
	
	std::string str1,str2;
	bool flag=true;
	do{
	std::cout<<"Enter two strings: "<<std::endl;
	if(std::cin>>str1>>str2)
		compareStrings(str1,str2);
	else
		flag=false;
	} while(flag);
	return 0;


}
