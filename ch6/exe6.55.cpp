#include<iostream>
#include<vector>
/*exe6.55 Write four functions that add, subtract, multiply, and divide
two int values. Store pointers to these values in your vector from the
previous exercise.*/

void add(int a,int b){
	std::cout<<"a+b= "<<a+b<<std::endl;
}

void sub(int a,int b){
	std::cout<<"a-b= "<<a-b<<std::endl;
}
void mult(int a,int b){
	std::cout<<"a*b= "<<a*b<<std::endl;
}
void divide(int a,int b){
	std::cout<<"a/b= "<<a/b<<std::endl;
}



int main(){
	std::vector<void (*)(int a,int b)>fun;
	fun.push_back(add);
	fun.push_back(sub);
	fun.push_back(mult);
	fun.push_back(divide);
	int a=0,b=0;
	std::cin>>a>>b;
	for(auto const & ele :fun)
		ele(a,b);
	return 0;
}
