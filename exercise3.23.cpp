#include<iostream>
#include<vector>




int main(){
	int ele;
	int count=0;
	std::vector<int>table;
	while(std::cin>>ele){
		++count;
		table.push_back(ele);
		if(count==10)
			break;
	}
	for(auto it=table.begin();it!=table.end();++it)
		*it*=2;
	for(auto ele:table)
		std::cout<<ele<<" ";



	return 0;

}
