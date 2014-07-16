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

#include "../_Matrix.h"

using namespace ty::Math;

int main()
{
	cout<<"Test of Matrix!"<<endl;
	double data[]={2,1,4,3,2,4,5,3,9,8,7};
	cout<<"---->Test of Construction!"<<endl;
	cout<<"-->one"<<endl;
	Matrix<double> m1;
	m1.PrintMatrix(std::cout);
	
	cout<<"-->Two"<<endl;
	Matrix<double> m2(3,3,data+1);
	m2.PrintMatrix(std::cout);

	cout<<"-->Three"<<endl;
	Vector<double> l1(3,data);
	Vector<double> l2(3,data+3);
	Vector<double> l3(3,data+6);
	Vector<double> line[]={l1,l2,l3};
	Matrix<double> m3(3,3,line);
	m3.PrintMatrix(std::cout);

	cout<<"---->Test of Operating !"<<endl;
	cout<<"-->Add"<<endl;
	Matrix<double> madd=m2.Add(m3);
	madd.PrintMatrix(std::cout);
	cout<<"-->Minuse"<<endl;
	m2.Minuse(m3).PrintMatrix(std::cout);

	cout<<"-->Multiple"<<endl;
	m3.Multiple(2.0).PrintMatrix(std::cout);

	cout<<"--->Test of Matrix exception!"<<endl;
	try
	{
		m1.Add(m2);
	}
	catch( SizeNotCompatible e )
	{
		cout<<"Exception happened!"<<endl;
		cout<<e.what()<<endl;
	}
	

	return 0;
}
