/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.3
 *Date		:2011-4-4
 *Describ	:实现对Hex文件数据的提取
 *			 使用c++类实现算法并且实现文件分离
 *			 更改来Show()方法
 ********************************************************************
 */

#include "../includes/HexData.h"

Hex::Hex()
{
	this->GetDataStr(":00000001FF");

}

Hex::Hex(string data)
{
}

Hex::Hex(char * data)
{
	GetDataStr(data);
}


Hex::~Hex()
{
	// TODO Auto-generated destructor stub
}


void Hex::GetDataStr(char * line)
{
	int i=0;
	if(line[i]!=':')
	{
		cout<<"error code!"<<endl;
		this->rec_type=H_ERR;
	}
	i+=1;	//指向字节数起始位置
	this->byte_count=16*(get_Num(line[i]))+get_Num(line[i+1]);

	i+=2;	//指向地址段起始位置
	this->address=16*16*16*get_Num(line[i])
					+16*16*get_Num(line[i+1])
					+16*get_Num(line[i+2])+get_Num(line[i+3]);

	i+=4;	//指向数据记录类型段起始位置
	this->rec_type=/*16*get_Num(line[i])+*/(Record_Type)get_Num(line[i+1]);	//因为类型段不可能大于5，故。。。

	i+=2;	//指向数据段起始位置
	this->pdata=new unsigned char[this->byte_count];
	for(unsigned int k=0;k<this->byte_count;k++)
	{
		this->pdata[k]=16*(get_Num(line[i]))+get_Num(line[i+1]);
		i+=2;
	}

	i=i;	//指向校验和段起始位置
	this->chechsum=16*(get_Num(line[i]))+get_Num(line[i+1]);
}

bool Hex::Show()
{
	if(this->rec_type==H_EOF)
	{
		cout<<"End Of Code!!"<<endl;
		return true;
	}
	cout<<"Information of Rec:"<<endl;
	cout<<_hex_
#if HP_TYPE
		<<_hex_
		<<"DataType :	"	<<_0x_<<this->rec_type	<<endl
#endif
#if HP_ADD
		<<_hex_
		<<"Address  :	"	<<_0x_<<this->address	<<endl
#endif
#if HP_COUNT
		<<_hex_
		<<"ByteCount:	"	<<dec<<this->byte_count<<endl			//数据段大小始终使用10进制输出
#endif
#if HP_CHSUM
		<<_hex_
		<<"CheckSum :	"	<<_0x_<<this->chechsum	<<endl
#endif
		<<"";
#if	HP_DATA
	cout<<"Data     :	"	<<endl<<"---->";
	for(unsigned int i=0;i<this->byte_count;i++)
	{
		cout<<_hex_<<_0x_<<(unsigned int)this->pdata[i]<<"  .  ";
		//printf("  0x%x.  ",this->pdata[i]);
	}
#endif
	cout<<endl;

	return false;
}




/*
 *
 */
int get_Num(char ch)
{
	if(!isalnum(ch))
	{
		cout<<"Error Code!!"<<endl;
		return -1;
	}
	if(isupper(ch))
	{
		return ch-'A'+10;
	}
	else if(islower(ch))
	{
		return ch-'a'+10;
	}
	else
	{
		return ch-'0';
	}
}
