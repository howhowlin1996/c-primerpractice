#include<iostream>
#include<stdexcept>
/*Write a program that reads two integers from the standard
input and prints the result of dividing the first number by the second.*/

void divide(){
	int a,b;
	while(std::cin>>a>>b){
		try{	
			float divide=0;
			if(b==0) throw std::logic_error("divide by 0");
			divide=(float)a/b;
			std::cout<<"divide: "<<a<<"/"<<b<<"= "<<divide<<std::endl;	
		}
		catch(std::logic_error err){
			std::cout<<"error "<<err.what()<<std::endl;
		}	
	}
}


int main(){
	divide();

}
