#ifndef FACTORIAL_H
#define FACTORIAL_H
#include<iostream>
int factorial(int);


int factorial(int first){
	int sum=1;
	while(first>1)
		sum*=first--;	
	
	return sum;
}

#endif
