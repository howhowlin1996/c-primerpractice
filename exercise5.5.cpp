#include<iostream>
/*exe 5.5 Using an if–else statement, write your own version of the
program to generate the letter grade from a numeric grade.*/

int main(){
	int record=0;
	std::cin>>record;
	char gpa[4]={'D','C','B','A'};
	if(record>=0&&record<=100)
		if(record>=60){
			int pos=(record-60)/10;
			int remind=record%10;
			if(pos>=3){
				if(remind<2)
					std::cout<<"A"<<std::endl;
				else
					std::cout<<"A-"<<std::endl;
			}
			else{
				if(remind>7)
					std::cout<<gpa[pos]<<"+"<<std::endl;
				else if(remind<2)
					std::cout<<gpa[pos]<<"-"<<std::endl;				    else
					std::cout<<gpa[pos]<<std::endl;


			}


		}	
		else
			std::cout<<'F'<<std::endl;
	else{
		std::cout<<"error"<<std::endl;
	}





	return 0;

}
