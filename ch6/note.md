# 6.1. Function Basics

## Argument v.s. Parameter
```c++
int main()					
{				
	int j = fact(5); // ()-> call operator, 5->argument	
	cout << "5! is " << j << endl;
	return 0;
}
```
```c++
// factorial of val is val * (val - 1) * (val - 2) . . . * ((val - (val - 1)) * 1)
int fact(int val) //val->parameter
{
	int ret = 1; // local variable to hold the result as we calculate it
	while (val > 1)
		ret *= val--; // assign ret * val to ret and decrement val
	return ret; // return the result
}
```


## Function Execution
* 1.parameters be created and initialize
* 2.execution operation inside the block
* 3.return statement
	* a.return the value
	* b.transfer contro; out of called function back to the calling ones


```c++
// factorial of val is val * (val - 1) * (val - 2) . . . * ((val - (val - 1)) * 1)
int fact(int val)
{
	int ret = 1; // local variable to hold the result as we calculate it
	while (val > 1)
		ret *= val--; // assign ret * val to ret and decrement val
	return ret; // return the result
}
```
```c++
int val = 5; // initialize val from the literal 5
int ret = 1; // code from the body of fact
while (val > 1)
	ret *= val--;
int j = ret; // initialize j as a copy of ret
```

## Function Parameters can be empty:
```c++
void f1(){ /* ... */ } // implicit void parameter list
```
```c++
void f2(void){ /* ... */ } // explicit void parameter list
```

## Even when the types of two parameters are the same, we still need to initialize it with type:
```c++
int f3(int v1, v2) { /* ... */ } // error
```
```c++
int f4(int v1, int v2) { /* ... */ } // ok
```

##### Function return type can't be array type, we use pointer to substitute it.

##### Automatic objects:Objects that exist only while a block is executing.After execution exists a block, the values of them in the block are undefined.(e.g parameters)
##### Automatic objects corresponding to the function parameters are initialized by the arguments passed to the function.

## Local static objects:
* 1.lifetime can continue across calls to the function
* 2.initialized when first time execution
* 3.destroyed when the program terminates

* e.g. :
```c++
size_t count_calls()
{
	static size_t ctr = 0; // value will persist across calls
	return ++ctr;
}
int main()
{
	for (size_t i = 0; i != 10; ++i)
		cout << count_calls() << endl;
	return 0;
}
```
## Local Variable
###### A local variable is a variable defined inside the function scope.

* The scope of a local variable is the function body.
* The lifetime of the ordinary local variable (nonstatic) starts when control passes through the variable's definition, and ends when control passes through the end of the block in which the variable is defined.
* It is initialized if its definition contains an initializer, otherwise, it is default initialized.

## Parameter
##### A parameter is also a local variable, but the definition is in the parameter list of the function.

* The scope of a parameter is the same as local variable, which is the function body.
* The lifetime of the parameter starts when the function begins, and ends when the function terminates.
* It is initialized by the arguments passed to the function.

## Static Variable
##### A local static variable is a local variable that defined with static keyword. It has a lifetime much longer than usual local variable.

* The scope of a local static variable is the same as local variable, which is the function body.
* The lifetime of the local static varible starts when the first time control passes through the variable's definition, and ends when the program terminates.
* It is initialized if its definition contains an initializer, otherwise, it is value initialized.
* For example,
```c++
int foo(int param) {
  int lv;
  static int lsv = 1;
  lv = param + lsv;
  ++lsv;
  return lv;
}
```

##### every time the function foo is called, it will add how many times it has been called to the argument and return the sum.

## Function Declarations

##### A function declaration is just like a function definition except that a declaration has no function body. In a declaration, a semicolon replaces the function body. 

##### Because a function declaration has no body, there is no need for parameter names.

```c++
// parameter names chosen to indicate that the iterators denote a range of values to print
void print(vector<int>::const_iterator beg,
vector<int>::const_iterator end);
```
```c++
// without parameter name is ok
void print(vector<int>::const_iterator ,
vector<int>::const_iterator );
```

##### Function declarations are also known as the function <font color=#0000FF>**prototype**</font>.

## Header File
##### Classes are usually defined in header files.
##### Headers (usually) contain entities (such as class definitions and const and constexpr variables) that can be defined only once in any given file.
##### The most common technique for making it safe to include a header multiple times relies on the preprocessor.
##### C++ programs also use the preprocessor to define header guards. Header guards rely on preprocessor variables.

#### #ifdef/#ifndef
* #ifdef
	is true if the variable has been defined
* #ifndef
	is true if the variable has not been defined

* e.g. :

```c++
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
#endif
```
##### Preprocessor variables usually are written in all uppercase.


## Sperate Compilation

##### Separate compilation lets us split our programs into several files, each of which can be compiled independently.

##### fact.cc->fact function Chapter6.h.->declararction of fact function factMain.exe-> main function

##### To produce an executable file, we must tell the compiler where to find all of the code we use.

* e.g. :

``` bash
$ CC factMain.cc fact.cc # generates factMain.exe or a.out
$ CC factMain.cc fact.cc -o main # generates main or
main.exe
```

##### CC->name of compiler $->system prompt #->begins a command-line comment

##### This process usually yields a file with the .obj (Windows) or .o (UNIX) file extension, indicating that the file contains object code.

##### The compiler lets us link object files together to form an executable.

* On the system we use, we would separately compile our program as follows:

```bash
$ CC -c factMain.cc # generates factMain.o
$ CC -c fact.cc # generates fact.o
$ CC factMain.o fact.o # generates factMain.exe or a.out
$ CC factMain.o fact.o -o main # generates main or main.exe
```


