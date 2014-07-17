/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.4
 *Date		:2011-4-4
 *Describ	:ʵ�ֶ�Hex�ļ����ݵ���ȡ
 *			 ʹ��c++��ʵ���㷨����ʵ���ļ�����
 *			 ��get_Num()������������д
 *			 �������ӵĺܶ��ע��
 *			 ͬʱ�Ժ����Ĳ���������ֵ�Ѿ������������˸����ϸ���޶�
 ********************************************************************
 */

#include "../includes/HexData.h"

/******************************************************************
 * ���캯����
******************************************************************/
Hex::Hex()
{
	this->GetDataStr(":00000001FF");

}

Hex::Hex(const string data)
{
	this->GetDataStr(data.c_str());
}

Hex::Hex(const char * data)
{
	this->GetDataStr(data);
}

/*******************************************************************
 * ��������
 *******************************************************************/
Hex::~Hex()
{
	if(NULL!=this->pdata)
		delete this->pdata;
}


/**********************************************************************
 * ��ȡ���ݺ���
 * �ú������ַ���line�л�ȡHex�е�������Ϣ
 * ȡ�������ݷ���this->������
 */
void Hex::GetDataStr(const char * line)
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


	//�������ݿռ�
	this->pdata=new unsigned char[this->byte_count];

	i+=2;	//ָ�����ݶ���ʼλ��
	for(unsigned int k=0;k<this->byte_count;k++)
	{
		//���ַ�����ȡ�����ݲ�����pdata����
		this->pdata[k]=16*(get_Num(line[i]))+get_Num(line[i+1]);
		i+=2;
	}

	i=i;	//ָ��У��Ͷ���ʼλ��
	this->chechsum=16*(get_Num(line[i]))+get_Num(line[i+1]);
}

/*********************************************************************
 * ��ʾHex�ṹ��Ϣ�������������ļ�β�������End Of Code��
 * �������ȥHex��¼һ��β����Show����true�����򷵻�false
 *********************************************************************/
bool Hex::Show() const
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
		<<"ByteCount:	"	<<dec<<this->byte_count<<endl			//���ݶδ�Сʼ��ʹ��10���������ֱ��
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


/**********************************************************************************
 * ��һ���ַ�ת��λ16��������
 * ����ch����ʾ������10����
 *********************************************************************************/
int get_Num(char ch)
{
	//�ж���Ϊ16�����ַ�
	if(!isxdigit(ch))		//��ֹ������g h֮������ݣ����Ӱ�ȫ��׼ȷ
	{
		cout<<"Error Code!!"<<endl;
		return -1;
	}
	//Ϊ��д�ַ�
	if(isupper(ch))
	{
		return ch-'A'+10;
	}
	//Сд�ַ�
	else if(islower(ch))
	{
		return ch-'a'+10;
	}
	//����
	else
	{
		return ch-'0';
	}
}
