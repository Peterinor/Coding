#include"ty.h"

//辅助函数
//用于判断浮点数x是否为0.0，其中eps为0.0的容许范围，默认为10^-9
bool ty::IsZero(double x,double eps)
{
	return abs(x)<eps;
}

//用于判断浮点数x是否大于0.0，其中eps为0.0的容许范围，默认为10^-9
bool ty::IsBigZero(double x,double eps)
{
	return x>eps;
}

//用于判断浮点数x是否小于0.0，其中eps为0.0的容许范围，默认为10^-9
bool ty::IsSmallZero(double x,double eps)
{
	return x<-eps;
}

#define NOPOSSIBLE		0.0

//数组a[]、b[]的q次内积，显然，结果可交换
double ty::Inner_q(int q,double a[],double b[],int a_m,int b_m)
{
	if(q>b_m+a_m||q<0)
	{
		/*原则上数据错误时不应该返回任何值的，但是此处不得已返回0.0(NOPOSSIBLE)，大家使用的时候注意就好
		**但是大家也可以在使用的时候预先定义一个不可能出现的数字作为错误返回，如此处的0.0
		*/
		cout<<"Request Error!"<<endl;
		return NOPOSSIBLE;
	}
	double res=0.0;
	for(int i=0;i<a_m+1;i++)
	{
		if(q-i<b_m+1&&q-i>=0)
			res+=a[i]*b[q-i];
	}
	return res;
}