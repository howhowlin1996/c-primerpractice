#ifndef Person_H
#define Person_H
#include<string>
using std::string;
struct Person{
	public:
		//constuctor
		Person()=default;
		Person(const string&add):address(add){};
		Person(const string&add, const string&name_input):address(add),name(name_input){};
		//function
		std::string getAddress() const{return this->address;}
		std::string getName() const{return this->name;}

	private:
		std::string address;
		std::string name;
};



#endif
