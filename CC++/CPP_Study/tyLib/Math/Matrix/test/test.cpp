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

#include "../../../apart_test/_max.h"

int main()
{
	cout<<"Test of Matrix!"<<endl;
	double data[]={2,1,4,3,2,4,5,3,9,8,7,6,7,4,3,1};
	cout<<"---->Test of Construction!"		<<endl;
	cout<<"-->Zero"<<endl;
	Matrix<double> m0(4,3);
	m0.PrintMatrix(std::cout);
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
	Vector<double> lline[]={l1,l2,l3};
	const Matrix<double> m3(3,3,lline);
	m3.PrintMatrix(std::cout);

	cout<<"-->Four"<<endl;
	Vector<double> ll1(4,data);
	Vector<double> ll2(4,data+4);
	Vector<double> ll3(4,data+8);
	Vector<double> line[]={ll1,ll2,ll3};
	Matrix<double> m4(3,4,line);
	m4.PrintMatrix(std::cout);

	cout<<"---->Test of Operating !"		<<endl;
	cout<<"-->Add"<<endl;
	Matrix<double> madd=m2.Add(m3);
	madd.PrintMatrix(std::cout);
	cout<<"-->Minuse"<<endl;
	m2.Minuse(m3).PrintMatrix(std::cout);

	cout<<"-->Productor"					<<endl;
	m2.PrintMatrix(std::cout);
	cout<<"-"<<endl;
	m3.PrintMatrix(std::cout);
	cout<<"-"<<endl;
	m2.Productor(m3).PrintMatrix(std::cout);

	cout<<"-->Multiple"<<endl;
	m3.Multiple(2.0).PrintMatrix(std::cout);


	cout<<"--->Test of Matrix exception!"	<<endl;
	try
	{
		m1.Add(m2);
	}
	catch( SizeNotCompatible e )
	{
		cout<<"Exception happened!"			<<endl;
		cout<<e.what()<<endl;
	}
	cout<<endl;

	cout<<"Test of Transpose:" 				<<endl;
	m2.Transpose().PrintMatrix(std::cout);
	cout<<endl;
	m4.Transpose().PrintMatrix(std::cout);
	cout<<endl;
	Matrix<double> m5 = m4.Transpose();
	m5.PrintMatrix(std::cout);
	cout<<endl;

	cout<<"Test of Combine !"<<endl;
	m2.Combine(m2).PrintMatrix(std::cout);
	cout<<endl;
	m2.Combine(m3 , false ).PrintMatrix(std::cout);
	cout<<endl;
	
	cout<<"Test of DotToDotOperate!"		<<endl;
	m2.DotToDotOperate(m3 , max<double>).PrintMatrix(std::cout);

	return 0;
}
