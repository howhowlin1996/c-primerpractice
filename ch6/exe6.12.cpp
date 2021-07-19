#include<iostream>

/*use references instead of pointers to swap the value of two ints.*/


void swap(int&a,int&b){
	int b_origin=b;
	b=a;
	a=b_origin;


}

int main(){
	std::cout<<"Please enter two numbers, I'll swap them for you"<<std::endl;
	int a=0,b=0;
	std::cin>>a>>b;
	std::cout<<"a="<<a<<" "<<"b="<<b<<std::endl;
	swap(a,b);
	std::cout<<"After swapping "<<"a="<<a<<" "<<"b="<<b<<std::endl;
	return 0;


}
