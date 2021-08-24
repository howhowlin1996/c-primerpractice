#include<iostream>
#include<vector>
#define NDEBUG "off"
/*Revise the program you wrote in the exercises in § 6.3.2 (p.
228) that used recursion to print the contents of a vector to conditionally
print information about its execution. For example, you might print the size of
the vector on each call. Compile and run the program with debugging
turned on and again with it turned off.*/



void print(std::vector<int> print_vec,int  pos){
	std::cout<<print_vec[pos]<<" ";
	#ifndef NDEBUG
	std::cerr<<__func__<<" "<<__FILE__<<" "<<__LINE__<<" "<<__TIME__<<" "<<__DATE__<<" "<<": array position is "<<pos<<std::endl;
	#endif
	if(pos<print_vec.size()-1)
		print(print_vec,++pos);
	



}



int main(){
	std::vector<int> a={1,2,3,4,5};
	print(a,0);
	return 0;



}
