#include<iostream>


/*exe 6.3 Write and test your own version of fact.
exe 6.4 Write a function that interacts with the user, asking for a
number and generating the factorial of that number. Call this function from
main.*/





// factorial counting
void fact(){
	std::cout<<"Please enter a number, then I will count factorial sum for you"<<std::endl;
	int first=0,input;
	while(std::cin>>first){
		input=first;
		int sum=1;
		while(first>1)
			sum*=first--;
		std::cout<<input<<"! is:"<<sum<<std::endl;
		std::cout<<"Please enter a number, then I will count factorial sum for you"<<std::endl;
		
	}
}

//absolutely value
void ab_value(){

	std::cout<<"Please enter a number, then I will count absolutely value for you"<<std::endl;
	int first=0,ans=0;
	while(std::cin>>first){
		ans=first;
		if(first<0)
			ans=-first;
		std::cout<<first<<" absolutely value: "<<ans<<std::endl;
		first=0;
		std::cout<<"Please enter a number, then I will count absolutely value for you"<<std::endl;
	}




}





int main(){
	int mode=1;
	std::cout<<"Which mode do you want?\n1.factorial counting\n2.absolutely value counting\n Please enter number:";
	std::cin>>mode;
	if(mode==1)
		fact();
	else
		ab_value();






}
