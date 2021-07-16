#include<iostream>
#include "exercise6.8.h"

int main(){
	std::cout<<"Please enter a number, then I'lldo factorial counting for you"<<std::endl;
	int count_num=1;
	while(std::cin>>count_num){
		std::cout<<count_num<<"!: "<<factorial(count_num)<<std::endl;
		std::cout<<"Please enter a number, then I'lldo factorial counting for you"<<std::endl;

	}



return 0;
}
