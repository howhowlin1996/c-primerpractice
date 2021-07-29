#include<iostream>
/*Write a function that takes an int and a pointer to an int
and returns the larger of the int value or the value to which the pointer
points. What type should you use for the pointer?*/

int compare(const int a,int const *b)
{
	if(a>*b)
	return a;
	else
	return *b;
}



int main(){
	int a,b;
	std::cin>>a>>b;
	std::cout<<compare(a,&b)<<" is bigger"<<std::endl;

	return 0;
}
