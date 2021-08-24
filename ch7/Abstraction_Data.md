# Class

* Fondamental ideas:
	
	* data abstraction

	* encapsulation

## Data Abstraction

* Data abstraction: a programming (and design) technique that relies on the separation of interface and implementation.

* Interface: consists of the operations that users of the class can execute.

* Implememtation: includes 
	* the class’ data members

	* the bodies of the functions that constitute the interface

	* any functions needed to define the class that are not intended for general use

* Encapsulation: enforces the separation of a classinterface and implementation

* A class that uses data abstraction and encapsulation defines an abstract data type.

* Class designers: worries about how the class is implemented

* Programmers: use the class without nowing how the type works
	
	* They can instead think abstractly about what the types does.

### Defining Abstract Data Types

* Try to build a Sale_data class:
	
	* An isbn member function to return the object’s ISBN

	* A combine member function to add one Sales_data object into another

	* A function named add to add two Sales_data objects

	* A read function to read data from an istream into a Sales_data object

	* A print function to print the value of a Sales_data object on an ostream


### Sales-data Class

```c++
struct Sales_data {
	// new members: operations on Sales_data objects
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	// data members are unchanged from § 2.6.1 (p. 72)
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
```

* As we've seen, our class will also have two member functions, combine and isbn.

	* Member functions must be declared inside the class.

	* Member functions may be defined inside the class itself or outside the class body.

* Nonmember functions that are part of the interface, such as add, read, and print, are declared and defined outside the class.

* This function, which we'll name avg_price, isn't intended for general use. It will be part of the implementation, not part of the interface.

* Functions defined in the class are implicitly inline.


```c++
std::string isbn() const { return bookNo; }
```

* The interesting thing about this function is how it gets the object from which to fetch the bookNo member.

```c++
total.isbn()//call of function isbn
```

* In this call, when isbn returns bookNo, it is implicitly returning total.bookNo.

* Member functions access the object on which they were called through an extra, implicit parameter named this.

* The compiler passes the address of total to the implicit this parameter in isbn.

```c++
// pseudo-code illustration of how a call to a member function is translated
Sales_data::isbn(&total)
```

* Any direct use of a member of the class is assumed to be an implicit reference through this.

* That is, when isbn uses bookNo, it is implicitly using the member to whichthis points. It is as if we had written this->bookNo.

```c++
std::string isbn() const { return this->bookNo; }
```

* this is a comst pointer.

### Introducing const Member Functions

* The other important part about the isbn function is the keyword const that follows the parameter list.

```c++
std::string isbn() const { return bookNo; }
```

* The purpose of that const is to modify the type of the implicit this pointer.

```c++
// pseudo-code illustration of how the implicit this pointer is used
// this code is illegal: we may not explicitly define the this pointer ourselves
// note that this is a pointer to const because isbn is a const member
std::string Sales_data::isbn(const Sales_data *const this)
{ return this->isbn; }
```

* The type of this is a const pointer to the nonconst version of the class type.

* Although this is implicit, it follows the normal initialization rules, which means that (by default) we cannot bind this to a const object.

* The fact that this is a pointer to const means that const member functions cannot change the object on which they are called.

* Thus, isbn may read but not write to the data members of the objects on which it is called.

* Objects that are const, and references or pointers to const objects, may call only const member functions.

* e.g.

```c++
#include<iostream>
using namespace std;

class Test {
	int value;
public:
	Test(int v = 0) {value = v;}
	int getValue() {return value;}
};

int main() {
	const Test t;
	cout << t.getValue();
	return 0;
}
```

```
passing 'const Test' as 'this' argument of 'int
Test::getValue()' discards qualifiers
```

```c++
// Demonstration of constant object,
// show that constant object can only
// call const member function
#include<iostream>
using namespace std;
class Demo
{
	int value;
	public:
	Demo(int v = 0) {value = v;}
	void showMessage()
	{
		cout<<"Hello World We are Tushar, "
		"Ramswarup, Nilesh and Subhash Inside"
		" showMessage() Function"<<endl;
	}
	void display()const
	{
		cout<<"Hello world I'm Rancho "
		"Baba Inside display() Function"<<endl;
	}
};
int main()
{
//Constant object are initialised at the time of declaration using constructor
	const Demo d1;
	//d1.showMessage();Error occurred if uncomment.
	d1.display();
	return(0);
}
```

```
OUTPUT : Hello world I'm Rancho Baba Inside display() Function
```

### Class Scope and Member Functions

* The compiler processes classes in two steps:

	* The member declarations are compiled first.
	
	* Then, the member function bodies are processed if any.
* Thus, member function bodies may use other members of their class regardless of where in the class those members appear.


### Defining a Member Function outside the Class

* As with any other function, when we define a member function outside the class body, the member's definition must match its declaration.

```c++
double Sales_data::avg_price() const {
if (units_sold)
	return revenue/units_sold;
else
	return 0;
}
```

* Once the compiler sees the function name, the rest of the code is interpreted as being inside the scope of the class.

* Thus, when avg_price refers to revenue and units_sold, it is implicitly referring to the avg_price refers to revenue and units_sold, it is implicitly referring to the members of Sales_data.

### Defining a Function to Return “This” Object

```c++
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold; // add the members of rhs into
	revenue += rhs.revenue; // the members of ''this'' object
	return *this; // return the object on which the function was called
}
```

```c++
total.combine(trans); // update the running total
```

```c++
units_sold += rhs.units_sold; // add the members of rhs into
```

* the effect is to add total.units_sold and trans.units_sold, storing the result back into total.units_sold.

* Ordinarily, when we define a function that operates like a built-in operator, our function should mimic the behavior of that operator.

* To return an lvalue, our combine function must return a reference.

* Because the left-hand operand is a Sales_data object, the return type is Sales_data&.

* Here the return statement dereferences this to obtain the object on which the function is executing. That is, for the call above, we return a reference tototal.


