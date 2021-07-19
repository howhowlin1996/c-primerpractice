#include<iostream>
/*Using pointers, write a function to swap the values of two
ints. Test the function by calling it and printing the swapped values.*/



void swap(int* a,int* b){
	int b_origin=*b;
	*b=*a;
	*a=b_origin;



}

int main(){
	std::cout<<"Please enter two numbers, I'll swap them for you"<<std::endl;
	int a=0,b=0;
	std::cin>>a>>b;
	std::cout<<"a="<<a<<" "<<"b="<<b<<std::endl;
	swap(&a,&b);
	std::cout<<"After swaping "<<"a="<<a<<" "<<"b="<<b<<std::endl;
	
	return 0;
}




