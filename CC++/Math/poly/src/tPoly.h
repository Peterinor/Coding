#pragma once
/*
Author:tangyu
Edited in 2011/1/20
File:tPoly.h
*/


#include"ty.h"
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;
namespace ty
{
	class tPoly	:	
		tObject
	{
	public:
		//构造函数
		tPoly(void);
		tPoly(double n);
		tPoly(double n,double *a);
		tPoly(char* p);
		tPoly(string p);
		tPoly(const tPoly &  pt);
	
		//析构函数
		virtual ~tPoly(void);
	
		//运算符重载部分
		//赋值运算符重载
		tPoly &operator=(const tPoly &p);
		//数值运算符重载
		/*注意：多项式的运算结果应该仍然为多项式，所以不会有多项式的除法，
		但是可以计算多项式的值的商，同样的，也没有实现多项式的乘方，应为乘方是基于乘方的*/
		tPoly operator+(const tPoly &p);
		tPoly operator-(const tPoly &p);
		tPoly operator*(const tPoly &p);
		
		//多项式本身计算返回
		double operator()(double x);

		void show();		

	private:
		double *coef;		//多项式系数
		int n;				//多项式次数
		string poly;
	};

}
