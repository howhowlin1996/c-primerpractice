/*Extend the program that assigned high pass, pass, and fail
grades to also assign low pass for grades between 60 and 75 inclusive. Write
two versions: One version that uses only conditional operators; the other
should use one or more if statements. Which version do you think is easier
to understand and why?*/


#include<iostream>
#include<vector>

int main(){
	std::vector<int>grade_table;
	int grade=0;
	while(std::cin>>grade)
		if(grade>=0&&grade<=100)
			grade_table.push_back(grade);
	
	//conditional operation
		for(auto ele:grade_table)
			std::cout<<(ele>90?"high pass":ele>=60&&ele<=75?"low pass":ele<60?"failed":"pass")<<" ";
	std::cout<<std::endl;
	// if-else stateman
		for(auto ele:grade_table){
			if(ele>90)
				std::cout<<"high pass";
			else if(ele>=60&&ele<=75)
				std::cout<<"low pass";
			else if(ele<60)
				std::cout<<"failed";
			else
				std::cout<<"pass";
			
			std::cout<<" ";
		}

		std::cout<<std::endl;
		return 0;
}
