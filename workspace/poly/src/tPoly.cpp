/*
Author:tangyu
Edited in 2011/1/20
File:tPoly.cpp
*/


#include "tPoly.h"


using namespace std;
using namespace ty;

//���캯��
tPoly::tPoly(void)
{
	//������ζ���ʽ��������
	this->n=0;
	this->coef=new double[1];
	this->coef[0]=0.0;
}

//����һ��n�ζ���ʽ
tPoly::tPoly(double n)
{
	this->n=n;
	this->coef=new double[this->n+1];
	for(int i=0;i<n+1;i++)
	{
		this->coef[i]=0.0;
	}
}

//������aΪϵ����������ʽ
tPoly::tPoly(double n,double *a)
{
	this->n=n;
	this->coef=new double[this->n+1];
	for(int i=0;i<n+1;i++)
	{
		this->coef[i]=a[i];
	}
}
//6x^4+7x^29
tPoly::tPoly(char* p)
{
	//��ȡ��
	this->poly=p;

	char *temp=p;
	string coefficient,degree;
	int coeff_index;

	//��ȡ����ʽ����	
	while(*temp!='^')
	{
		temp++;
	}
	temp++;
	while(*temp!='+')
	{
		degree.append(1,*temp);
		temp++;
	}

	//����ռ�
	this->n=atoi(degree.c_str());
	coeff_index=this->n;
	this->coef=new double[this->n+1];

	//��ȡ����ϵ���ʹ���
	temp=p;
	while(*temp!='\0')
	{
		//�Ƚ�ϵ��ָ���ַ������
		degree.clear();
		coefficient.clear();
		//��ȡϵ��
		while(*temp!='x'&&*temp!='\0')
		{
			coefficient.append(1,*temp);
			temp++;
		}
		//��ȡ����
		while(*temp!='^'&&*temp!='\0')
		{
			temp++;
		}
		temp++;
		while(*temp!='+'&&*temp!='\0')
		{
			degree.append(1,*temp);
			temp++;
		}
		temp++;

		int _degree=atoi(degree.c_str());
		for(int i=coeff_index;i>_degree;i--)
		{
			this->coef[i]=0;
		}
		coeff_index=_degree-1;
		//cout<<coefficient.c_str()<<endl;//������
		this->coef[_degree]=atof(coefficient.c_str());			

	}
	//��ȡ����a0��ϵ��
	string pf(p);
	degree.clear();
	coefficient.clear();
	temp=p+pf.find_last_of("+")+1;
	pf=string(temp);
	if(pf.find('x')==string::npos)
	{
		while(*temp!='\0')
		{
			coefficient.append(1,*temp);
			temp++;
		}
		this->coef[0]=atof(coefficient.c_str());
	}
	else
	{
		this->coef[0]=0;
	}/**/

}


tPoly::tPoly(string p)
{
	//��ȡ��
	this->poly=p;

	char *cp=new char[this->poly.size()];
	strcpy(cp,this->poly.c_str());
	char *temp=cp;
	string coefficient,degree;
	int coeff_index;

	//��ȡ����ʽ����	
	while(*temp!='^')
	{
		temp++;
	}
	temp++;
	while(*temp!='+')
	{
		degree.append(1,*temp);
		temp++;
	}

	//����ռ�
	this->n=atoi(degree.c_str());
	coeff_index=this->n;
	this->coef=new double[this->n+1];

	//��ȡ����ϵ���ʹ���
	temp=cp;
	while(*temp!='\0')
	{
		//�Ƚ�ϵ��ָ���ַ������
		degree.clear();
		coefficient.clear();
		//��ȡϵ��
		while(*temp!='x'&&*temp!='\0')
		{
			coefficient.append(1,*temp);
			temp++;
		}
		//��ȡ����
		while(*temp!='^'&&*temp!='\0')
		{
			temp++;
		}
		temp++;
		while(*temp!='+'&&*temp!='\0')
		{
			degree.append(1,*temp);
			temp++;
		}
		temp++;

		int _degree=atoi(degree.c_str());
		for(int i=coeff_index;i>_degree;i--)
		{
			this->coef[i]=0;
		}
		coeff_index=_degree-1;
		//cout<<coefficient.c_str()<<endl;//������
		this->coef[_degree]=atof(coefficient.c_str());			

	}
	//��ȡ����a0��ϵ��
	string pf(this->poly);
	degree.clear();
	coefficient.clear();
	temp=cp+pf.find_last_of("+")+1;
	pf=string(temp);
	if(pf.find('x')==string::npos)
	{
		while(*temp!='\0')
		{
			coefficient.append(1,*temp);
			temp++;
		}
		this->coef[0]=atof(coefficient.c_str());
	}
	else
	{
		this->coef[0]=0;
	}/**/

}

//�������캯��
tPoly::tPoly(const tPoly &  pt)
{
	this->n=pt.n;
	/*�����ǹ�����̣����Դ˿����Ƕ���ģ���
	//���������ʽ����ֵ
	if(NULL!=this->coef)
		delete []this->coef;
	*/
	this->coef=new double[this->n+1];

	for(int i=0;i<n+1;i++)
	{
		this->coef[i]=pt.coef[i];
	}
}

//��������
tPoly::~tPoly(void)
{
	delete []this->coef;
	//����delete this->coef;
}

//��ֵ���������
tPoly &tPoly::operator=(const tPoly &p)
{
	//����Ը�ֵ
	if(this == &p) 
		return *this; 
  
	//�ͷ�ԭ�е��ڴ���Դ 
	delete [] this->coef; 
   
	//�����µ��ڴ���Դ������������
	this->coef = new double[p.n];
	if(this->coef!=NULL)	//����ɹ�
	{
		for(int i=0;i<this->n;i++)
		{
			this->coef[i]=p.coef[i];
		}
	}   
	//���ر����������
	return *this; 
}

//����ʽ�໥����
//"+"
tPoly tPoly::operator+(const tPoly &p)
{
	int mdegree=max(this->n,p.n);
	if(mdegree==this->n)
	{
		tPoly res(this->n,this->coef);
		int i=0;
		for(i=0;i<p.n+1;i++)
		{
			res.coef[i]=res.coef[i]+p.coef[i];
		}
		return tPoly(res.n,res.coef);
	}
	else
	{
		tPoly res(p.n,p.coef);
		int i=0;
		for(i=0;i<this->n+1;i++)
		{
			res.coef[i]=res.coef[i]+this->coef[i];
		}
		return tPoly(res.n,res.coef);
	}
}

//"-"
tPoly tPoly::operator-(const tPoly &p)
{
	int mdegree=max(this->n,p.n);
	if(mdegree==this->n)
	{
		tPoly res(this->n,this->coef);
		int i=0;
		for(i=0;i<p.n+1;i++)
		{
			res.coef[i]=res.coef[i]-p.coef[i];
		}
		return tPoly(res.n,res.coef);
	}
	else
	{
		tPoly res(p.n,p.coef);
		int i=0;
		for(i=0;i<this->n+1;i++)
		{
			res.coef[i]=res.coef[i]-this->coef[i];
		}
		//˳�򲻶ԣ�ȡ�෴��
		for(int i=0;i<res.n+1;i++)
		{
			res.coef[i]=-res.coef[i];
		}
		return tPoly(res.n,res.coef);
	}

}

//"*"
tPoly tPoly::operator*(const tPoly &p)
{
	tPoly res(this->n+p.n);

	for(int i=0;i<res.n+1;i++)
	{
		res.coef[i]=Inner_q(i,this->coef,p.coef,this->n,p.n);
	}
	return tPoly(res.n,res.coef);
}
		
//����ʽ������㷵��,�˴�����()��������ö����������һ��ʹ�ã���ν���º�������
double tPoly::operator()(double x)
{
	double p=0.0;

	for(int i=1;i<this->n+1;i++)
	{
		p+=this->coef[i]*pow(x,i);
	}
	p+=this->coef[0];

	return p;
}

//�������ʽ
void tPoly::show()
{
	cout<<"����ʽ����:"<<endl;
	cout<<"f(x)="<<this->coef[this->n]<<"x^"<<this->n;
	for(int i=this->n-1;i>0;i--)
	{
		if(!IsZero(this->coef[i]))
		{
			if(IsBigZero(this->coef[i]))
				cout<<"+"<<this->coef[i]<<"x^"<<i;
			else
				cout<</*"-"<<*/this->coef[i]<<"x^"<<i;
		}
	}
	if(!IsZero(this->coef[0]))
	{
		if(IsBigZero(this->coef[0]))
			cout<<"+"<<this->coef[0];
		else
			cout<</*"-"<<*/this->coef[0];
	}
	cout<<endl;
}


