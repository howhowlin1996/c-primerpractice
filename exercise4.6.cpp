/*exe4.6 Write an expression to determine whether an int value is
even or odd.
exe 4.10 Write the condition for a while loop that would read ints
from the standard input and stop when the value read is equal to 42.
*/


#include<iostream>


int main(){
	// exe 4.6
	int num=0;
	std::cin>>num;
	if(num%2==0)
		std::cout<<"is even"<<std::endl;
	else
		std::cout<<"is odd"<<std::endl;
	//exe 4.10
	while(std::cin>>num&&num!=42)
		std::cout<<num<<std::endl;








	return 0;
}
