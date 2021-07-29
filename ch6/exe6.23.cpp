#include<iostream>
/*exe6.23 Write your own versions of each of the print functions
presented in this section. Call each of these functions to print i and j
defined as follows:
int i = 0, j[2] = {0, 1};*/


void print(const int a){
	
	std::cout<<a<<std::endl;

}

void print(const int a[],const int size){
	for(int i=0;i!=size;++i)
		std::cout<<*(a++)<<" ";
	std::cout<<std::endl;



}



int main(){
	int i=0;
	int j[2]={0,1};
	int k[3]={0,1,2};
	print(i);
	print(j,std::end(j)-std::begin(j));
	print(k,std::end(k)-std::begin(k));


}
