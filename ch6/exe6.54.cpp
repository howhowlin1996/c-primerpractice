#include <vector>
#include <iostream>

int foo(int, int);
int bar(int, int);

int main() {
  std::vector<int (*)(int, int)> vf;
  int (* add) (int,int)=&foo;
  std::cout<<reinterpret_cast<void*>(add)<<std::endl;
  //std::cout<<int(add)<<std::endl;
  vf.push_back(foo);
  vf.push_back(bar);

  vf[0](1,2);
  vf[1](3, 4);
  
  for(int i=0;i<vf.size();++i){
	std::cout<<&vf[i]<<std::endl;

  }
  return 0;
}

int foo(int a, int b) {
  std::cout << "Called foo(" << a << ", " << b << ")" << std::endl;
  return -1;
}

int bar(int a, int b) {
  std::cout << "Called bar(" << a << ", " << b << ")" << std::endl;
  return 0;
}
