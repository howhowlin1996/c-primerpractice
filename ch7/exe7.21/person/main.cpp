#include<iostream>
#include"Person.h"
using std::cin;
using std::cout;
using std::endl;



int main(){
	Person p1;
  	Person p2("aaa");
	Person p3("aaa","bbb");
	cout<<"name"<<p1.getName()<<" "<<" addree "<<p1.getAddress()<<endl;
	cout<<"name"<<p2.getName()<<" "<<" addree "<<p2.getAddress()<<endl;
	cout<<"name"<<p3.getName()<<" "<<" addree "<<p3.getAddress()<<endl;
	return 0;
}
