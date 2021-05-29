/*Write three different versions of a program to print the
elements of ia. One version should use a range for to manage the
iteration, the other two should use an ordinary for loop in one case using
subscripts and in the other using pointers. In all three programs write all the
types directly. That is, do not use a type alias, auto, or decltype to
simplify the code.*/
#include<iostream>



int main(){
	int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
	//use range for loop
	for(int (&row)[4] :ia)
		for(int ele:row)
			std::cout<<ele<<" ";
	std::cout<<std::endl;
        //for loop using subscript
	for(int i=0;i!=3;++i)
		for(int j=0;j!=4;++j)
			std::cout<<ia[i][j]<<" ";
	std::cout<<std::endl;
	//for loop using pointer
	for(int (*row_beg)[4]=std::begin(ia),(*row_end)[4]=std::end(ia);row_beg!=row_end;++row_beg)
		for(int *col_beg=std::begin(*row_beg),*col_end=std::end(*row_beg);col_beg!=col_end;++col_beg)
			std::cout<<*col_beg<<" ";
	std::cout<<std::endl;
	//for loop using pointer
	for(int(*row)[4]=ia;row!=ia+3;++row)
		for(int *col=*row;col!=*row+4;++col)
			std::cout<<*col<<" ";
	std::cout<<std::endl;
	return 0;
}
