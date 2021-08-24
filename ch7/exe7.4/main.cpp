#include<iostream>
#include"Person.h"
using std::cin;
using std::cout;
using std::endl;



int main(){
	Person p1;
	p1.address="one road two street";
	p1.name="howhowLin";
	cout<<"name"<<p1.getName()<<" "<<" addree "<<p1.getAddress()<<endl;
	return 0;
}
