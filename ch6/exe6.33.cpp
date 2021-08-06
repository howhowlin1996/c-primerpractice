#include<iostream>
#include<vector>
/*Write  recursive function to print the contents of a vector.*/


void print(std::vector<int>& vec,int pos){
	if(pos>=0){
		int next=pos-1;
		print(vec,next);
		std::cout<<vec[pos]<<" ";
	}
	else{
		std::cout<<std::endl;
		return;
	}
	



}



int main(){
	std::vector<int> vec1={1,2,3,4,5,6,7,8,9};
	std::vector<int> vec2={};
	std::vector<int> vec3={2,2,3,4,5,6,7,8,9};
	print(vec1,vec1.size()-1);
	print(vec2,vec2.size()-1);
	print(vec3,vec3.size()-1);

	return 0;
}
