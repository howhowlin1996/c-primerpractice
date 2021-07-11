#include<iostream>
#include<string>
/*exe5.9 Write a program using a series of if statements to count the
number of vowels in text read from cin.*/
/*exe 5.10There is one problem with our vowel-counting program as
we’ve implemented it: It doesn’t count capital letters as vowels. Write a
program that counts both lower- and uppercase letters as the appropriate
vowel—that is, your program should count both 'a' and 'A' as part of
aCnt, and so forth.*/
/*exxe5.11 Modify our vowel-counting program so that it also counts the
number of blank spaces, tabs, and newlines read.*/
int main(){
	int Anumt=0,Enumt=0,Inumt=0,Onumt=0,Unumt=0,Space_num=0,Tabs_num=0,Newlines_num=0,ff_num=0,f1_num=0,fi_num=0;
	char word;
	bool f_check=0;
	std::string paragraph;
	while(std::getline(std::cin,paragraph)){
		++Newlines_num;
		for(auto word:paragraph){
			if(word=='a'||word=='A')
				++Anumt;
			else if(word=='e'||word=='E')
				++Enumt;
			else if(word=='i'||word=='I')
				++Inumt;
			else if(word=='o'||word=='O')
				++Onumt;
			else if(word=='u'||word=='U')
				++Unumt;
			else if(word==' ')
				++Space_num;
			else if(word=='\t')
				++Tabs_num;
			if(f_check==1){
				if(word=='f')
					++ff_num;
				else if(word=='1')
					++f1_num;
				else if(word=='i')
					++fi_num;
				f_check=0;
			}
			if(word=='f'&&f_check==0)
				f_check=1;
		}
	}
std::cout<<"a: "<<Anumt<<" e: "<<Enumt<<" i: "<<Inumt<<" o: "<<Onumt<<" u: "<<Unumt<<" spaces: "<<Space_num<<" tabs: "<<Tabs_num<<" newlines: "<<Newlines_num<<" ff: "<<ff_num<<" f1: "<<f1_num<<" fi: "<<fi_num<<std::endl;
	return 0;	








}
