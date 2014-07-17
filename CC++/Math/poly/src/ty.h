
#include<iostream>
#include<string>
//#include<vector>

#include<cmath>
#include<iomanip>


#include"tObject.h"


using namespace std;

namespace ty
{
	
	bool IsZero(double x,double eps=0.000000001);
	bool IsBigZero(double x,double eps=0.000000001);
	bool IsSmallZero(double x,double eps=0.000000001);

	double Inner_q(int q,double a[],double b[],int a_m,int b_m);
}