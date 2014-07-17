/*
Author:tangyu
Edited in 2011/1/20
File:tPoly.cpp
*/


#include "tPoly.h"


using namespace std;
using namespace ty;

//构造函数
tPoly::tPoly(void)
{
	//建立零次多项式，即常数
	this->n=0;
	this->coef=new double[1];
	this->coef[0]=0.0;
}

//创建一个n次多项式
tPoly::tPoly(double n)
{
	this->n=n;
	this->coef=new double[this->n+1];
	for(int i=0;i<n+1;i++)
	{
		this->coef[i]=0.0;
	}
}

//以数组a为系数创建多项式
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
	//获取串
	this->poly=p;

	char *temp=p;
	string coefficient,degree;
	int coeff_index;

	//获取多项式次数	
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

	//分配空间
	this->n=atoi(degree.c_str());
	coeff_index=this->n;
	this->coef=new double[this->n+1];

	//获取各项系数和次数
	temp=p;
	while(*temp!='\0')
	{
		//先将系数指数字符串清空
		degree.clear();
		coefficient.clear();
		//获取系数
		while(*temp!='x'&&*temp!='\0')
		{
			coefficient.append(1,*temp);
			temp++;
		}
		//获取次数
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
		//cout<<coefficient.c_str()<<endl;//调试用
		this->coef[_degree]=atof(coefficient.c_str());			

	}
	//获取最后的a0项系数
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
	//获取串
	this->poly=p;

	char *cp=new char[this->poly.size()];
	strcpy(cp,this->poly.c_str());
	char *temp=cp;
	string coefficient,degree;
	int coeff_index;

	//获取多项式次数	
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

	//分配空间
	this->n=atoi(degree.c_str());
	coeff_index=this->n;
	this->coef=new double[this->n+1];

	//获取各项系数和次数
	temp=cp;
	while(*temp!='\0')
	{
		//先将系数指数字符串清空
		degree.clear();
		coefficient.clear();
		//获取系数
		while(*temp!='x'&&*temp!='\0')
		{
			coefficient.append(1,*temp);
			temp++;
		}
		//获取次数
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
		//cout<<coefficient.c_str()<<endl;//调试用
		this->coef[_degree]=atof(coefficient.c_str());			

	}
	//获取最后的a0项系数
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

//拷贝构造函数
tPoly::tPoly(const tPoly &  pt)
{
	this->n=pt.n;
	/*由于是构造过程，所以此考虑是多余的！！
	//先清除多项式储存值
	if(NULL!=this->coef)
		delete []this->coef;
	*/
	this->coef=new double[this->n+1];

	for(int i=0;i<n+1;i++)
	{
		this->coef[i]=pt.coef[i];
	}
}

//析构函数
tPoly::~tPoly(void)
{
	delete []this->coef;
	//或者delete this->coef;
}

//赋值运算符重载
tPoly &tPoly::operator=(const tPoly &p)
{
	//检查自赋值
	if(this == &p) 
		return *this; 
  
	//释放原有的内存资源 
	delete [] this->coef; 
   
	//分配新的内存资源，并复制内容
	this->coef = new double[p.n];
	if(this->coef!=NULL)	//分配成功
	{
		for(int i=0;i<this->n;i++)
		{
			this->coef[i]=p.coef[i];
		}
	}   
	//返回本对象的引用
	return *this; 
}

//多项式相互运算
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
		//顺序不对，取相反数
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
		
//多项式本身计算返回,此处重载()运算符，让对象可以像函数一样使用！所谓“仿函数”！
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

//输出多项式
void tPoly::show()
{
	cout<<"多项式如下:"<<endl;
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


