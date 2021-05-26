#include<iostream>
#include<vector>

void print_adjacent(std::vector<int>&table){
	if(table.size()<2)
		return;
	for(auto beg=table.begin(),end=table.end();beg!=end-1;++beg)                  std::cout<<*beg+*(beg+1)<<" ";
        std::cout<<std::endl;
}


void print_headandend(std::vector<int>&table){
	 if(table.size()<2)
	 	return;
	 for(auto beg=table.begin(),end=table.end()-1,mid=beg+(end-beg)/2;beg<=end;++beg,--end)
                  std::cout<<*beg+*end<<" ";


}


int main(){
	using std::vector;
	vector<int>table;
	int ele;
	std::cout<<"Please enter in numbers. We will calculate adjacent sum and head+tail sum(if the size of array<2, it will print nothing): "<<std::endl;
	while(std::cin>>ele)
		table.push_back(ele);
	print_adjacent(table);
	print_headandend(table);
	return 0;
}
