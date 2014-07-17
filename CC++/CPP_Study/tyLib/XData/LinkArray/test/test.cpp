/*
 *File		:test.cpp
 *Author	:tangyu
 *Date		:2011-05-27 22:09:49 
 *Version	:1.0.0
 *Modify	:
 */

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::fstream;


#include <string>
using std::string;

#include "../_LinkArray.h"

using namespace ty::XData;
using ty::ErrorHandle::NotFound;

int main()
{
	cout<<"test of LinkArray!"<<endl;

	LinkArray<string , int > arr;
	arr.Add("A",100);
	arr.Add("B",85 );
	arr.Add("C",60 );
	arr.Add("D",60 );
	arr.PrintArray(std::cout);

	
	try
	{	cout<<arr["A"]<<endl;
		cout<<arr["E"]<<endl;	
	}
	catch(NotFound e)
	{
		cout<<"Exception Happpened :"<<e.what()<<endl;
		cout<<"ExcetionType :"<<e.GetExceptionType()<<endl;
	}
	if(ty::ErrorHandle::OK!=arr.GetLastError())
	{
		cout<<"Not Found"<<endl;
	}
	cout<<"Remove \'A\' from arr1"<<endl;
	LinkArray<string , int > arr1=arr;
	/**Remove by index test**/
	arr1.Remove("A");
	arr1.PrintArray(std::cout);
	arr.PrintArray(std::cout);
	/**Remove by value test**/
	arr1.Remove(60);
	arr1.PrintArray(std::cout);
	try
	{
		/**test of need of Construction Function**/	
		cout<<arr["A"]<<endl;

		/**Remove by index test**/
		//cout<<arr1["A"]<<endl;

		/**Remove by value test**/
		//cout<<arr1["c"]<<endl;	
		cout<<arr1["D"]<<endl;	
	}
	catch(NotFound e)
	{
		cout<<"Exception Happpened :"<<e.what()<<endl;
		cout<<"ExcetionType :"<<e.GetExceptionType()<<endl;
	}
	cout<<"Test of output to a txt file"<<endl;
	fstream file;
	file.open("/home/paul/CPP_Study/tyLib/XData/LinkArray/test/output",std::ios::out);
	if(file)
		arr.PrintArray(file);
	else
		cout<<"open file failed !"<<endl;
	file.close();
	

	return 0;
}
