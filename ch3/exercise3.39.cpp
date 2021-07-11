/*exe3.39 Write a program to compare two strings. Now write a
program to compare the values of two C-style character strings.*/
#include<iostream>
#include<string>
void compare_str(std::string &str1,std::string &str2){
	if(str1>str2)
		std::cout<<"str1>str2"<<std::endl;
	else if(str2>str1)
		std::cout<<"str2>str1"<<std::endl;
	else
		std::cout<<"str1==str2"<<std::endl;

}
void compare_chr(char* chr1,char* chr2,int size1,int size2){
	if(size1>size2)
		std::cout<<"chr1>chr2"<<std::endl;
	else if(size2>size1)
		std::cout<<"chr2>chr1"<<std::endl;
	else{
		for(int i=0;i!=size1;++i,++chr1,++chr2){
			if(*chr1>*chr2){
				std::cout<<"chr1>chr2"<<std::endl;
				return;
			}
			else if(*chr2>*chr1){
				std::cout<<"chr2>chr1"<<std::endl;
				return;
			}
			
		}
		std::cout<<"chr1==chr2"<<std::endl;

	}

}



int main(){
	 std::cout<<"Please enter two strings splited with witespace :"<<std::endl;
	std::string str1;
	std::string str2;
	std::cin>>str1>>str2; // read in two strings
	const int str1_s=str1.size(); //confirm the char array size
	const int str2_s=str2.size();
	char chr1[str1_s+1]; // reserve the '\0' position
	char chr2[str2_s+1];
	char *chr1_beg=chr1;
	char *chr2_beg=chr2;
	for(auto character:str1){
		*chr1_beg=character;
		++chr1_beg;
	}
	for(auto character:str2){
		*chr2_beg=character;
		++chr2_beg;
	}
	*chr1_beg='\0';
	*chr2_beg='\0';
	compare_str(str1,str2);
	compare_chr(chr1,chr2,str1_s+1,str2_s+1);



	

	return 0;
}
