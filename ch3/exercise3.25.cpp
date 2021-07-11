/*grade cluster using iterator c++ primer 5th edition exe 3.25*/
#include<iostream>
#include<vector>



int main(){
	std::cout<<"Please key in grade and split them by whitespace. Program will cluster them. : "<<std::endl;
	int grade;
	std::vector<int>grade_t;// remember every input grade
	std::vector<int>cluster_t(11,0);// remember cluster number

	while(std::cin>>grade)
		grade_t.push_back(grade);

	auto clu_beg=cluster_t.begin(); //to remember head in cluster table

	for(auto beg=grade_t.begin(),end=grade_t.end();beg!=end;++beg){
		int clu_pos=*beg/10; //decide each grade's cluster
	        if(*beg<=100&&*beg>=0)
			*(clu_beg+clu_pos)+=1;
	}

	for(auto ele:cluster_t)
		std::cout<<ele<<" ";
	
	return 0;





}
