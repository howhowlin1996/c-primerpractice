/*exe 3.40 Write a program to define two character arrays initialized
from string literals. Now define a third character array to hold the
concatenation of the two arrays. Use strcpy and strcat to copy the two
arrays into the third.*/
#include<iostream>
#include<string>
#include<cstring>




int main(){
	std::string str1;
	std::string str2;
	std::cout<<"Pleaase enter two string"<<std::endl;
	std::cin>>str1>>str2;
	const int size1=str1.size();
	const int size2=str2.size();
	char chr1[size1+1]; 	//reserve the '/0/' position
	char chr2[size2+1];
	char chr3[size1+size2+1];
	char *chr1_beg=chr1;
	char *chr2_beg=chr2;

	for(auto ele:str1){
		*chr1_beg=ele;
		++chr1_beg;
	}
	for(auto ele:str2){
		*chr2_beg=ele;
		++chr2_beg;
	}
	*chr1_beg='\0';
	*chr2_beg='\0';
	strcpy(chr3,chr1);
	strcat(chr3,chr2);
	char *chr3_beg=chr3;
	for(int i=0;i!=size1+size2;++i,++chr3_beg)
		std::cout<<*chr3_beg;
	std::cout<<std::endl;
	return 0;
}
