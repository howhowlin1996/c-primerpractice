#include<iostream>
#include<vector>
/*exe 6.27Write a function that takes an initializer_list<int>
and produces the sum of the elements in the list.*/


int sum(std::initializer_list<int> li){
	int total=0;
	for( auto ele:li)
		total+=ele;
	return total;

}



int main(){
	std::cout<<sum({1,2,3,4,5,6})<<std::endl;
	return 0;


}
