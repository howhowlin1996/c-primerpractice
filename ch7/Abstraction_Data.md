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

### Constructors

* Classes control object initialization by defining one or more special member functions known as constructors.

* The job of a constructor is to initialize the data members of a class object. A constructor is run whenever an object of a class type is created.

* Constructors have the same name as the class.

* Unlike other functions, constructors have no return type.

* Like other functions, constructors have a (possibly empty) parameter list and a (possibly empty) function body.

* A class can have multiple constructors.

* Unlike other member functions, constructors may not be declared as const.

* When we create a const object of a class type, the object does not assume its constness until after the constructor completes the object掇 initialization.

* Thus, constructors can write to const objects during their construction.

* Classes control default initialization by defining a special constructor, known as the default constructor.

* The default constructor is one that takes no arguments.

* If our class does not explicitly define any constructors, the compiler will implicitly define the default constructor for us.

*  The compiler-generated constructor is known as the synthesized default constructor.

	* If there is an in-class initializer, use it to initialize the member.

	* Otherwise, default-initialize the member.

### Some Classes Cannot Rely on the Synthesized Default Constructor

* If we define any constructors, the class will not have a default constructor unless we define that constructor ourselves.

* The basis for this rule is that if a class requires control to initialize an object in one case, then the class is likely to require control in all cases.

* The compiler generates a default constructor automatically only if a classdeclares no constructors.

* A second reason to define the default constructor is that for some classes, the synthesized default constructor does the wrong thing.

	* e.g. array and pointer will be undefined

* Classes that have members of built-in or compound type usually should rel y on the synthesized default constructor only if all such members have in-class initializers.

* A third reason that some classes must define their own default constructor is that sometimes the compiler is unable to synthesize one.

	* For example, if a class has a member that has a class type, and that class doesn't have a default constructor, then the compiler can掐 initialize that member.


## Defining the Sales_data Constructors

```c++
struct Sales_data {
	// constructors added
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
	bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);
	// other members as before
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

```

### What = default Means

```c++
Sales_data() = default;
```

* This constructor defines the default constructor because it takes no arguments.

* Under the new standard, if we want the default behavior, we can ask the compiler to generate the constructor for us by writing = default after the parameter list.

* The default constructor works for Sales_data only because we provide initializers for the data members with built-in type.

* If your compiler does not support in-class initializers, your default constructor should use the constructor initializer list (described immediately following) to initialize every member of the class.

* Like any other function, if the = default appears inside the class body, the default constructor will be inlined; if it appears on the definition outside the class, the member will not be inlined by default.

### Constructor Initializer List

* This new part is a constructor initializer list, which specifies initial values for one or more data members of the object being created.

```c++
Sales_data(const std::string &s): bookNo(s) { }
```

* The constructor that has a single string parameter uses that string to initialize bookNo but does not explicitly initialize the units_sold and revenue members.

* When a member is omitted from the constructor initializer list, it is implicitly initialized using the same process as is used by the synthesized default constructor.

* equal to :

```c++
// has the same behavior as the original constructor defined above
Sales_data(const std::string &s):
bookNo(s), units_sold(0), revenue(0){ }
```

```c++
Sales_data(const std::string &s, unsigned n, double p):
bookNo(s), units_sold(n), revenue(p*n) { }
```

* The constructor initializer is a list of member names, each of which is followed by that member掇 initial value in parentheses (or inside curly braces).

* Multiple member initializations are separated by commas.

* Constructors should not override in-class initializers except to use a different initial value.

* If you can掐 use in-class initializers, each constructor should explicitly initialize every member of built-in type.

### Defining a Constructor outside the Class Body

* Unlike our other constructors, the constructor that takes an istream does have work to do.

```c++
Sales_data::Sales_data(std::istream &is)
{
	read(is, *this); // read will read a transaction from is into this object
}
```

* Constructors have no return type, so this definition starts with the name of the function we are defining.

* Sales_data::Sales_data says that we're defining the Sales_data member named Sales_data.

* Even though the constructor initializer list is empty, the members of this object are still initialized before the constructor body is executed.

* Members that do not appear in the constructor initializer list are initialized by the corresponding in-class initializer (if there is one) or are default initialized.


## Copy, Assignment, and Destruction

* Objects are assigned when we use the assignment operator .

* Objects are destroyed when they cease to exist, such as when a local object is destroyed on exit from the block in which it was created .

* Objects stored in a vector (or an array) are destroyed when that vector (or array) is destroyed.

* If we do not define these operations, the compiler will synthesize them for us.

### Some Classes Cannot Rely on the Synthesized Versions

* It is important to understand that for some classes the default versions do not behave appropriately.

* In particular, the synthesized versions are unlikely to work correctly for classes that allocate resources that reside outside the class objects themselves.

	* i.e. dynamic memory

* However, it is worth noting that many classes that need dynamic memory can (and generally should) use a vector or a string to manage the necessary storage.

* Moreover, the synthesized versions for copy, assignment, and destruction work correctly for classes that have vector or string members.


