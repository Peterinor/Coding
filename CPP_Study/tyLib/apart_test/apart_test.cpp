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

#include"../Core/tyLib.h"

class TConst
{
public:
	TConst A()const
	{ 
		return TConst(*this);		
	}
	TConst B( const TConst & another)
	{
		return another.A();
	}
private:
};

template<typename Fun>
int test( int a , Fun & fun)
{
	return fun(a);
}


int doubled(int x)
{
	return 2*x;	
}
class Doubled
{
public:
	Doubled( )
	{
		this->times=0;		
	}
	Doubled( int n )
	{
		this->times=n;		
	}
	int operator()( int x )
	{
		return this->times*x;	
	}
private:
	int times;

};

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

	TConst t1,t2;
	t2.B(t1);

	cout<<test(5,doubled)<<endl;
	Doubled d;
	cout<<test(5,d)<<endl;
	Doubled d3(3);
	cout<<test(5,d3)<<endl;
	
	
}
