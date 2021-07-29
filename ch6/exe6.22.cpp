#include<iostream>
/*exe6.22 Write a function to swap two int pointers.*/
void swap(int**a,int**b){
	
	int *tem=*b;
	*b=*a;
	*a=tem;
	
}

void swap(int*&a,int*&b){
	int *tem=b;
	b=a;
	a=tem;


}


int main(){
	int a,b;
	std::cin>>a>>b;
	std::cout<<"a: "<<&a<<" b: "<<&b<<std::endl;
	int *aptr=&a,*bptr=&b;
	swap(&aptr,&bptr);
	std::cout<<"aptr: "<<aptr<<" a: "<<*aptr<<" bptr: "<<bptr<<" b: "<<*bptr<<std::endl;
	swap(aptr,bptr);
	std::cout<<"aptr: "<<aptr<<" a: "<<*aptr<<" bptr: "<<bptr<<" b: "<<*bptr<<std::endl;
	return 0;
}



