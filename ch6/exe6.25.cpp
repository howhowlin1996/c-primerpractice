#include<iostream>
/*Write a main function that takes two arguments.
Concatenate the supplied arguments and print the resulting string.*/



int main(int argc,char **argv){
	std::cout<<argc<<std::endl;
	for(int i=0;i!=argc;++i)
		std::cout<<argv[i]<<std::endl;
	return 0;
		


}
