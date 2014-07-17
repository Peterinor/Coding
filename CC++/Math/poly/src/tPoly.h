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
		//���캯��
		tPoly(void);
		tPoly(double n);
		tPoly(double n,double *a);
		tPoly(char* p);
		tPoly(string p);
		tPoly(const tPoly &  pt);
	
		//��������
		virtual ~tPoly(void);
	
		//��������ز���
		//��ֵ���������
		tPoly &operator=(const tPoly &p);
		//��ֵ���������
		/*ע�⣺����ʽ��������Ӧ����ȻΪ����ʽ�����Բ����ж���ʽ�ĳ�����
		���ǿ��Լ������ʽ��ֵ���̣�ͬ���ģ�Ҳû��ʵ�ֶ���ʽ�ĳ˷���ӦΪ�˷��ǻ��ڳ˷���*/
		tPoly operator+(const tPoly &p);
		tPoly operator-(const tPoly &p);
		tPoly operator*(const tPoly &p);
		
		//����ʽ������㷵��
		double operator()(double x);

		void show();		

	private:
		double *coef;		//����ʽϵ��
		int n;				//����ʽ����
		string poly;
	};

}
