/*
 * File		:farmland.cpp
 * Author	:tangyu
 * Date		:2011-05-22 22:30:25 
 * Version	:0.1
 * LastMod	:2011-05-24 22:30:28 
 */ 

#include"farmland.h"
#include<cstdlib>
#include<cstring>
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

/**		构造函数		**/
Farmland::Farmland(void)
{
	this->Allocate(0);
	this->ClearLand();
}


Farmland::Farmland(int landsize)
{
	this->Allocate(landsize);
	this->ClearLand();	
}


Farmland::Farmland(const Farmland & src)
{
	this->Allocate(src.landSize);
	this->ClearLand();
	for(int i=1;i<this->landSize+1;i++)
	{	
	/*
		for(int j=1;j<this->landSize+1;j++)
		{
			this->landData[i][j]=src.landData[i][j];
		}
	*/
		memcpy(this->landData[i],src.landData[i],this->landSize+2);
	}
}

Farmland::Farmland(int landsize, unit_type * landdata)
{
	this->Allocate(landsize);
	this->ClearLand();
	this->SetLandData(landdata);
}

Farmland::Farmland(int landsize, string landdata)
{
	this->Allocate(landsize);
	this->ClearLand();
	this->SetLandData(landdata);
}


Farmland::~Farmland()
{
	this->DeAllocate();
}


/**		生成相关函数		**/
string 	Farmland::NextGeneration(void )
{
	string state=this->ReportLandState();
	Farmland temp(*this);
	for(int i=1;i<this->landSize+1;i++)
	{
		for(int j=1;j<this->landSize+1;j++)
		{
			if(temp.GetCellState(i,j)>_TOO_CROWDED || temp.GetCellState(i,j)<_TOO_LONELY)
				this->landData[i][j]=false;
			else
				this->landData[i][j]=true;
		}
	}
	return state;
}
	
string Farmland::ReportLandState(void )
{
	string state;
	for(int i=1;i<this->landSize+1;i++)
	{
		for(int j=1;j<this->landSize+1;j++)
		{
			if(this->landData[i][j])
				state.append("1");
			else
				state.append("0");
		}
	}
	
	return state;	
}
	
int 	Farmland::GetCellState(int i, int j)
{
	return 	this->landData[i-1][j-1]	+	this->landData[i-1][j]	+	this->landData[i-1][j+1]	+
			this->landData[i][j-1]		+	0/*self to align */ 	+	this->landData[i][j+1]		+
			this->landData[i+1][j-1]	+	this->landData[i+1][j]	+	this->landData[i+1][j+1];
}


void 	Farmland::PrintLand(void)
{
	//cout<<"Print"<<endl;
	for(int i=1;i<this->landSize+1;i++)
	{
		//cout<<"Print1"<<endl;
		for(int j=1;j<this->landSize+1;j++)
		{
			//cout<<"Print2";
			cout<<(this->landData[i][j]?_LIFE:_DEATH)<<" ";
		}
		cout<<endl;
	}
}



/**		内存分配相关函数			**/
void 	Farmland::Allocate(int landsize)
{
	this->landSize=landsize;
	this->landData=NULL;
	if(this->landSize>0)
	{
		//cout<<"allocate"<<endl;
		this->landData=new unit_type *[this->landSize+2];
		for(int i=0;i<this->landSize+2;i++)
		{
			this->landData[i]=new unit_type[this->landSize+2];
		}
	
	}
}

void 	Farmland::DeAllocate(void)
{
	if(this->landData)
	{
		for(int i=0;i<this->landSize+2;i++)
		{
			delete this->landData[i];
		}
		delete [] this->landData;
	}
}


/**		数据设定相关函数		**/

void 	Farmland::SetLand(int landsize,unit_type *landdata)
{
	if(this->landSize!=landsize)
	{
		this->DeAllocate();
		this->Allocate(landsize);
	}
	this->ClearLand();
	this->SetLandData(landdata);
}

void 	Farmland::SetLand(int landsize,string landdata)
{
	if(this->landSize!=landsize)
	{
		this->DeAllocate();
		this->Allocate(landsize);
	}
	this->ClearLand();
	this->SetLandData(landdata);
}

void	Farmland::SetLandData(unit_type * landdata)
{
	if(this->landData==NULL)
		return ;
	for(int i=1;i<this->landSize+1;i++)
	{
		for(int j=1;j<this->landSize+1;j++)
		{
			this->landData[i][j]=landdata[(i-1)*this->landSize+(j-1)];
		}

	}
}
void 	Farmland::SetLandData(string landdata)
{
	if(this->landData==NULL)
		return ;
	for(int i=1;i<this->landSize+1;i++)
	{
		for(int j=1;j<this->landSize+1;j++)
		{
			this->landData[i][j]=(landdata[(i-1)*this->landSize+(j-1)]=='0') ? false : true ;
		}

	}
	
}

void	Farmland::ClearLand(void)
{
	if(this->landData==NULL)
		return ;
	for(int i=0;i<this->landSize+2;i++)
	{
		for(int j=0;j<this->landSize+2;j++)
		{
			this->landData[i][j]=false;
		}
	}
	
}

/**		获取相关信息		**/
int 	Farmland::GetLandSize(void ) const
{
	return this->landSize;
}

unit_type	Farmland::GetLandData(void ) const		/*	慎用		*/
{
	return this->landData;
}


