#include<iostream>
#include<string>
#include<map>
/*Write a program to read strings from standard input
looking for duplicated words. The program should find places in the input
where one word is followed immediately by itself. Keep track of the largest
number of times a single repetition occurs and which word is repeated. Print
the maximum number of duplicates, or else print a message saying that no
word was repeated.*/

int main(){
	std::map<std::string,int>table;
	std::string word;
	int max=0;
	std::string freq_w;
	while(std::cin>>word){
		auto it=table.end();
		if(table.find(word)!=it){
			int time=(++table.find(word)->second);
			if(max<time){
				max=time;
				freq_w=word;
			}
		}
		else{
			table.insert(std::pair<std::string,int>(word,1));
			if(max<1){
				max=1;
				freq_w=word;
			}
		}

	}
	std::cout<<"most occurred word: "<<freq_w<<" times: "<<max<<std::endl;
	return 0;









}
