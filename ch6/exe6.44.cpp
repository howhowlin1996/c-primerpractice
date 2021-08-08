#include<iostream>
#include<string>
/*Rewrite the isShorter function from § 6.2.2 (p. 211) to be
inline.*/

// compare the length of two strings
inline bool isShorter(const std::string &s1, const std::string &s2)
{
	return s1.size() < s2.size();
}

int main(){

	std::cout<<isShorter("apple","banana")<<std::endl;
	return 0;

}
