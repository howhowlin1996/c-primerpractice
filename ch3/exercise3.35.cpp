//exercise 3.35-> change all elements in array to 0
//exercise 3.36-> compare 2 vectors and 2 arrays equality respectively
#include<iostream>
#include<vector>
void comp_vec(std::vector<int>&vec1,std::vector<int>&vec2){
	if(vec1>vec2)
		std::cout<<"vec1>vec2"<<std::endl;
	else if(vec1==vec2)
		std::cout<<"vec1==vec2"<<std::endl;
	else
		std::cout<<"vec1<vec2"<<std::endl;

}
void comp_arr(int *arr1,int *arr2,int size1,int size2){
	if(size1>size2)
		std::cout<<"arr1>arr2"<<std::endl;
	else if(size2>size1)
		std::cout<<"arr2>arr1"<<std::endl;
	else{
		for(int i=0;i!=size1;++i,++arr1,++arr2){
			if(*arr1>*arr2){
				std::cout<<"arr1>arr2"<<std::endl;
				return;
			}
			else if(*arr1<*arr2){
				std::cout<<"arr2>arr1"<<std::endl;
				return;
			}
		}
		std::cout<<"arr1==arr2"<<std::endl;
		
	}


}

int main(){
	//exe 3.35
	int table[10]{1,2,3,4,5,6,7,8,9,10};
	int * beg=table;
	for(int i=0;i!=10;++i,++beg)
		*beg=0;
	for(auto ele:table)
		std::cout<<ele<<" ";
	std::cout<<std::endl;
	//exe3.36
	int ele,vec1_s,vec2_s;
	std::vector<int>vec1;
	std::vector<int>vec2;
	std::cout<<"Please enter two vector size"<<std::endl;
	std::cin>>vec1_s>>vec2_s;
	std::cout<<"Please enter vec1: "<<std::endl;
	for(int i=0;i!=vec1_s;++i){
		std::cin>>ele;
		vec1.push_back(ele);
	}

	std::cout<<"Please enter vec2: "<<std::endl;		
	for(int i=0;i!=vec2_s;++i){
		std::cin>>ele;
		vec2.push_back(ele);
	}
	std::cout<<std::endl;
	const int size1=vec1_s;
	const int size2=vec2_s;
	int arr1[size1];
	int arr2[size2];
	int *arr1_beg=arr1;
	int *arr2_beg=arr2;

	for(auto ele:vec1){
		*arr1_beg=ele;
		++arr1_beg;
	}
	for(auto ele:vec2){
		*arr2_beg=ele;
		++arr2_beg;
	}
	comp_arr(arr1,arr2,size1,size2);
	comp_vec(vec1,vec2);

	return 0;
}
