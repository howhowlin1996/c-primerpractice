#include<iostream>
#include<vector>
/*exercise 3.31 & 3.32*/


int main(){
	//3.31 initiate 10 integers array and each elemants is their position 
	constexpr int  size=10;
	int table[10];
	for(size_t i=0;i!=10;++i)
		table[i]=i;
	
	//3.32 use vetor to duplicate above array
	std::vector<int>copy;
	for(auto ele:table){
		copy.push_back(ele);
	}
	//verify them
	for(size_t i=0;i!=10;++i)
		std::cout<<copy[i]<<" "<<table[i]<<" ";



	return 0;
}
