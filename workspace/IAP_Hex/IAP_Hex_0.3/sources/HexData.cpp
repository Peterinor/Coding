/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.3
 *Date		:2011-4-4
 *Describ	:ʵ�ֶ�Hex�ļ����ݵ���ȡ
 *			 ʹ��c++��ʵ���㷨����ʵ���ļ�����
 *			 ������Show()����
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
	i+=1;	//ָ���ֽ�����ʼλ��
	this->byte_count=16*(get_Num(line[i]))+get_Num(line[i+1]);

	i+=2;	//ָ���ַ����ʼλ��
	this->address=16*16*16*get_Num(line[i])
					+16*16*get_Num(line[i+1])
					+16*get_Num(line[i+2])+get_Num(line[i+3]);

	i+=4;	//ָ�����ݼ�¼���Ͷ���ʼλ��
	this->rec_type=/*16*get_Num(line[i])+*/(Record_Type)get_Num(line[i+1]);	//��Ϊ���Ͷβ����ܴ���5���ʡ�����

	i+=2;	//ָ�����ݶ���ʼλ��
	this->pdata=new unsigned char[this->byte_count];
	for(unsigned int k=0;k<this->byte_count;k++)
	{
		this->pdata[k]=16*(get_Num(line[i]))+get_Num(line[i+1]);
		i+=2;
	}

	i=i;	//ָ��У��Ͷ���ʼλ��
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
		<<"ByteCount:	"	<<dec<<this->byte_count<<endl			//���ݶδ�Сʼ��ʹ��10�������
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
