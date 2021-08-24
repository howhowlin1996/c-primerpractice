#ifndef Sales_data_H
#define Sales_data_H
#include<iostream>

struct Sales_data {
	//Sales_data& combine(Sales_data&);//combine two Sales_datas and return to the origin one
	std::string isbn() const{return this->bookNo;}//fetch bookNo
	Sales_data& toNext(Sales_data&) {return * this;}// change the bookinfo to the next object
	Sales_data& combine(Sales_data&);
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	

};

std::istream&read(std::istream&, Sales_data&); //read info
std::ostream&print(std::ostream&,Sales_data&); //print info
Sales_data add(const Sales_data&, const Sales_data&);//add two different info


Sales_data& Sales_data::combine(Sales_data&newBook){
	this->units_sold+=newBook.units_sold;
	this->revenue+=newBook.revenue;
	return *this;
}

std::istream&read(std::istream&rstream, Sales_data&info){
	return rstream>>info.bookNo>>info.units_sold>>info.revenue;
}

std::ostream&print(std::ostream&pstream, Sales_data&info){
	return pstream<<info.bookNo<<" "<<info.units_sold<<" "<<info.revenue;
}


#endif
