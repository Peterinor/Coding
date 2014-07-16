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

#include<algorithm>

#include <string>
using std::string;

#include<vector>
using std::vector;

typedef vector<int 		> VRing;
typedef vector<string	> VString;


class Circle
{
public:
	Circle():size(0),swap1(0),swap2(0){}
	Circle(int s, int s1 , int s2 ):size(s),swap1(s1),swap2(s2)
	{}

	string IsOk()
	{
		//cout<<this->ToString()<<endl;
		while(!this->IsSorted() && !this->IsLoop())	
		{
			if(this->Disorder())
			{
				this->swap();
				this->state.push_back(this->ToString());
				continue;
			}			
			this->roll();
		}
		if(this->IsSorted())
			return "YES";
		else
			return "NO";
	}

	void swap()
	{
		int temp = this->ring[this->swap1];
		this->ring[this->swap1]=this->ring[this->swap2];
		this->ring[this->swap2]=temp;	
	}

	void roll()
	{
		int temp=this->ring[0];
		for(int i =0 ; i<this->size -1 ; i++)
		{
			this->ring[i]=this->ring[i+1];
		}		
		this->ring[this->size-1]=temp;
	}

	bool Disorder()
	{
		return this->ring[this->swap1] > ring[this->swap2];
	}

	bool IsSorted()
	{
		bool sorted = true;
		int i =0 ;
		for( ; i<this->size -1; i++ )
		{
			if(ring[i]>ring[i+1])
			{
				//sorted=false;
				break;
			}
		}
	//	cout<<"i="<<i++<<endl;
		for( ; i<this->size -1; i++ )
		{
			if(ring[i]>ring[i+1])
			{
				sorted=false;
				break;
			}
		}
		return sorted;
			
	}
	

	bool IsLoop()
	{
		VString::iterator it = std::find(this->state.begin(),this->state.end(),this->ToString());
		if(it==this->state.end())
			return false;
		else
			return true;	
	}

	string ToString()
	{
		string temp(size,'\0');	
		for( int i =0 ; i<this->size ; i++ )
		{
			temp[i]=this->ring[i]+'0';
		}
		return temp;
	}
//private:
	int size;
	int swap1 , swap2;
	VRing 	ring;
	VString	state;
	
};

typedef vector<Circle	> VGame;

int main()
{
	//初始化数据
	Circle gtemp;
	//VGame game;
	int size;
	cin>>size;
	do
	{		
		if(size!=0)
		{
			int s1=0 , s2 =0;
			cin>>s1;
			cin>>s2;
			Circle temp(size, s1, s2);
			gtemp=temp;
			//game.push_back(temp);
			int data = 0;
			for( int i = 0 ; i<temp.size ; i++ )
			{
				cin>>data;
				temp.ring.push_back(data);
			}	
			cout<<temp.IsOk()<<endl;				
		
		}	
		else
		{
			break;	
		}	
		cin>>size;
	}while(1);

	return 0;
}
