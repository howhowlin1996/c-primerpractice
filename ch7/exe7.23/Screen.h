#ifndef Screen_H
#define Screen_H
#include<string>
class Screen{
	public:
	//size_t
	typedef std::string::size_type pos;
	//constructor
	Screen()=default;
	Screen(pos w,pos h):height(h),width(w),content(h*w,' '){};
	Screen(pos w,pos h,char c):height(h),width(w),content(h*w,c){};
	private:
	//element
	pos height=0;
	pos width=0;
	std::string content;
};


#endif
