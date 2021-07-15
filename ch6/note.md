6.1. Function Basics

argument v.s. parameter
int main()						int fact(int val){ 
{							/*val->parameter*/
int j = fact(5); // ()-> call operator, 5->argument	}
cout << "5! is " << j << endl;
return 0;
}


function execution
1. parameters be created and initialize
2.execution operation inside the block
3.return statement
	a.return the value
	b.transfer contro; out of called function back to the calling ones



// factorial of val is val * (val - 1) * (val - 2) . . . * ((val - (val - 1)) * 1)
int fact(int val)
{
int ret = 1; // local variable to hold the result as we calculate it
while (val > 1)
ret *= val--; // assign ret * val to ret and decrement val
return ret; // return the result
}

int val = 5; // initialize val from the literal 5
int ret = 1; // code from the body of fact
while (val > 1)
ret *= val--;
int j = ret; // initialize j as a copy of ret
Parameters and

function parameters can be empty:
void f1(){ /* ... */ } // implicit void parameter list
void f2(void){ /* ... */ } // explicit void parameter list

Even when the types of two parameters are the same, we still need to initialize it with type:
int f3(int v1, v2) { /* ... */ } // error
int f4(int v1, int v2) { /* ... */ } // ok

function return type can't be array type, we use pointer to substitute it.

Automatic objects:Objects that exist only while a block is executing.After execution exists a block, the values of them in the block are undefined.
i.e. parameters
Automatic objects corresponding to the function parameters are initialized by the arguments passed to the function.

Local static objects:
1.lifetime can continue across calls to the function
2.initialized when first time execution
3.destroyed when the program terminates

i.e.

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














