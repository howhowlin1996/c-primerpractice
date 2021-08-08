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
	* b.transfer control; out of called function back to the calling ones


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

* If we changed one of our source codes, we would like to change only the file that actually cahnged
* We can yields .o so that next time we can only recompile tje changed file.
* The compiler let us link different .o files together.
```bash
$ CC -c factMain.cc # generates factMain.o
$ CC -c fact.cc # generates fact.o
$ CC factMain.o fact.o # generates factMain.exe or a.out
$ CC factMain.o fact.o -o main # generates main or main.exe
```

## The process of c++ compilation

* Preprocessing: the preprocessor deals with #include, #define...... preprocessor directives.The it yields a pure c++ file.
* Compilation: the compiler takes the pre-processsor's output and prouces an object file from it.
* Linking: the liker takes all of the object files and produces either a library or an executable file.

![image](https://github.com/howhowlin1996/c-primerpractice/blob/main/ch6/c%2B%2B%20compilation.png)
![image](https://github.com/howhowlin1996/c-primerpractice/blob/main/ch6/c%2B%2B%20compilation%20detail.jpeg)

* Preprocessing:

>The preprocessor handles the preprocessor directives, like #include and #define. It is agnostic of the syntax of C++, which is why it must be used with care.

>It works on one C++ source file at a time by replacing #include directives with the content of the respective files (which is usually just declarations), doing replacement of macros (#define), and selecting different portions of text depending of #if, #ifdef and #ifndef directives.

>The preprocessor works on a stream of preprocessing tokens. Macro substitution is defined as replacing tokens with other tokens (the operator ## enables merging two tokens when it makes sense).

>After all this, the preprocessor produces a single output that is a stream of tokens resulting from the transformations described above. It also adds some special markers that tell the compiler where each line came from so that it can use those to produce sensible error messages.

>Some errors can be produced at this stage with clever use of the #if and #error directives.


* Compilation:

>The compilation step is performed on each output of the preprocessor. The compiler parses the pure C++ source code (now without any preprocessor directives) and converts it into assembly code. Then invokes underlying back-end(assembler in toolchain) that assembles that code into machine code producing actual binary file in some format(ELF, COFF, a.out, ...). This object file contains the compiled code (in binary form) of the symbols defined in the input. Symbols in object files are referred to by name.

>Object files can refer to symbols that are not defined. This is the case when you use a declaration, and don't provide a definition for it. The compiler doesn't mind this, and will happily produce the object file as long as the source code is well-formed.

>Compilers usually let you stop compilation at this point. This is very useful because with it you can compile each source code file separately. The advantage this provides is that you don't need to recompile everything if you only change a single file.

>The produced object files can be put in special archives called static libraries, for easier reusing later on.

>It's at this stage that "regular" compiler errors, like syntax errors or failed overload resolution errors, are reported.


* Linking:

>The linker is what produces the final compilation output from the object files the compiler produced. This output can be either a shared (or dynamic) library (and while the name is similar, they haven't got much in common with static libraries mentioned earlier) or an executable.

>It links all the object files by replacing the references to undefined symbols with the correct addresses. Each of these symbols can be defined in other object files or in libraries. If they are defined in libraries other than the standard library, you need to tell the linker about them.

>At this stage the most common errors are missing definitions or duplicate definitions. The former means that either the definitions don't exist (i.e. they are not written), or that the object files or libraries where they reside were not given to the linker. The latter is obvious: the same symbol was defined in two different object files or libraries.

## Argument Passing

* Passed by reference/Called by reference:
	* When a parameter is a reference, we will bount to its argument.

* Passed by value/Called by value:
	* When a parameter is not a reference, we will copy the argument value so that they are independent objects.

* Pointer Parameters:
	* When we copy a pointer, the value of the pointer is copied. After the copy, the two pointers are distinct but point to the same adress. Therefore, We can change the value of that object by assigning through the pointe.
	* e.g.:
```c++
int n = 0, i = 42;
int *p = &n, *q = &i; // p points to n; q points to i
*p = 42; // value in n is changed; p is unchanged
p = q; // p now points to i; values in i and n are
unchanged
```
```c++
// function that takes a pointer and sets the pointed-to value to zero
void reset(int *ip)
{
	*ip = 0; // changes the value of the object to which ip points
	ip = 0; // changes only the local copy of ip; the argument is unchanged
}
```
* After a call to reset, the object to which the argument points will be 0, but the pointer argument itself is unchanged:
```c++
int i = 42;
reset(&i); // changes i but not the address of i
cout << "i = " << i << endl; // prints i = 0
```
* Called by reference:
	* Reference parameters exploit this behavior. They are often used to allow a function to change the value of one or more of its arguments.
	* e,g,:
```c++
// function that takes a reference to an int and sets the given object to zero
void reset(int &i) // i is just another name for the object passed to reset
{
	i = 0; // changes the value of the object to which i refers
}
```

```c++
int j = 42;
reset(j); // j is passed by reference; the value in j is changed
cout << "j = " << j << endl; // prints j = 0
```

* The advantages called by reference:
	* more efficient than called by value in objects of large class types or large containers.
	* some class types can't be copied
	* A function can return only a single value. We can use it to return multiple value.

* Reference parameters that are not changed inside a function should be references to const.

* Level of const:
	* top-level const:indicate that the pointer itself is a const
		* e.g.: int*i=0,int *const p1=&i
	* low-level const:a pointer can point to a const object
		* e.g.: const int *p2=&ci,const int &r=ci

* const parameters:
	* Just as any other initialization, when we copy an argument to initialize a parameter, top-level consts are ignored.
	* We can pass either a const or nonconst objects to a parameter thathas a top-levle const.
	* We can defind several different functions that have the same name.However, they need to be sufficient difference.
	* e.g.:
	```c++
	void fcn(const int i) { /* fcn can read but not write to i */ }
	void fcn(int i) { /* . . . */ } // error: redefines fcn(int)
	```

	* Because top-level consts are ignored, we can pass exactly the same types to either version of fcn. The second version of fcn is an error.
	* We can initialize an object with a low-level const from a nonconst object but not vice versa, and a plain reference must be initialized from an object of the same type.

	* e.g.:
	```c++
	int i = 0;
	const int ci = i;
	string::size_type ctr = 0;
	reset(&i); // calls the version of reset that has an int* parameter
	reset(&ci); // error: can't initialize an int* from a pointer to a const int object
	reset(i); // calls the version of reset that has an int& parameter
	reset(ci); // error: can't bind a plain reference to the const object ci
	reset(42); // error: can't bind a plain reference to a literal
	reset(ctr); // error: types don't match; ctr has an unsigned type
	// ok: find_char's first parameter is a reference to const
	find_char("Hello World!", 'o', ctr);
	```

* Timing of using reference to const:
	* It is a somewhat common mistake to define parameters that a function does not change as (plain) references:
	* We cannot pass a const object, or a literal, or an object that requires conversion to a plain reference parameter.


## Built-in Arrays

##### Arrays are a compound type. a[d]->declarator form. a->name being defined. d->the dimension of the array

##### The dimension must be known at compile time, which means that the dimension must be a constant expression.

```c++
unsigned cnt = 42; // not a constant expression
constexpr unsigned sz = 42; // constant expression
// constexpr see § 2.4.4 (p. 66)
int arr[10]; // array of ten ints
int *parr[sz]; // array of 42 pointers to int
string bad[cnt]; // error: cnt is not a constant expression
string strs[get_size()]; // ok if get_size is constexpr, error otherwise
```

##### As with variables of built-in type, a default-initialized array of built-in type that is defined inside a function will have undefined values.

##### We can list initialize the elements. In this case, we can omit the dimension.

```c++
const unsigned sz = 3;
int ia1[sz] = {0,1,2}; // array of three ints with values 0, 1, 2
int a2[] = {0, 1, 2}; // an array of dimension 3
int a3[5] = {0, 1, 2}; // equivalent to a3[] = {0, 1, 2, 0, 0}
string a4[3] = {"hi", "bye"}; // same as a4[] = {"hi", "bye", ""}
int a5[2] = {0,1,2}; // error: too many initializers
```

##### Character arrays have an additional form of initialization: We can initialize such arrays from a string literal.

```c++
char a1[] = {'C', '+', '+'}; // list initialization, no null
char a2[] = {'C', '+', '+', '\0'}; // list initialization, explicit null
char a3[] = "C++"; // null terminator added
automatically
const char a4[6] = "Daniel"; // error: no space for the null!
//The dimension of a1 is 3; the dimensions of a2 and a3 are both 4.
```
##### We cannot initialize an array as a copy of another array, We cannot initialize an array as a copy of another array.

```c++
int a[] = {0, 1, 2}; // array of three ints
int a2[] = a; // error: cannot initialize one array with another
a2 = a; // error: cannot assign one array to another
```

##### Pointers, References, and Array

```c++
int *ptrs[10]; // ptrs is an array of ten pointers to int
int &refs[10] = /* ? */; // error: no arrays of references
int (*Parray)[10] = &arr; // Parray points to an array of ten ints
int (&arrRef)[10] = arr; // arrRef refers to an array of ten ints
int *(&arry)[10] = ptrs; // arry is a reference to an array of ten pointers
```

```c++
string *p2 = nums; // equivalent to p2 = &nums[0]
```

## Array and function

* These declarations are equivalent, all the argument has type const int * :
	
	```c++
	// each function has a single parameter of type const int*
	void print(const int*);
	void print(const int[]); // shows the intent that the function takes an array
	void print(const int[10]); // dimension for documentation purposes (atbest)
	```
	```c++
	int i = 0, j[2] = {0, 1};
	print(&i); // ok: &i is int*
	print(j); // ok: j is converted to an int* that points to j[0]
	```

* Because arrays are passed as pointers, functions ordinarily don’t know the size of the array they are given. They must rely on additional information provided by the caller. There are three common techniques used to manage pointer parameters.

	* Using a Marker to Specify the Extent of an Array:
		* The first approach to managing array arguments requires the array itself to contain an end marker. ex: C-style strings
		``` c++
		void print(const char *cp)
		{
		if (cp) // if cp is not a null pointer
			while (*cp) // so long as the character it points to is not a null character
		cout << *cp++; // print the character and advance the pointer
		}
		```
		* This convention works well for data where there is an obvious end-marker value (like the null character) that does not appear in ordinary data.
	
	* Using the Standard Library Conventions:
		* Past pointer begin and end into the function.
		```c++
		void print(const int *beg, const int *end)
		{
			// print every element starting at beg up to but not including end
			while (beg != end)
				cout << *beg++ << endl; // print the current element
			// and advance the pointer
		}
		```
	
	* Explicitly Passing a Size Parameter:
		```c++
		// const int ia[] is equivalent to const int* ia
		// size is passed explicitly and used to control access to elements of ia
		void print(const int ia[], size_t size)
		{
			for (size_t i = 0; i != size; ++i) {
				cout << ia[i] << endl;
			}
		}
		```
##### When a function does not need write access to the array elements, the array parameter should be a pointer to const.A parameter should be a plain pointer to a nonconst type only if the function needs to change element values.


* Array Reference Parameters
	* e.g.
	```c++
	// ok: parameter is a reference to an array; the dimension is part of the type
	void print(int (&arr)[10])
	{
		for (auto elem : arr)
		cout << elem << endl;
	}
	```
	* We may call this function only for an array of exactly ten ints:
	* e.g.
	```c++
	int i = 0, j[2] = {0, 1};
	int k[10] = {0,1,2,3,4,5,6,7,8,9};
	print(&i); // error: argument is not an array of ten ints
	print(j); // error: argument is not an array of ten ints
	print(k); // ok: argument is an array of ten ints
	```
* Multidimensional Array
	* The first dimension is usually referred to as the row and the second as the column.
	* e.g.
	```c++
	int ia[3][4] = { // three elements; each element is an array of size 4
		{0, 1, 2, 3}, // initializers for the row indexed by 0
		{4, 5, 6, 7}, // initializers for the row indexed by 1
		{8, 9, 10, 11} // initializers for the row indexed by 2
	};
	```
	
	* In the second example, we define row as a reference to an array of four ints. We bind that reference to the second row in ia.
	* e.g.
	```c++
	// assigns the first element of arr to the last element in the last row of ia
	ia[2][3] = arr[0][0][0];
	int (&row)[4] = ia[1]; // binds row to the second four-element array in ia
	```
	* Using a Range for with Multidimensional Array
	```c++
	size_t cnt = 0;
	for (auto &row : ia) // for every element in the outer array
		for (auto &col : row) { // for every element in the inner array
			col = cnt; // give this element the next value
			++cnt; // increment cnt
		}
	```
* Passing a Multidimensional Array
	* As with any array, a multidimensional array is passed as a pointer to its first element.That element is an array, so the pointer is a pointer to an array.	    
	* The size of the second (and any subsequent) dimension is part of the element type and must be specified:
	```c++
	// matrix points to the first element in an array whose elements are arrays of ten ints
	void print(int (*matrix)[10], int rowSize) { /* . . . */ }
	```
	```c++
	int *matrix[10];//array of ten pointers
	int (*matrix)[10]; //pointer to an array of ten ints
	```
	* We can also define our function using array syntax. As usual,the compiler ignores the first dimension, so it is best not to include it:
	```c++
	// equivalent definition
	void print(int matrix[][10], int rowSize) { /* . . . */ }
	```
	* In fact, the parameter is a pointer to an array of ten ints.

	* exe6.24: Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.
	
	```c++
	void print(const int ia[10])
	{
		for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
	}
	```

	* The function prototype is the same as void print(const int * ia), which means we can pass any pointer to int to the function, not only an array of ten ints. This will lead to an error. We can change the parameter to a reference to array:
	
	```c++
	void print(const int (&ia)[10]) { /* ... */ }
	```
## Main Function arguments:

* command line: ./a.out -d -o ofile data0
	
	```c++
	int main(int argc, char *argv[]) { ... }
	//or
	int main(int argc, char **argv) { ... }
	```
* result:

	```c++
	argv[0] = "./a.out"; // or argv[0] might point to an empty string
	argv[1] = "-d";
	argv[2] = "-o";
	argv[3] = "ofile";
	argv[4] = "data0";
	//length 5 string array		
	argv[5] = 0; //C-style string need '/0' at the end 

	```

* When you use the arguments in argv, remember that the optional arguments begin in argv[1]; argv[0] contains the program’s name, not user input.

## Functions with Varying Parametersi

* Two ways to realize varying parameters function:
	* initializer_list
	* variadic template(cover in 16.4)

* initializer_list:
	* An initializer_list is a library type that represents an array of values of the specified type.
	* When we define an initializer_list, we must specify the type of the elements that the list will contain.
	
	```c++
	initializer_list<string> ls; // initializer_list of strings
	initializer_list<int> li; // initializer_list of ints
	```

	* Unlike vector, the elements in an initializer_list are always const values; there is no way to change the value of an element in an initializer_list.
	* When we pass a sequence of values to an initializer_list parameter, we must enclose the sequence in curly braces.

	```c++
	void error_msg(initializer_list<string> il)
	{
		for (auto beg = il.begin(); beg != il.end(); ++beg)
			cout << *beg << " " ;
		cout << endl;
	}
	
	if (expected != actual)
		error_msg(ErrCode(42), {"functionX", expected, actual});
	else
		error_msg(ErrCode(0), {"functionX", "okay"});
	```

* Ellipsis Parameters ...
	
	* Ellipsis parameters should be used only for types that are common to both C and C++.
	* Using a C library facility named varargs. <cstdarg>
	* Taking a variable number of arguments.

	```c++
	// C++ program to demonstrate the
	// use of Ellipsis
	#include <cstdarg>
	#include <iostream>
	using namespace std;
	// Function accepting variable number
	// of arguments using Ellipsis
	double average(int count, ...)
	{
		// va_list found in <cstdarg> and
		// list is its type, used to
		// iterate on ellipsis
		va_list list;

		// Initialize position of va_list
		va_start(list, count);

		double avg = 0.0;

		// Iterate through every argument
		for (int i = 0; i < count; i++) {
			avg += static_cast<double>(va_arg(list, int))
				/ count;
		}

		// Ends the use of va_list
		va_end(list);

		// Return the average
		return avg;
	}

	// Driver Code
	int main()
	{
		// Function call
		double avg = average(6, 1, 2, 3, 4, 5, 6);

		// Print Average
		cout << "Average is " << avg;
		return 0;
	}
	```

	* va_list type is used to access the values in the ellipsis. It will be conceptually easy for you if you think of ellipsis as an array. In that case, va_list  will act as the iterator type. The va_list is not a special type. It is a macro definition.
	* va_start points to the va_list at the starting point of the ellipsis. It takes two arguments: va_list itself and the last normal parameter (non-ellipsis).
	* va_arg returns the value which va_list is currently referring to and also moves va_list to the next parameter. It also takes two arguments: va_list itself and the type of the parameter we are trying to access.
	* va_end takes only one argument: va_list itself. It is used to clean up the va_list macro.

	* When using ellipsis, the compiler does not check the type of arguments passed to the function. So the compiler does not throw any error if arguments are of different types.

## Functions with No Return Value

* A return with no value may be used only in a function that has a return type of void.

* Typically, void functions use a return to exit the function at an intermediate point. (like break statement to exit a loop)

* An implicit return occurs after the last assignment statement.

```c++
void swap(int &v1, int &v2)
{
	// if the values are already the same, no need to swap, just return
	if (v1 == v2)
		return;
	// if we're here, there's work to do
	int tmp = v2;
	v2 = v1;
	v1 = tmp;
	// no explicit return necessary
}
```

## Functions That Return a Value

* Every return in a function with a return type other than void must return a value.

* The value returned must have the same type as the function return type, or it must have a type that can be implicitly converted to that type.

* Failing to provide a return after a loop that contains a return is an error. However, many compilers will not detect such errors.

```c++
// incorrect return values, this code will not compile
bool str_subrange(const string &str1, const string &str2)
{
	// same sizes: return normal equality test
	if (str1.size() == str2.size())
		return str1 == str2; // ok: == returns bool
	// find the size of the smaller string; conditional operator
	auto size = (str1.size() < str2.size())? str1.size() : str2.size();
	// look at each element up to the size of the smaller string
	for (decltype(size) i = 0; i != size; ++i) {
		if (str1[i] != str2[i])
			return; // error #1: no return value; compiler should detect this error
	}
	// error #2: control might flow off the end of the function without a return
	// the compiler might not detect this error
}
```

## How Values Are Returned

* Values are returned in exactly the same way as variables and parameters are initialized: 
	* The return value is used to initialize a temporary at the call site, and that temporary is the result of the function call.

```c++
// return a reference to the shorter of two strings
const string &shorterString(const string &s1, const string
&s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}
```

* The parameters and return type are references to const string. The strings are not copied when the function is called or when the result is returned.

## Never Return a Reference or Pointer to a Local Object

* When a function completes, its storage is freed.After a function terminates, references to local objects refer to memory that is no longer valid:

```c++
// disaster: this function returns a reference to a local object
const string &manip()
{
	string ret;
	// transform ret in some way
	if (!ret.empty())
		return ret; // WRONG: returning a reference to a local object!
	else
	return "Empty"; // WRONG: "Empty" is a local temporary string
}

```

* One good way to ensure that the return is safe is to ask: To what preexisting
object is the reference referring?

## Functions That Return Class Types and the Call Operator

* If a function returns a pointer, reference or object of class type, we can use the result of a call to call a member of the resulting object.

```c++
// call the size member of the string returned by shorterString
auto sz = shorterString(s1, s2).size()
```

## Reference Returns Are Lvalues

```c++
char &get_val(string &str, string::size_type ix)
{
	return str[ix]; // get_val assumes the given index is valid
}
int main()
{
	string s("a value");
	cout << s << endl; // prints a value
	get_val(s, 0) = 'A'; // changes s[0] to A
	cout << s << endl; // prints A value
	return 0;
}
```

* If the return type is a reference to const, then (as usual) we may not assign to the result of the call:

```c++
shorterString("hi", "bye") = "X"; // error: return value is const
```

## List Initializing the Return Value

* If the list is empty, that temporary is value initialized. Otherwise, the value of the return depends on the function's return type.

```c++
vector<string> process()
{
	// . . .
	// expected and actual are strings
	if (expected.empty())
		return {}; // return an empty vector
	else if (expected == actual)
		return {"functionX", "okay"}; // return list-initialized vector
	else
		return {"functionX", expected, actual};
}
```
* In the first return statement, we return an empty list. In this case, the vector that process returns will be empty.

* Otherwise, we return a vector initialized with two or three elements depending on whether expected and actual.

* If returns a built-in type, a braced list may contain at most one value, and that value must not require a narrowing conversion.

* If returns a class type, then the class itself defines how the initializers are used.

```c++
long double ld = 3.1415926536;
int a{ld}, b = {ld}; // error: narrowing conversion required
int c(ld), d = ld; // ok: but value will be truncated
```

## Return from main

* Only exception function that can terminate without a return.

* The compiler will implicitly insert a return of 0.

*  A zero return indicates success; most other values indicate failure. A nonzero value has a machine-dependent meaning.

* The cstdlib header defines two preprocessor variables that we can use to indicate success or failure.

``` c++
int main()
{
	if (some_failure)
		return EXIT_FAILURE; // defined in cstdlib
	else
		return EXIT_SUCCESS; // defined in cstdlib
}
```

* Because these are preprocessor variables, we must not precede them with std::, nor may we mention them in using declarations.

## Recursion

* A function that calls itself, either directly or indirectly, is a recursive function.

```c++
// calculate val!, which is 1 * 2 * 3 . . . * val
int factorial(int val)
{
	if (val > 1)
		return factorial(val-1) * val;
	return 1;
}
```

* The main function may not call itself.

## Returning a Pointer to an Array

* We can't copy an array but we can with pointer or a reference to an array.

* We can use some methods to simplify the declaration of array.

```c++
typedef int arrT[10]; // arrT is a synonym for the type array of ten ints
using arrtT = int[10]; // equivalent declaration of arrT; see § 2.5.1 (p. 68)
arrT* func(int i); // func returns a pointer to an array of five ints
//func
is a function that takes a single int argument and returns a pointer to an array of ten ints.
```

* If without alias, we must remember the rule that declarate array.

```c++
int arr[10]; // arr is an array of ten ints
int *p1[10]; // p1 is an array of ten pointers
int (*p2)[10] = &arr; // p2 points to an array of ten ints
```
* Hence, the form of a function that returns a pointer to an array is:

```c++
Type (*function(parameter_list))[dimension]

int (*func(int i))[10];
```
* func(int) says that we can call func with an int argument.
* (*func(int)) says we can dereference the result of that call.
* (*func(int))[10] says that dereferencing the result of a call to func yields
an array of size ten.
* int (*func(int))[10] says the element type in that array is int.

### Using a Trailing Return Type

* Traiing Return Type: can be difined for any function, but are most useful for functions with complicated return types.

```c++
// fcn takes an int argument and returns a pointer to an array of ten ints
auto func(int i) -> int(*)[10];

```
* the return type comes after the parameter list, it is easier to see that fun returns a pointer and that that pointer points to an array of ten ints.

### Using decltype

```c++
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
// returns a pointer to an array of five int elements
decltype(odd) *arrPtr(int i)
{
	return (i % 2) ? &odd : &even; // returns a pointer to the array
}
```
* decltype does not automatically convert an array to its corresponding pointer type.

* The type returned by decltype is an array type, to which we must add a * to indicate that arrPtr returns a pointer.

## Overloaded functions
* Overloaded: functions that have the same name but with different parameters and in the same scope

```c++
void print(const char *cp);
void print(const int *beg, const int *end);
void print(const int ia[], size_t size);

int j[2] = {0,1};
print("Hello World"); // calls print(const char*)
print(j, end(j) - begin(j)); // calls print(const int*, size_t)
print(begin(j), end(j)); // calls print(const int*, const int*)
```

* The main function may not be overloaded.

* If the parameter lists of two functions match but the return types differ, then the second declaration is an error:

```c++
Record lookup(const Account&);
bool lookup(const Account&); // error: only the return type is different
```

* Two parameter lists can be identical, even if they don’t look the same:

```c++
// each pair declares the same function
Record lookup(const Account &acct);
Record lookup(const Account&); // parameter names are ignored

typedef Phone Telno;
Record lookup(const Phone&);
Record lookup(const Telno&); // Telno and Phone are the same type
```

* On the other hand, we can overload based on whether the parameter is a reference (or pointer) to the const or nonconst version of a given type; such consts are low-level:

```c++
// functions taking const and nonconst references or pointers have different
parameters
// declarations for four independent, overloaded functions
Record lookup(Account&); // function that takes a reference to
Account
Record lookup(const Account&); // new function that takes a const
reference

Record lookup(Account*); // new function, takes a pointer to
Account
Record lookup(const Account*); // new function, takes a pointer to const
```
* In these cases, the compiler can use the constness of the argument to distinguish which function to call.

* There is no conversion (§ 4.11.2, p. 162) from const, we can pass a const object (or a pointer to const) only to the version with a const parameter.

* The compiler will prefer the nonconst versions when we pass a nonconst object or pointer to nonconst.

```c++
#include<iostream>
void test( int& a){
	a=2;
	std::cout<<a<<std::endl;


}

void test(const int& a){
	std::cout<<a<<std::endl;

}

int main(){
	test(3)
	int c=3;
	test(c);
	const int b=3;
	test(b);

}
//output 3,2 & 3
```

* We should only overload operations that actually do similar things.

* const_cast and Overloading: 
		* We can call the function on a pair of nonconst string arguments, but we'll get a reference to a const string as the result.
		* We might want to have a version of shorterString that, when given nonconst arguments, would yield a plain reference.
```c++
// return a reference to the shorter of two strings
const string &shorterString(const string &s1, const string
&s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2)
{
	auto &r = shorterString(const_cast<const string&>(s1),const_cast<const string&>(s2));
	return const_cast<string&>(r);
}
```

### Calling an Overloaded Function
* Function matching (overload resolution): is the process by which a particular function call is associated with a specific function from a set of overloaded functions.

* The compiler determines which function to call by comparing the arguments in the call with the parameters offered by each function in the overload set.

	* The compiler finds exactly one function that is a best match for the actual arguments and generates code to call that function.
	* There is no function with parameters that match the arguments in the call, in which case the compiler issues an error message that there was no match.
	* There is more than one function that matches and none of the matches is clearly best. This case is also an error; it is an ambiguous call.

### Overloading and Scope

* It is a bad idea to declare a function locally.

```c++
string read();
void print(const string &);
void print(double); // overloads the print function
void fooBar(int ival)
{
	bool read = false; // new scope: hides the outer declaration of read
	string s = read(); // error: read is a bool variable, not a function
	// bad practice: usually it's a bad idea to declare functions at local scope
	void print(int); // new scope: hides previous instances of print
	print("Value: "); // error: print(const string &) is hidden
	print(ival); // ok: print(int) is visible
	print(3.14); // ok: calls print(int); print(double) is hidden
}
```

	* When the compiler processes the call to read, it finds the local definition of read. That name is a bool variable, and we cannot call a bool.

	* Exactly the same process is used to resolve the calls to print.

	* When we call print, the compiler first looks for a declaration of that name. It finds the local declaration for print that takes an int.

	* Once a name is found, the compiler ignores uses of that name in any outer scope.

* In C++, name lookup happens before type checking.


## Features for Specialized Uses

### Default Arguments

* Some functions have parameters that are given a particular value in most, but not all, calls.

* Functions with default arguments can be called with or without that argument.

* For example, we might use a string to represent the contents of a window.

* The window must have particular height, width, and background character. However, we might also want to allow users to pass values other than default.

```c++
typedef string::size_type sz; // typedef see § 2.5.1 (p. 67)
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');
```

	* A default argument is specified as an initializer for a parameter in the parameter list.

	* If a parameter has a default argument, all the parameters that follow it must also have default arguments.

```c++
string window;
window = screen(); // equivalent to screen(24,80,' ')
window = screen(66);// equivalent to screen(66,80,' ')
window = screen(66, 256); // screen(66,256,' ')
window = screen(66, 256, '#'); // screen(66,256,'#')
window = screen(, , '?'); // error: can omit only trailing arguments
window = screen('?'); // calls screen('?',80,' ')
// right-most trailing
```

	* Part of the work of designing a function with default arguments is ordering the parameters so that those least likely to use a default value appear first and those most likely to use a default appear last.


* It is normal practice to declare a function once inside a header, it is legal to redeclare a function multiple times.

* However, each parameter can have its default specified only once in a given scope.

```c++
// no default for the height or width parameters
string screen(sz, sz, char = ' ');
string screen(sz, sz, char = '*'); // error: redeclaration
string screen(sz = 24, sz = 80, char); // ok: adds default
```

* Local variables may not be used as a default argument.

```c++
// the declarations of wd, def, and ht must appear outside a function
sz wd = 80;
char def = ' ';
sz ht();
string screen(sz = ht(), sz = wd, char = def);
string window = screen(); // calls screen(ht(), 80, ' ')

void f2()
{
	def = '*'; // changes the value of a default argument
	sz wd = 100; // hides the outer definition of wd but does not change the default
	window = screen(); // calls screen(ht(), 80, '*')
}
```
	* Our function also declared a local variable that hides the outer wd. However, the local named wd is unrelated to the default argument passed to screen.

