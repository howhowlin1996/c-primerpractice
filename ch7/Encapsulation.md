# Access Control and Encapsulation

* In C++ we use access specifiers to enforce encapsulation:

	* Members defined after a public specifier are accessible to all parts of the program. The public members define the interface to the class.

	* Members defined after a private specifier are accessible to the member functions of the class but are not accessible to code that uses the class. The private sections encapsulate (i.e., hide) the implementation.

```c++
class Sales_data {
	public: // access specifier added
		Sales_data() = default;
		Sales_data(const std::string &s, unsigned n, double p):
		bookNo(s), units_sold(n), revenue(p*n) { }
		Sales_data(const std::string &s): bookNo(s) { }
		Sales_data(std::istream&);
		std::string isbn() const { return bookNo; }
		Sales_data &combine(const Sales_data&);
	private: // access specifier added
		double avg_price() const
			{ return units_sold ? revenue/units_sold : 0; }
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
};
```

* The constructors and member functions that are part of the interface.

* The data members and the functions that are part of the implementation follow the private specifier.

### Using the class or struct Keyword

* The only difference between struct and class is the default access level.

* If we use the struct keyword, the members defined before the first access specifier are public.

* If we use class, then the members are private.

* Now that the data members of Sales_data are private, our read, print, and
add functions will no longer compile.

	* The problem is that although these functions are part of the Sales_data interface, they are not members of the class.

*  A class can allow another class or function to access its nonpublic members by making that class or function a friend.


```c++
class Sales_data {
	// friend declarations for nonmember Sales_data operations added
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	// other members and access specifiers as before
	public:
		Sales_data() = default;
		Sales_data(const std::string &s, unsigned n, double p):
		bookNo(s), units_sold(n), revenue(p*n) { }
		Sales_data(const std::string &s): bookNo(s) { }
		Sales_data(std::istream&);
		std::string isbn() const { return bookNo; }
		Sales_data &combine(const Sales_data&);
	private:
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
};
// declarations for nonmember parts of the Sales_data interface
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
```

* Friend declarations may appear only inside a class definition.

* Friends are not members of the class and are not affected by the access control of the section in which they are declared.

* Ordinarily it is a good idea to group friend declarations together at the beginning or end of the class definition.

### Key Concept: Benefits of Encapsulation

* Encapsulation provides two important advantages:
	
	* User code cannot inadvertently corrupt the state of an encapsulated object.

	* The implementation of an encapsulated class can change over time without requiring changes in user-level code.

* Another advantage of making data members private is that the data are protected from mistakes that users might introduce.

	* Only code that is part of the implementation could be responsible for the error.

	* The search for the mistake is limited, greatly easing the problems of maintenance and program correctness.

### Declarations for Friends

* To make a friend visible to users of the class, we usually declare each friend (outside the class) in the same header as the class itself.


