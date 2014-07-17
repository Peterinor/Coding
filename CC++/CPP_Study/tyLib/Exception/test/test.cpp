/*
 *File		:test.cpp
 *Author	:tangyu
 *Date		:2011-05-27 12:27:14 
 *Version	:1.0.0
 *Modify	:
 */


#include "../_Exception.h"

#include <iostream>
using std::cout;
using std::endl;

using namespace ty::ErrorHandle;

int main()
{
	try
	{
		throw Exception();
	}
	catch(Exception e)
	{
		cout<<"Exception type		:"<<e.GetExceptionType()<<endl;
		cout<<"Exception arguement	:"<<e.GetExceptionArg()	<<endl;
		cout<<e.what()<<endl;
	}

	try
	{
		throw NotFound();
	}
	catch(NotFound e)
	{
		cout<<"Exception type		:"<<e.GetExceptionType()<<endl;
		cout<<"Exception arguement	:"<<e.GetExceptionArg()	<<endl;
		cout<<e.what()<<endl;
	}

	try
	{
		throw SizeNotCompatible();
	}
	catch(SizeNotCompatible e)
	{
		cout<<"Exception type		:"<<e.GetExceptionType()<<endl;
		cout<<"Exception arguement	:"<<e.GetExceptionArg()	<<endl;
		cout<<e.what()<<endl;
	}
	return 0;
}
