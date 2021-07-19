#include<iostream>
/*Write and test your own version of reset that takes a
reference.*/

void reset(int&i){
	i=0;
}


int main(){
	std::cout<<"Please enter a number, I'll reset it to zero."<<std::endl;
	int num=0;
	std::cin>>num;
	reset(num);
	std::cout<<num<<std::endl;
	return 0;

}
