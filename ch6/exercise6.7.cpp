#include<iostream>


/*Write a function that returns 0 when it is first called and then
generates numbers in sequence each time it is called again.*/



int sequence(){

	static int  seq_num=0;
	return seq_num++;


}






int main(){
	int time=0;
	std::cout<<"Please enter sequence length: "<<std::endl;
	std::cin>>time;
	for(int i=0;i!=time;++i)
		std::cout<<sequence()<<std::endl;

	return 0;


}









