#include<iostream>


/*assume that the definition of our fact function is in a file named
fact.cc*/



int factorial(int start_num){
	int sum=1;
	while(start_num>1)
		sum*=start_num--;
	return sum;
}
