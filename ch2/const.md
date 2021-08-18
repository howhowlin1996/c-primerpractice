# const Qualifer

* We use const to define a variable whose value we know cannot be changed.

```c++
const int bufSize = 512; // input buffer size

bufSize = 512; // error: attempt to write to const object
```

* const must be initialized because we can't change the value

```c++
const int i = get_size(); // ok: initialized at run time
const int j = 42; // ok: initialized at compile time
const int k; // error: k is uninitialized const
```

* when we use an object to initialize another object, it doesn't matter whether either or both of the objects are consts

```c++
int i = 42;
const int ci = i; // ok: the value in i is copied into ci
int j = ci; // ok: the value in ci is copied into j
```

## By Default, const Objects Are Local to a File

* the compiler will usually replace uses of the variable with its corresponding value during compilation.

* That is, the compiler will generate code using the value 512 in the places that our code uses bufSize.

* When we split a program into multiple files, every file that uses the const must have access to its initializer.

* In order to see the initializer, the variable must be defined in every file wants to use it.

* To surport it, and avoid multiple definition of the same variable, const variables are defined as local to the file.

* When we define a const with the same name in multiple files, it is as if we had written definitions for separate variables in each file.


* To share a const object among multiple files, you must define the variable
as extern.

```c++
// file_1.cc defines and initializes a const that is accessible to other files
extern const int bufSize = fcn();
// file_1.h
extern const int bufSize; // same bufSize as defined in file_1.cc
```

* The extern signifies that bufSize is not local to this file and that its definition will occur elsewhere.

## Reference to const

* A reference to const cannot be used to change the object to which the reference is bound.

```c++
const int ci = 1024;
const int &r1 = ci; // ok: both reference and underlying object are const
r1 = 42; // error: r1 is a reference to const
int &r2 = ci; // error: non const reference to a const object
```

* We noted that there are two exceptions to the rule that the type of a reference must match the type of the object to which it refers.

* The first exception is that we can initialize a reference to const from any expression that can be converted to the type of the reference.

* We can bind a reference to const to a nonconst object, a literal, or a more general expression.

```c++
int i = 42;
const int &r1 = i; // we can bind a const int& to a plain int object
const int &r2 = 42; // ok: r1 is a reference to const
const int &r3 = r1 * 2; // ok: r3 is a reference to const
int &r4 = r * 2; // error: r4 is a plain, non const reference
```

＊what happens when we bind a reference to an object of a different type:

```c++
double dval = 3.14;
const int &ri = dval;
```

```c++
const int temp = dval; // create a temporary const int from the double
const int &ri = temp; // bind ri to that temporary
```

* In this case, ri is bound to a temporary obj

```c++
const int temp = dval; // create a temporary const int from the double
const int &ri = temp; // bind ri to that temporary
```

* In this case, ri is bound to a temporary object.

## A Reference to const May Refer to an Object That Is Not const

* It is important to realize that a reference to const restricts only what we can do through that reference.

```c++
int i = 42;
int &r1 = i; // r1 bound to i
const int &r2 = i; // r2 also bound to i; but cannot be used to change i
r1 = 0; // r1 is not const; i is now 0
r2 = 0; // error: r2 is a reference to const
```

* However, we cannot use r2 to change i. Even so, the value in i still might change. We can change i by assigning to it directly.

## Pointers and const

* A pointer to const may not be used to change the object to which the pointer points.

``` c++
const double pi = 3.14; // pi is const; its value may not be changed
double *ptr = &pi; // error: ptr is a plain pointer
const double *cptr = &pi; // ok: cptr may point to a double that is const
*cptr = 42; // error: cannot assign to *cptr
```

* Like a reference to const, a pointer to const says nothing about whether the object to which the pointer points is const.

```c++
double dval = 3.14; // dval is a double; its value can be changed
cptr = &dval; // ok: but can't change dval through cptr
```

* It is important to remember that there is no guarantee that an object pointed to by a pointer to const won't change.

* It may be helpful to think of pointers and references to const as pointers or references “that think they point or refer to const.”

## const Pointers

* Like any other const object, a const pointer must be initialized, and once initialized, its value (i.e., the address that it holds) may not be changed.

```c++
int errNumb = 0;
int *const curErr = &errNumb; // curErr will always point to errNumb
const double pi = 3.14159;
const double *const pip = &pi; // pip is a const pointer to a const
object
```
* The symbol closest to curErr is const, which means that curErr itself will be a const object.

* curErr addresses a plain, nonconst int. We can use curErr to change the value of errNumb.

## Top-Level and Low-Level const

* Top-level const to indicate that the pointer itself is a const.

* When a pointer can point to a const object, we refer to that const as a low-level const.

* When we copy an object, top-level consts are ignored:

```c++
i = ci; // ok: copying the value of ci; top-level const in ci is ignored
p2 = p3; // ok: pointed-to type matches; top-level const in p3 is ignored
```

* Copying an object doesn't change the copied object. As a result, it is immaterial whether the object copied from or copied into is const.

* On the other hand, low-level const is never ignored. When we copy an object, both objects must have the same low-level const qualification or there must be a conversion between the types of the two objects.

	* 1.the same low-level const qualification or 
	
	* 2.LHS has more strict constness than RHS (In other words, there must be a conversion between the types of the two objects. In general, we can convert a nonconst to const but not the other way round.








