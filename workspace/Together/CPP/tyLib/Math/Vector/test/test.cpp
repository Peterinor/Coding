/*
 *File		:test.cpp
 *Author	:tangyu
 *Date		:2011-06-01 12:41:30 
 *Version	:1.0.0
 *Modify	:2011-06-02 12:41:36 
 */

#include <iostream>

using std::cout;
using std::endl;

#include "../_Vector.h"

using ty::Math::Vector;
using namespace ty::ErrorHandle;

int main()
{
	//template Vector<double >;
	cout<<"Test of Vector"<<endl;
	
	double data[]={1,2,5,4,6,4,9,5,1};
	Vector<double > vec(5,data);
	vec.PrintVector(std::cout);
	Vector<double > voidvec(5);
	voidvec.PrintVector(std::cout);

	Vector<double > another(5,data+1);
	another.PrintVector(std::cout);
	cout<<"Test of Add Multiple Minuse !"<<endl;	
	try
	{	
		another.Add(vec)	.PrintVector(std::cout);
		another.Minuse(vec)	.PrintVector(std::cout);
		another.Multiple(2)	.PrintVector(std::cout);
	}
	catch(SizeNotCompatible e)
	{
		cout<<"----->Exception happened here!"	<<endl;
		cout<<"----->Exception type:"<<e.what()	<<endl;
	}
	cout<<"Test of copy Construction!"		<<endl;
	Vector<double > cpvec(vec);
	cpvec.PrintVector(std::cout);

	cout<<"Test of operator ="				<<endl;
	Vector<double >vvec=cpvec;
	vvec.PrintVector(std::cout);
	
	cout<<"Test of innerProductor!"				<<endl;
	cout<<"result="<<vec.InnerProductor(another)<<endl;

	cout<<"Test of OuterProductor!"				<<endl;
	vec.OuterProductor(another).PrintVector(std::cout);

	cout<<"Test of Norm!"						<<endl;
	cout<<"result="<<vec.Norm()<<endl;

	cout<<"Test of Correlation !"							<<endl;
	cout<<"Correlation?:"<<vec.Correlation(vec)				<<endl;
	cout<<"Correlation?:"<<vec.Correlation(another)			<<endl;
	cout<<"Correlation?:"<<vec.Correlation(vec.Multiple(2))	<<endl;

	return 0;
}
