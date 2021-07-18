#include<iostream>
#include"CHAPTER6.h"
/*exe6.9 main function*/

int main(){
	std::cout<<"Please enter a number, I'll count a factorial for you"<<std::endl;
	int first=0;
	while(std::cin>>first){
		std::cout<<first<<"! : "<<factorial(first)<<std::endl;
	std::cout<<"Please enter a number, I'll count a factorial for you"<<std::endl;
	}

	return 0;
}
