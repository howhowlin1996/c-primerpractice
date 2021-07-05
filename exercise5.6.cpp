#include<iostream>
/*exe 5.6 Rewrite your grading program to use the conditional operator in place of the if–else statement.*/

int main(){
	int record=0;
	std::cin>>record;
	char gpa[4]={'D','C','B','A'};
	if(record>=0&&record<=100)
		if(record>=60){
			int pos=(record-60)/10;
			int remind=record%10;
			if(pos>=3){
				std::cout<<((remind<2)?"A-":"A");
				std::cout<<std::endl;
			}
			else{	
				std::string record="";
				record+=gpa[pos];
				record+=((remind>7)?'+':(remind<2)?'-':' ');
				std::cout<<record<<std::endl;



			}


		}	
		else
			std::cout<<'F'<<std::endl;
	else{
		std::cout<<"error"<<std::endl;
	}





	return 0;

}

