/*
edited in 2010/11/01
builed in 2010/11/01
Version 1.1
*/

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int N;		//���̵Ľ���,���ñ�����������ʹ���߾������̽���������������

double Main_Element;	//��¼ÿ��ѡ�����Ԫ

double **A;
double **B;
double **A_B;
double **X;

/*
	{3,1,6};
A=	{2,1,3};
	{1,1,1};
B=	{2,7,4};
��ĸ�Ϊ��X={19,-7,-8};
*/

/*
Ϊ��������洢�ռ䣬��ʼ��ϵ������
v1.0
*/
void Init_Data();

/*
���ٱ����ռ�
v1.0
*/
void Destroy_Data();

/*
�󷽳���Ax=B���������A_B
v1.0
*/
double** AUB(int N,double **A,double **B,double **A_B);	

/*
������ʾ�������ϸ����,row x col��
v1.0
*/
void Show_Matrix(double **A,int row,int col);

/*
���ں�����ʾ����,N x 1��
v1.0
*/
void Show_Result(int x,/*������ĸ���*/int N);

int Gauss_Colum_Main_Element(
							int n,			//���̽���
							double **A,		//ϵ������
							double**B,		//
							double e);		//���ȿ���

/*
ȷ������Ԫ�������У��������к�
V1.0
*/
int Choose_Colum_Main_Element(
							int n,			//���̽���
							double**A,		//ϵ������
							int start);
/*
��������L1,L2����
*/
void Exchange(double **A,int num_of_colum,int L1,int L2);

/*
��λ��ϵ������,��׼ȷ��˵�ǽ�����A�����Ͻ�nxn���ֿ����λ��
v1.0
*/
double **Unitization(int n/*���̽���*/,double**A	/*ϵ������*/);

/*
��ȷ��������Ԫ�صľ��������Ԫ����
*/
void Elimination(int n,double**A,int start);


int main()
{
	bool willgo;
	do
	{	
		Init_Data();		
		Show_Result(Gauss_Colum_Main_Element(N,A,B,0),N);
		cout<<"�˳�(0)���Ǽ����������������(1)?"<<endl;
		Destroy_Data();
		
		cin>>willgo;
	}while(willgo);	
	
	return 0;	
}

void Init_Data()
{
	cout<<"�����뷽�̵Ľ�����"<<endl;
	cin>>N;
	while(N<=0)
	{
		cout<<"��������Ч�ķ��̽���"<<endl;
		cin>>N;
	}
	A=new double*[sizeof(double*)*N];
	B=new double*[sizeof(double*)*1];
	A_B=new double*[sizeof(double*)*(N+1)];
	X=new double*[sizeof(double*)*1];
	
	for(int i=0;i<N;i++)
	{
		A[i]=new double[N];
		B[i]=new double[1];
		A_B[i]=new double[N+1];
		X[i]=new double[1];
	}
	cout<<"��ѡ����"<<N<<"�׷��������.\n������ϵ������A���������룩:"<<endl;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>A[i][j];
		}
	}
	cout<<"���������B:"<<endl;
	for(int i=0;i<N;i++)
	{		
		cin>>B[i][0];
	}

	AUB(N,A,B,A_B);

}

void Destroy_Data()
{	
	for(int i=0;i<N;i++)
	{
		delete A[i];
		delete B[i];
		delete A_B[i];
		delete X[i];
	}
	delete A;
	delete B;
	delete A_B;
	delete X;
}

double** AUB(int N,double **A,double **B,double **A_B)	
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			A_B[i][j]=A[i][j];
		}
		A_B[i][N]=B[i][0];
	}
	return A_B;
}

void Show_Matrix(double **A,int row,int col)
{
	cout<<endl;
	for(int i=0;i<row;i++)
	{
		cout<<"|";
		for(int j=0;j<col;j++)
		{
			cout<<setw(10)<<A[i][j];
		}
		cout<<"   |";
		cout<<endl;
	}
	cout<<endl;
}

void Show_Result(int x/*������ĸ���*/,int N)
{
	if(x==0)
	{
		cout<<"������Ԫ�����г�����ԪС�����趨�ľ���,�Ҵ�ʱ���������B!~0\n"
			<<"���ԣ������޽�"<<endl;
		return ;
	}
	if(x==-1)
	{
		cout<<"������Ϊ�����"<<endl;
		return ;
	}
	cout<<"���󷽳���ĸ�Ϊ:(x1,x2,x3)=( ";
	for(int i=0;i<N;i++)
	{
		cout<<X[i][0]<<" ,";
	}
	cout<<"\b)."<<endl<<endl;
	
}

int Gauss_Colum_Main_Element(
							int N,			//���̽���
							double **A,		//ϵ������
							double**B,		//
							double e)		//���ȿ���
{
	cout<<endl<<"Ax=B���������Ϊ:"<<endl;
	Show_Matrix(A_B,N,N+1);
	cout<<"�ⷽ��Ax=B�Ĺ�������:"<<endl;
	for(int i=0;i<N;i++)
	{
		int row=Choose_Colum_Main_Element(N,A_B,i);
		if(Main_Element<=e) goto A_0;
		Exchange(A_B,N+1,row,i);
		Elimination(N,A_B,i);
		cout<<"ѡȡ����Ԫ���"<<i+1<<"����Ԫ:"<<endl;
		Show_Matrix(A_B,N,N+1);
	}
	
	Unitization(N,A_B);
	cout<<"��λ��֮��Ľ��:"<<endl;
	Show_Matrix(A_B,N,N+1);
	for(int i=0;i<N;i++)
	{
		X[i][0]=A_B[i][N];
	}	
	return 1;

A_0:	//����������������|A|~0�������������
	for(int i=0;i<N;i++)
	{
		//���������|B|!~0
		if(abs(A_B[i][N])>e) return 0;
	}
	//���������|B|~0,�����̽�Ϊ���������
	/*
	for(int i=0;i<N;i++)
	{
		X[i][0]=0;
	}*/
	return -1;
	
}

//������Ԫ���ڵ���
int Choose_Colum_Main_Element(int n,double**A,int start)
{
	int row=start;
	double max=abs(A[start][start]);
	for(int i=start;i<n;i++)
	{		
		if(max<abs(A[i][start]))
		{
			row=i;			
			max=A[i][start];
		}
	}
	Main_Element=max;
	return row;
}
//����L1,L2��
void Exchange(double **A,int num_of_colum,int L1,int L2)
{
	double temp;
	for(int i=0;i<num_of_colum;i++)
	{
		temp=A[L1][i];
		A[L1][i]=A[L2][i];
		A[L2][i]=temp;
	}
}

void Elimination(int n,double**A,int start)
{
	double factor;
	for(int i=start+1;i<n;i++)
	{
		factor=A[i][start]/A[start][start];
		for(int j=start;j<n+1;j++)
		{
			A[i][j]=A[i][j]-factor*A[start][j];
		}
	}
}

//�ش���⣬����λ��ϵ������
double **Unitization(int n,double**A)
{
	double row_first;	//����Ԫ��
	//���Խ�Ԫ�ص�λ��
	for(int i=0;i<n;i++)
	{
		row_first=A[i][i];
		for(int j=0;j<n+1;j++)
		{
			A[i][j]=A[i][j]/row_first;
		}
	}	
	
	for(int k=n-1;k>0;k--)
	{
		for(int i=0;i<k;i++)
		{
			double factor=A[i][k];
			for(int j=0;j<n+1;j++)
			{
				A[i][j]=A[i][j]-factor*A[k][j];
			}
			
		}
	}
	return A;
}
