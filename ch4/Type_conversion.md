# Type Conversions

## Implicit conversions

* These conversions are carried out automatically without programmer intervention— and sometimes without programmer knowledge.

* For example:
	
	* if an expression has both integral and floatingpoint operands, the integer is converted to floating-point

* Compiler will aoutomatically converts operands in the following circumstances:

	* In most expressions, values of integral types smaller than int are first promoted to an appropriate larger integral type.

	* In conditions, nonbool expressions are converted to bool.

	* In initializations, the initializer is converted to the type of the variable; in assignments, the right-hand operand is converted to the type of the left-hand.

	* In arithmetic and relational expressions with operands of mixed types, the types are converted to a common type.

	* conversions also happen during function calls

### The Arithmetic Conversions

* The rules define a hierarchy of type conversions in which operands to an operator are converted to the widest type.

	* mix floating-point and integral values, the integral value is converted to an appropriate floating-point type.

* Integral Promotions:
	
	* convert the small integral types to a larger integral type
	
	* The types bool, char, signed char, unsigned char, short, and unsigned short signed char, unsigned char, short, and unsigned short int if all possible values of that type fit in an int.

	* Otherwise, ptomoted to unsigned int.

	* The larger char types (wchar_t, char16_t, and char32_t) are promoted to the smallest type of int, unsigned int, long, unsigned long, long long, or unsigned long long in which all possible values of that character type fit.

#### Operands of Unsigned Type

* Integral promotions happen first.
	
	* If the resulting type(s) match, no further conversion is needed.
	
* When the signedness differs:
	
	* the type of the unsigned operand is the same as or larger than that of the signed operand

		* for example: unsigned int and an int -> int is converted to unsigned int
	
	* If the signed operand has a larger type than the unsigned ones, the result is machine dependent.

		* If all values in the unsigned type fit in the larger type, then the unsigned operand is converted to the signed type.

		* If the values don't fit, then the signed operand is converted to the unsigned type.

* Let's consider the following 3 example cases for each of the 3 above clauses on a system where sizeof(int) < sizeof(long) == sizeof(long long)

```c++
#include <iostream>

signed int s1 = -4;
unsigned int u1 = 2;

signed long int s2 = -4;
unsigned int u2 = 2;

signed long long int s3 = -4;
unsigned long int u3 = 2;

int main()
{
    std::cout << (s1 + u1) << "\n"; // 4294967294
    std::cout << (s2 + u2) << "\n"; // -2
    std::cout << (s3 + u3) << "\n"; // 18446744073709551614
}
```

### Other Implicit Conversions

#### Array to Pointer Conversions: In most expressions, when we use an array, the  array is automatically converted to a pointer to the first element in that array:

```c++
int ia[10]; // array of ten ints
int* ip = ia; // convert ia to a pointer to the first element
```

* This conversion is not performed when an array is used withdecltype or as the operand of the address-of (&), sizeof, or typeid operators.

#### Pointer Conversions: 

* A constant integral value of 0 and the literal nullptr can be converted to any pointer type

* A pointer to any nonconst type can be converted to void*.

* A pointer to any type can be converted to a const void*.

#### Conversions to bool:

* If the pointer or arithmetic value is zero, the conversion yields false; any other value yields true.

```c++
char *cp = get_string();
if (cp) /* ... */ // true if the pointer cp is not zero
while (*cp) /* ... */ // true if *cp is not the null character
```

#### Conversion to const:

* We can convert a pointer to a nonconst type to a pointer to the corresponding const type, and similarly for references.

```c++
int i;
const int &j = i; // convert a nonconst to a reference to const int
const int *p = &i; // convert address of a nonconst to the address of a const
int &r = j, *q = p; // error: conversion from const to nonconst not allowed
```

* The reverse conversionremoving a low-level const does not exist.

#### Conversions Defined by Class Types:

* Class types can define conversions that the compiler will apply automatically.

* The compiler will apply only one class-type conversion at a time.

```c++
string s, t = "a value"; // character string literal converted to type
string
while (cin >> s) // while condition converts cin to bool
```
* The IO library defines a conversion from istream to bool.

* The resulting bool value depends on the state of the stream. If the last read succeeded, then the conversion yields true. Otherwise, false.

### Explicit Conversions

* A named cast has the following form:

```c++
cast-name<type>(expression);
```

* static_cast, dynamic_cast, const_cast, and reinterpret_cast

* We’ll cover dynamic_cast, which supports the run-time type identification, in § 19.2 (p. 825).

#### static_cast

* Any well-defined type conversion, other than those involving low-level const, can be requested using a static_cast.

```c++
// cast used to force floating-point division
double slope = static_cast<double>(j) / i;
```

* A static_cast is often useful when a larger arithmetic type is assigned to a smaller type.

* Compilers often generate a warning for assignments of a larger arithmetic type to a smaller type.

	* When we do an explicit cast, the warning message is turned off.

* A static_cast is also useful to perform a conversion that the compiler will not generate automatically.

	* For example, we can use a static_cast to retrieve a pointer value that was stored in a void* pointer.

```c++
void* p = &d; // ok: address of any nonconst object can be stored in a void*
// ok: converts void* back to the original pointer type
double *dp = static_cast<double*>(p);
```

* we must be certain that the type to which we cast the pointer is the actual type of that pointer; if the types do not match, the result is undefined.

####  const_cast

* A const_cast changes only a low-level const in its operand:

```c++
const char *pc;
char *p = const_cast<char*>(pc); // ok: but writing through p is
undefined
```

* cast that converts a const object to a nonconst type casts away the const

	* Once we have cast away the const of an object, the compiler will no longer prevent us from writing to that object.

* Only a const_cast may be used to change the constness of an expression.

```c++
const char *cp;
// error: static_cast can't cast away const
char *q = static_cast<char*>(cp);
static_cast<string>(cp); // ok: converts string literal to string
const_cast<string>(cp); // error: const_cast only changes constness
```

* A const_cast is most useful in the context of overloaded functions.

```c++
// return a reference to the shorter of two strings
const string &shorterString(const string &s1, const string
&s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2)
{
auto &r = shorterString(const_cast<const string&>(s1),
const_cast<const string&>(s2));
return const_cast<string&>(r);
}
```

#### reinterpret_cast

* A reinterpret_cast generally performs a low-level reinterpretation of the bit pattern of its operands.

```c++
int *ip;
char *pc = reinterpret_cast<char*>(ip);
```

* We must never forget that the actual object addressed by pc is an int, not a character.

```c++
string str(pc);
```

* is likely to result in bizarre run-time behavior

* The use of pc to initialize str is a good example of why reinterpret_cast is dangerous.

	* Any subsequent use of pc will assume that the value it holds is a char*.

	* The compiler has no way of knowing that it actually holds a pointer to an int.

#### Old-Style Casts

```c++
type (expr); // function-style cast notation
(type) expr; // C-language-style cast notation
```

