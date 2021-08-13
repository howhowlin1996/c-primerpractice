# Dealing with Types

* Why we need types aliaes: Some types are hard to spell.That is, they have forms that are tedious and error-prone to write.

## Type Aliases

* Type aliases let us simplify complicated type definitions, making those types easier to use.

* We can define a type alias in one of two ways: 
	* typedef
	* alias declaration

### typedef

```c++
typedef double wages; // wages is a synonym for double
typedef wages base, *p; // base is a synonym for double, p for double*
```

### alias declaration

```c++
using SI = Sales_item; // SI is a synonym for Sales_item
```

```c++
wages hourly, weekly; // same as double hourly, weekly;
SI item; // same as Sales_item item
```

### Pointers, const, and Type Aliases

* Declarations that use type aliases that represent compound types and const can yield surprising results.

```c++
typedef char *pstring; //pstring -> pointer tochar.
const pstring cstr = 0; // cstr is a constant pointer to char
const pstring *ps; // ps is a pointer to a constant pointer to char
```

### The auto Type Specifier

* Sometimes, it can be difficult or impossible to determine the type of an expression.

* auto tells the compiler to deduce the type from the initializer.

	* A variable that uses auto as its type specifier must have an initializer.

* We can also define multiple variables by auto. However, they need to have tyoes that are consistent with each other.

```c++
auto i = 0, *p = &i; // ok: i is int and p is a pointer to int
auto sz = 0, pi = 3.14; // error: inconsistent types for sz and pi
```

### Compound Types, const, and auto

* When we use a reference as an initializer, the initializer is the corresponding object.

```c++
int i = 0, &r = i;
auto a = r; // a is an int (r is an alias for i, which has type int)
```

* auto ordinarily ignores top-level consts

```c++
const int ci = i, &cr = ci;
auto b = ci; // b is an int (top-level const in ci is dropped)
auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
auto d = &i; // d is an int*(& of an int object is int*)
auto e = &ci; // e is const int*(& of a const object is low-level const)
```

* When we ask for a reference to an auto-deduced type, top-level consts in the initializer are not ignored.

```c++
auto &g = ci; // g is a const int& that is bound to ci
auto &h = 42; // error: we can't bind a plain reference to a literal
const auto &j = 42; // ok: we can bind a const reference to a literal
```
```c++
auto k = ci, &l = i; // k is int; l is int&
auto &m = ci, *p = &ci; // m is a const int&;p is a pointer to const int
// error: type deduced from i is int; type deduced from &ci is const int
auto &n = i, *p2 = &ci;
```

### The decltype Type Specifier

* The compiler analyzes the expression to determine its type but does not evaluate the expression: 

```c++
decltype(f()) sum = x; // sum has whatever type f returns
```

* The compiler does not call f() but it uses the type that such a call would return as the type for sum.

* The compiler gives sum the same type as the type that would be returned if we were to call f().

* The way decltype handles top-level const and references differs subtly from the way auto does.

```c++
const int ci = 0, &cj = ci;
decltype(ci) x = 0; // x has type const int
decltype(cj) y = x; // y has type const int& and is bound to x
decltype(cj) z; // error: z is a reference and must be initialized
```

### decltype and References

* Generally speaking, decltype returns a reference type for expressions that yield objects that can stand on the left-hand side of the assignment:

```c++
// decltype of an expression can be a reference type
int i = 42, *p = &i, &r = i;
decltype(r + 0) b; // ok: addition yields an int; b is an (uninitialized) int
decltype(*p) c; // error: c is int& and must be initialized
```

* Here r is a reference, so decltype(r) is a reference type.

* When we use r in an expression, such as r + 0, which is an expression that yields a value that has a nonreference type.

* On the other hand, the dereference operator is an example of an expression for which decltype returns a reference.

* Thus, the type deduced by decltype(*p) is int&, not plain int

* Another important difference between decltype and auto is that the deduction done by decltype depends on the form of its given expression.

* If we wrap the variable’s name in one or more sets of parentheses, the compiler will evaluate the operand as an expression.

* A variable is an expression that can be the left-hand side of an assignment. As a result, decltype on such an expression yields a reference:

```c++
// decltype of a parenthesized variable is always a reference
decltype((i)) d; // error: d is int& and must be initialized
decltype(i) e; // ok: e is an (uninitialized) int
```

* Remember that decltype((variable)) (note, double parentheses) is always a reference type, but decltype(variable) is a reference type only if variable is a reference.





