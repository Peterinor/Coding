/*
edited in 2010/11/01
builed in 2010/11/01
Version 1.1
*/

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int N;		//方程的阶数,改用变量，可以由使用者决定方程阶数，程序更加灵活

double Main_Element;	//记录每次选择的主元

double **A;
double **B;
double **A_B;
double **X;

/*
	{3,1,6};
A=	{2,1,3};
	{1,1,1};
B=	{2,7,4};
求的根为：X={19,-7,-8};
*/

/*
为变量分配存储空间，初始化系数矩阵
v1.0
*/
void Init_Data();

/*
销毁变量空间
v1.0
*/
void Destroy_Data();

/*
求方程组Ax=B的增广矩阵A_B
v1.0
*/
double** AUB(int N,double **A,double **B,double **A_B);	

/*
用于显示矩阵的详细参数,row x col型
v1.0
*/
void Show_Matrix(double **A,int row,int col);

/*
用于横向显示向量,N x 1型
v1.0
*/
void Show_Result(int x,/*表征解的个数*/int N);

int Gauss_Colum_Main_Element(
							int n,			//方程阶数
							double **A,		//系数矩阵
							double**B,		//
							double e);		//精度控制

/*
确定列主元素所在行，并返回行号
V1.0
*/
int Choose_Colum_Main_Element(
							int n,			//方程阶数
							double**A,		//系数矩阵
							int start);
/*
交换矩阵L1,L2两行
*/
void Exchange(double **A,int num_of_colum,int L1,int L2);

/*
单位化系数矩阵,更准确地说是将矩阵A的左上角nxn个分块矩阵单位化
v1.0
*/
double **Unitization(int n/*方程阶数*/,double**A	/*系数矩阵*/);

/*
对确定好列主元素的矩阵进行消元处理
*/
void Elimination(int n,double**A,int start);


int main()
{
	bool willgo;
	do
	{	
		Init_Data();		
		Show_Result(Gauss_Colum_Main_Element(N,A,B,0),N);
		cout<<"退出(0)还是继续求解其他方程组(1)?"<<endl;
		Destroy_Data();
		
		cin>>willgo;
	}while(willgo);	
	
	return 0;	
}

void Init_Data()
{
	cout<<"请输入方程的阶数："<<endl;
	cin>>N;
	while(N<=0)
	{
		cout<<"请输入有效的方程阶数"<<endl;
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
	cout<<"您选择了"<<N<<"阶方程组计算.\n请输入系数矩阵A（按行输入）:"<<endl;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>A[i][j];
		}
	}
	cout<<"请输入矩阵B:"<<endl;
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

void Show_Result(int x/*表征解的个数*/,int N)
{
	if(x==0)
	{
		cout<<"由于消元过程中出现主元小于所设定的精度,且此时增广矩阵中B!~0\n"
			<<"所以：方程无解"<<endl;
		return ;
	}
	if(x==-1)
	{
		cout<<"方程组为任意解"<<endl;
		return ;
	}
	cout<<"所求方程组的根为:(x1,x2,x3)=( ";
	for(int i=0;i<N;i++)
	{
		cout<<X[i][0]<<" ,";
	}
	cout<<"\b)."<<endl<<endl;
	
}

int Gauss_Colum_Main_Element(
							int N,			//方程阶数
							double **A,		//系数矩阵
							double**B,		//
							double e)		//精度控制
{
	cout<<endl<<"Ax=B的增广矩阵为:"<<endl;
	Show_Matrix(A_B,N,N+1);
	cout<<"解方程Ax=B的过程如下:"<<endl;
	for(int i=0;i<N;i++)
	{
		int row=Choose_Colum_Main_Element(N,A_B,i);
		if(Main_Element<=e) goto A_0;
		Exchange(A_B,N+1,row,i);
		Elimination(N,A_B,i);
		cout<<"选取列主元后第"<<i+1<<"次消元:"<<endl;
		Show_Matrix(A_B,N,N+1);
	}
	
	Unitization(N,A_B);
	cout<<"单位化之后的结果:"<<endl;
	Show_Matrix(A_B,N,N+1);
	for(int i=0;i<N;i++)
	{
		X[i][0]=A_B[i][N];
	}	
	return 1;

A_0:	//如果出现增广矩阵中|A|~0的情况处理如下
	for(int i=0;i<N;i++)
	{
		//增广矩阵中|B|!~0
		if(abs(A_B[i][N])>e) return 0;
	}
	//增广矩阵中|B|~0,即方程解为任意解的情况
	/*
	for(int i=0;i<N;i++)
	{
		X[i][0]=0;
	}*/
	return -1;
	
}

//返回主元所在的行
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
//交换L1,L2行
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

//回带求解，即单位化系数矩阵
double **Unitization(int n,double**A)
{
	double row_first;	//行首元素
	//主对角元素单位化
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
