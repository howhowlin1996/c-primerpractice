/*exe3.44 Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.
exe3.45 Rewrite the programs again, this time using auto.*/
#include<iostream>





int main(){
	int ia[3][4]{0,1,2,3,4,5,6,7,8,9,10,11};
	//exe3.44
	typedef int int_array[4];
	for(int_array* row_beg=ia;row_beg!=ia+3;++row_beg)
		for(int *col_beg=*row_beg;col_beg!=*row_beg+4;++col_beg)
			std::cout<<*col_beg<<" ";
	std::cout<<std::endl;
	//exe3.45
	for(auto &row:ia)
		for(auto col:row)
			std::cout<<col<<" ";
	std::cout<<std::endl;

	return 0;






}
