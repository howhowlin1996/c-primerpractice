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
	
