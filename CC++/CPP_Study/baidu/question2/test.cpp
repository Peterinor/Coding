/*
 *File		:test.cpp
 *Author	:tangyu
 *Date		:2011-05-27 22:09:49 
 *Version	:1.0.0
 *Modify	:
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<vector>
using std::vector;

typedef vector<int > Satisfy;

void Simplify( int & sum, int & m)
{
	bool simp = false;
	do
	{
		for( int i =1 ; i < m+1 /*i<=m*/; i++ )
		{
			int sumi=sum/i;
			double sumd=(double)sum/double(i);
			int mi=m/i;
			double md=(double)m/(double)i;
			if( sumi==sumd && mi==md )
			{
				sum=sum/i;
				m=m/i;
				//cout<<m<<endl;
				i = 1;
			}		
		}
		simp= true;
		
	}while(!simp);
}

class Baidu
{
public:
	Baidu():size(0),least(0){}
	Baidu(int s , int l):size(s),least(l)
	{
		this->num=this->least;
	}

	void Solve()
	{
		int maxSA = 0;	
		for ( Satisfy::iterator it = this->A.begin() ; it != this->A.end()-this->least + 1 ; it++ )
		{
			this->lastAvg = (double)maxSA/(double)this->num;
			int temp = this->sum(it);
			//cout<<temp<<endl;
			if( (double)temp/(double)this->num > lastAvg )
			{	
				maxSA=temp; 
			}
			
		}
		double maxA = (double)maxSA/(double)this->num;
		if((double)maxSA == maxA)
			cout<<maxA<<endl;
		else
		{
			int sum = maxSA;
			int m   = this->num;
			//cout<<sum<<"  ,  "<<m<<endl;
			Simplify(sum,m);
			cout<<sum<<"/"<<m<<endl;

		} 		
	}

	int sum( Satisfy::iterator b)
	{		
		int maxsum = 0 ;
		double lastAvg_=0.0;
		Satisfy::iterator it;
		int n = 0;
		for( int j = 0 ; j < this->size - this->least; j ++ )
		{
			n = 0;
			int sum=0;
			for( it=b ; it!=b + this->least  + j  && it!=this->A.end()+1; it++ )
			{				
				n++;
				sum+=*it;			
			}
			double avr = (double)sum/(double)n ;
			if( avr > lastAvg_)
			{
				cout<<"aaaa"<<avr<<"  "<<lastAvg_<<"  "<<maxsum<<"  "<<n<<endl;
				maxsum=sum;
				lastAvg_ =(double) maxsum / (double)n;
				this->num = n;
				
			}
			//cout<<endl;
		}	
		
		return maxsum;
	}

int size;
int least;
Satisfy A;
int num;
double lastAvg;
};


int main()
{
	for( int i =0 ; i != 0 ; i++ )
	{
		cout<<"one"<<endl;
	}
	int size=0,least =0;
	cin>>size;
	cin>>least;
	int data=0;
	Baidu baidu(size, least);
	for( int i =0 ; i < baidu.size ; i++ )
	{
		cin>>data;
		baidu.A.push_back(data);
	}
	baidu.Solve();


	return 0;
}
