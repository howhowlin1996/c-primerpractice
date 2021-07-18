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

! [image](https://github.com/howhowlin1996/c-primerpractice/blob/main/ch6/c%2B%2B%20compilation.png)
![image](https://github.com/howhowlin1996/c-primerpractice/blob/main/ch6/c%2B%2B%20compilation%20detail.jpeg)

* Preprocessing:
```
The preprocessor handles the preprocessor directives, like #include and #define. It is agnostic of the syntax of C++, which is why it must be used with care.

It works on one C++ source file at a time by replacing #include directives with the content of the respective files (which is usually just declarations), doing replacement of macros (#define), and selecting different portions of text depending of #if, #ifdef and #ifndef directives.

The preprocessor works on a stream of preprocessing tokens. Macro substitution is defined as replacing tokens with other tokens (the operator ## enables merging two tokens when it makes sense).

After all this, the preprocessor produces a single output that is a stream of tokens resulting from the transformations described above. It also adds some special markers that tell the compiler where each line came from so that it can use those to produce sensible error messages.

Some errors can be produced at this stage with clever use of the #if and #error directives.
```

* Compilation:
```
The compilation step is performed on each output of the preprocessor. The compiler parses the pure C++ source code (now without any preprocessor directives) and converts it into assembly code. Then invokes underlying back-end(assembler in toolchain) that assembles that code into machine code producing actual binary file in some format(ELF, COFF, a.out, ...). This object file contains the compiled code (in binary form) of the symbols defined in the input. Symbols in object files are referred to by name.

Object files can refer to symbols that are not defined. This is the case when you use a declaration, and don't provide a definition for it. The compiler doesn't mind this, and will happily produce the object file as long as the source code is well-formed.

Compilers usually let you stop compilation at this point. This is very useful because with it you can compile each source code file separately. The advantage this provides is that you don't need to recompile everything if you only change a single file.

The produced object files can be put in special archives called static libraries, for easier reusing later on.

It's at this stage that "regular" compiler errors, like syntax errors or failed overload resolution errors, are reported.
```

* Linking:

>The linker is what produces the final compilation output from the object files the compiler produced. This output can be either a shared (or dynamic) library (and while the name is similar, they haven't got much in common with static libraries mentioned earlier) or an executable.

>It links all the object files by replacing the references to undefined symbols with the correct addresses. Each of these symbols can be defined in other object files or in libraries. If they are defined in libraries other than the standard library, you need to tell the linker about them.

>At this stage the most common errors are missing definitions or duplicate definitions. The former means that either the definitions don't exist (i.e. they are not written), or that the object files or libraries where they reside were not given to the linker. The latter is obvious: the same symbol was defined in two different object files or libraries.


