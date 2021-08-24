#ifndef Person_H
#define Person_H
#include<string>
struct Person{

std::string getAddress() const{return this->address;}
std::string getName() const{return this->name;}

std::string address;
std::string name;
};



#endif
