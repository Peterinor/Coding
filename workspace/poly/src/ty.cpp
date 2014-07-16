#include"ty.h"

//��������
//�����жϸ�����x�Ƿ�Ϊ0.0������epsΪ0.0������Χ��Ĭ��Ϊ10^-9
bool ty::IsZero(double x,double eps)
{
	return abs(x)<eps;
}

//�����жϸ�����x�Ƿ����0.0������epsΪ0.0������Χ��Ĭ��Ϊ10^-9
bool ty::IsBigZero(double x,double eps)
{
	return x>eps;
}

//�����жϸ�����x�Ƿ�С��0.0������epsΪ0.0������Χ��Ĭ��Ϊ10^-9
bool ty::IsSmallZero(double x,double eps)
{
	return x<-eps;
}

#define NOPOSSIBLE		0.0

//����a[]��b[]��q���ڻ�����Ȼ������ɽ���
double ty::Inner_q(int q,double a[],double b[],int a_m,int b_m)
{
	if(q>b_m+a_m||q<0)
	{
		/*ԭ�������ݴ���ʱ��Ӧ�÷����κ�ֵ�ģ����Ǵ˴������ѷ���0.0(NOPOSSIBLE)�����ʹ�õ�ʱ��ע��ͺ�
		**���Ǵ��Ҳ������ʹ�õ�ʱ��Ԥ�ȶ���һ�������ܳ��ֵ�������Ϊ���󷵻أ���˴���0.0
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