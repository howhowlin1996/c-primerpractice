#include<iostream>
#include<vector>


/*Given two vectors of ints, write a program to determine
whether one vector is a prefix of the other. For vectors of unequal
length, compare the number of elements of the smaller vector. For
example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5,
8, respectively your program should return true.*/

void readVec(std::vector<int>&vec1,std::vector<int>&vec2){
	//read two vector	
	std::cout<<" vector prefix detection: "<<" please insert 'e' at the end of each vectors "<<" first vector: "<<std::endl;
	int input;
	char x;
	while(std::cin>>input)
		vec1.push_back(input);
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	while(std::cin>>input)
		vec2.push_back(input);


}

bool comparePrefix(std::vector<int> longVec,std::vector<int> shortVec){
	for(int i=0;i!=shortVec.size();++i){
		if(longVec[i]!=shortVec[i])
			return false;
	}

	return true;
}

int main(){
	std::vector<int> vec1,vec2;
	readVec(vec1,vec2);
	if(vec1.size()>=vec2.size()){
		if(comparePrefix(vec1,vec2))
			std::cout<<"true"<<std::endl;
		else
			std::cout<<"flase"<<std::endl;
	}
	else{
		
		if(comparePrefix(vec2,vec1))
			std::cout<<"true"<<std::endl;
		else
			std::cout<<"flase"<<std::endl;
	}
			
	return 0;
}
