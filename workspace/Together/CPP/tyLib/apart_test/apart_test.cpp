/*
 *File		:apart_test.cpp
 *Author	:tangyu
 *Date		:2011-05-27 22:01:00 
 *Version	:1.0.0
 *Modify	:
 */

//#define EXPORT_SUPPORT

#include "_max.h"

#include <iostream>

using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main()
{
	int a=5,b=7;
	cout<<max(a,b)<<endl;
	cout<<min(a,b)<<endl;

	Person<int > me;
	cout<<me.test(5)<<endl;

	
	int data[]={1,1,2,5,4,6};
	vector<double> vec(data,data+1);
	//vector<int >   ivec=vec;
	
	
}
