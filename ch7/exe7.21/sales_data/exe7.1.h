#ifndef Sales_data_H
#define Sales_data_H
#include<iostream>

struct Sales_data {
	//constructor
	public:
	Sales_data()=default;
	Sales_data(const std::string& num):bookNo(num){};
	Sales_data(const std::string& num,int sold_num):bookNo(num),units_sold(sold_num){};
	Sales_data(const std::string& num,int sold_num,double price):bookNo(num),units_sold(sold_num),revenue(sold_num*price){};
	Sales_data(std::istream&is);
	//Sales_data& combine(Sales_data&);//combine two Sales_datas and return to the origin one
	std::string isbn() const{return this->bookNo;}//fetch bookNo
	Sales_data& toNext(Sales_data&) {return * this;}// change the bookinfo to the next object
	Sales_data& combine(Sales_data&);
	private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	
	//friend function
	friend  std::istream&read(std::istream&rstream, Sales_data&info);
	friend	std::ostream&print(std::ostream&pstream, Sales_data&info);
	friend  Sales_data add(const Sales_data&, const Sales_data&);//add two different info
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
	double price=0.0;
	rstream>>info.bookNo>>info.units_sold>>price;
	info.revenue+=price*info.units_sold;
	return rstream;
}

std::ostream&print(std::ostream&pstream, Sales_data&info){
	return pstream<<info.bookNo<<" "<<info.units_sold<<" "<<info.revenue;
}

Sales_data::Sales_data(std::istream&is){
	std::cout<<this->bookNo<<" "<<this->units_sold<<" "<<this->revenue<<std::endl;
	read(is,*this);

}

#endif
