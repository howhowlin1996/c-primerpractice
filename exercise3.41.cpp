/*exe3.41 Write a program to initialize a vector from an array of
ints exe 3.42 Write a program to copy a vector of ints into an array of
ints.*/
#include<iostream>
#include<vector>



int main(){
	//exe3.41
	int arr[]{1,2,3,4,5};
	std::vector<int>vec1(std::begin(arr),std::end(arr));
	//verify
	for(auto ele:vec1)
		std::cout<<ele<<" ";
	std::cout<<std::endl;
	//exe3.42
	const int size=vec1.size();
	int arr1[size];
	int *beg=arr1;
	for(auto ele:vec1){
		*beg=ele;
		++beg;
	}
	for(auto ele:arr1)
		std::cout<<ele<<" ";
	std::cout<<std::endl;
	return 0;





}
