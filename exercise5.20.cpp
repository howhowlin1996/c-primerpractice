#include<iostream>
#include<string>
#include<map>


/*Write a program to read a sequence of strings from the
standard input until either the same word occurs twice in succession or all
the words have been read. Use a while loop to read the text one word at a
time. Use the break statement to terminate the loop if a word occurs twice
in succession. Print the word if it occurs twice in succession, or else print a
message saying that no word was repeated.*/

void checkRepeated(){
	std::map<std::string,int> table;
	std::string word;
	bool repeat=false;  //flag to remember whether repeat occirs or not
	while(std::cin>>word){
		if(table.find(word)!=table.end()){
			std::cout<<word<<" occurs twice."<<std::endl;
			repeat=true;
			break;
		}
		else{
			table.insert(std::pair<std::string,int>(word,0));
		}
	}
	if(!repeat)
		std::cout<<"no words was repeated"<<std::endl;


}




int main(){
	std::cout<<"please type a paragraph, I'll check if there is a repeated words"<<std::endl;
	checkRepeated();
}
