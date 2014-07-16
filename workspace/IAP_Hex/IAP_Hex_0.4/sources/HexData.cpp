/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.4
 *Date		:2011-4-4
 *Describ	:实现对Hex文件数据的提取
 *			 使用c++类实现算法并且实现文件分离
 *			 对get_Num()函数进行来重写
 *			 并且增加的很多的注释
 *			 同时对函数的参数，返回值已经函数类型做了更加严格的限定
 ********************************************************************
 */

#include "../includes/HexData.h"

/******************************************************************
 * 构造函数区
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
 * 析构函数
 *******************************************************************/
Hex::~Hex()
{
	if(NULL!=this->pdata)
		delete this->pdata;
}


/**********************************************************************
 * 获取数据函数
 * 该函数从字符串line中获取Hex行的数据信息
 * 取出的数据放在this->数据中
 */
void Hex::GetDataStr(const char * line)
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


	//分配数据空间
	this->pdata=new unsigned char[this->byte_count];

	i+=2;	//指向数据段起始位置
	for(unsigned int k=0;k<this->byte_count;k++)
	{
		//从字符串中取出数据并赋给pdata数组
		this->pdata[k]=16*(get_Num(line[i]))+get_Num(line[i+1]);
		i+=2;
	}

	i=i;	//指向校验和段起始位置
	this->chechsum=16*(get_Num(line[i]))+get_Num(line[i+1]);
}

/*********************************************************************
 * 显示Hex结构信息函数，当到达文件尾部是输出End Of Code！
 * 若程序对去Hex记录一道尾部则Show返回true，否则返回false
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
		<<"ByteCount:	"	<<dec<<this->byte_count<<endl			//数据段大小始终使用10进制输出，直观
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
 * 将一个字符转换位16进制数字
 * 返回ch所表示的数字10进制
 *********************************************************************************/
int get_Num(char ch)
{
	//判断是为16进制字符
	if(!isxdigit(ch))		//防止出现像g h之类的数据，跟加安全和准确
	{
		cout<<"Error Code!!"<<endl;
		return -1;
	}
	//为大写字符
	if(isupper(ch))
	{
		return ch-'A'+10;
	}
	//小写字符
	else if(islower(ch))
	{
		return ch-'a'+10;
	}
	//数字
	else
	{
		return ch-'0';
	}
}
