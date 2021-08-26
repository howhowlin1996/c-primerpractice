# 7.3. Additional Class Features

## Class Members Revisited

* Defining a Type Member

```c++
class Screen {
	public:
		typedef std::string::size_type pos;
	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		std::string contents;
};
```

* Each Screen has a string member that holds the Screen's contents, and three string::size_type members that represent the position of the cursor, and the height and width of the screen.

* Type names defined by a class are subject to the same access controls as any other member and may be either public or private.

* We defined pos in the public part of Screen because we want users to use that name.

* Users of screen shouldn't know that Screen uses a string to hold its data.

* We can equivalently use a type alias.

```c++
class Screen {
	public:
		// alternative way to declare a type member using a type alias
		using pos = std::string::size_type;
		// other members as before
};
```

* Unlike ordinary members, members that define types must appear before they are used.

* As a result, type members usually appear at the beginning of the class.

## Member Functions of class Screen

* To make our class more useful, we’ll add a constructor that will let users define the size and contents of the screen, along with members to move the cursor and to get the character at a given location:

```c++
class Screen {
	public:
		typedef std::string::size_type pos;
		Screen() = default; // needed because Screen has another constructor
		// cursor initialized to 0 by its in-class initializer
		Screen(pos ht, pos wd, char c): height(ht), width(wd),contents(ht * wd, c) { }
		char get() const // get the character at the cursor{ return contents[cursor]; } // implicitly inline
		inline char get(pos ht, pos wd) const; // explicitly inline
		Screen &move(pos r, pos c); // can be made inline later
	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		std::string contents;
};
```

## Making Members inline

* Classes often have small functions that can benefit from being inlined.

* Thus, Screen's constructors and the version of get that returns the character denoted by the cursor are inline by default.

* We can explicitly declare a member function as inline as part of its declaration inside the class body.

```c++
inline // we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width; // compute the row location
	cursor = row + c ; // move cursor to the column within that row
	return *this; // return this object as an lvalue
}
char Screen::get(pos r, pos c) const // declared as inline in the
class
{
	pos row = r * width; // compute row location
	return contents[row + c]; // return character at the given column
}
```
* Specifying inline only on the definition outside the class can make the class easier to read rather than declaration.

## Overloading Member Functions

* As with nonmember functions, member functions may be overloaded.

* For example, our Screen class defined two versions of get.

```c++
Screen myscreen;
char ch = myscreen.get();// calls Screen::get()
ch = myscreen.get(0,0); // calls Screen::get(pos, pos)
```

## mutable Data Members

* A mutable data member is never const, even when it is a member of a const object.

* we'll give Screen a mutable member named access_ctr, which we'll use to track how often each screen member function is called.

* Despite the fact that some_member is a const member function, it can change the value of access_ctr.

```c++
class Screen {
	public:
		void some_member() const;
	private:
		mutable size_t access_ctr; // may change even in a const object
		// other members as before
};
void Screen::some_member() const
{
	++access_ctr; // keep a count of the calls to any member function
	// whatever other work this member needs to do
}
```

## Initializers for Data Members of Class Type

```c++
class Window_mgr {
private:
	// Screens this Window_mgr is tracking
	// by default, a Window_mgr has one standard sized blank Screen
	std::vector<Screen> screens{Screen(24, 80, ' ') };
};
```

* This class will have a vector of Screens in which each element represents a particular Screen.

* By default, we'd like our Window_mgr class to start up with a single, default-initialized Screen.

* That initializer contains a Screen value that is passed to the vector<Screen> constructor to create a one-element vector.

* As we’ve seen, in-class initializers must use either the = form of initialization (which we used when we initialized the the data members of Screen) or the direct form of initialization using curly braces (as we do for screens).

* When we provide an in-class initializer, we must do so following an = sign or inside braces.


