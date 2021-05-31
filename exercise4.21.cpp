/*Write a program to use a conditional operator to find the
elements in a vector<int> that have odd value and double the value of
each such element*/
#include<iostream>
#include<vector>


int main(){
	std::vector<int>num;
	int ele;
	while(std::cin>>ele)
		num.push_back(ele);
	for(auto &ele:num)
		ele%2==1?ele*=2:ele;
	for(auto ele:num)
		std::cout<<ele<<" ";
	std::cout<<std::endl;






	return 0;
}
