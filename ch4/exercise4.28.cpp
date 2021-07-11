/*exe4.28 Write a program to print the size of each of the built-in
types.*/

#include<iostream>
#include<vector>


int main(){
	//exe4.28
	double d;
	std::cout<<"char: "<<sizeof('a')<<std::endl;
	std::cout<<"char16_t: "<<sizeof(u'a')<<std::endl;
	std::cout<<"char32_t: "<<sizeof(U'a')<<std::endl;
	std::cout<<"wchar_t: "<<sizeof(L'a')<<std::endl;
	std::cout<<"int: "<<sizeof(1)<<std::endl;
	std::cout<<"unsigned int: "<<sizeof(1u)<<std::endl;
	std::cout<<"long: "<<sizeof(1l)<<std::endl;
	std::cout<<"long long:"<<sizeof(1ll)<<std::endl;
	std::cout<<"float: "<<sizeof(1.0f)<<std::endl;
	std::cout<<"double: "<<sizeof(d)<<std::endl;
	std::cout<<"long double: "<<sizeof(1.0l)<<std::endl;
         
	//exe4.29
	int x[10]; int *p = x;
	std::cout << sizeof(x)/sizeof(*x) <<std::endl;
	std::cout<<sizeof(p)/sizeof(*p)<<std::endl;
	
	//exe4.31
	std::vector<int>ivec (10,0);
	std::vector<int>::size_type cnt = ivec.size();
	// assign values from size... 1 to the elements in ivec
	for(std::vector<int>::size_type ix = 0;ix != ivec.size(); ++ix, --cnt)
		ivec[ix] = cnt;
	for(auto exe:ivec)
		std::cout<<exe<<" ";
	std::cout<<std::endl;
	
	  std::vector<int>ivec1 (10,0);
	  cnt = ivec1.size();

	for(std::vector<int>::size_type ix = 0;ix != ivec1.size(); ++ix, --cnt)
		ivec1[ix] = cnt;
	for(auto exe:ivec1)
		std::cout<<exe<<" ";
         std::cout<<std::endl;
	return 0;



}
