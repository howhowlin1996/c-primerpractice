#include<iostream>
#include<string>
#include<ctype.h>
#include<set>
/*Revise the program from the exercise in § 5.5.1 (p. 191) so
that it looks only for duplicated words that start with an uppercase letter.*/


void checkDuplicate(){
	std::string word;
	std::set<std::string>table;
	while(std::cin>>word){
		if(isupper(word[0])){
			word[0]=tolower(word[0]);
			table.insert(word);
			continue;
		}
		else{
			if(table.find(word)!=table.end()){
				std::cout<<word<<" occurs twice"<<std::endl;
				return;
			}
		}
		
			
	}
	
	std::cout<<"No Words repeated"<<std::endl;


}



int main(){
	std::cout<<"Please key in a paragraph, and we'll check whether the upper letter words have a duplicate or not."<<std::endl;
	checkDuplicate();
	return 0;

}
