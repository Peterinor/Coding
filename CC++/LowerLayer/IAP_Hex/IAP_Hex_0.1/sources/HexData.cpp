/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.1
 *Version	:0.1
 *Date		:2011-4-1
 *Describ	:实现对Hex文件数据的提取
 *			 使用c结构实现算法并且未实现文件分离
 ********************************************************************
 */

#include"../../includes.h"


//定义Hex文件的行起始字符
#define Start_Code	':'

//设置十六进制的数据输出格式
#define Hex_Print 1

#if 	Hex_Print
#define	_hex_	hex
#define _0x_		"0x"
#else
#define	_hex_	""
#define _0x_ 	""
#endif


//定义打印标志
#define HP_ADD		1
#define HP_DATA		1
#define HP_COUNT	1
#define HP_TYPE		0
#define HP_CHSUM	0


/*
 * Hex行记录数据类型标志常量定义
 */
enum Record_Type		//记录类型
{
	H_ERR=-1,			//错误记录，根据程序的需要认为添加的一个校验数据
	H_DATA,				//数据记录			(0x00)---->8、16、32位用
	H_EOF,				//文件结束记录		(0x01)---->8、16、32位用
	//下面的数据在8位机器中不会用到，考虑完整性将其加上
	H_ESAR,				//扩展存储段地址记录	(0x02)---->16、32位用
	H_SSAR,				//起始段地址记录		(0x03)---->16、32位用
	H_ELAR,				//扩展线性地址记录		(0x04)---->32位专用
	H_SLAR				//起始线性地址记录		(0x04)---->32位专用
};

/*
 * Hex文件的行记录数据结构，编译操作
 */
typedef struct hex_Rec
{
	unsigned int 	byte_count;		//数据长度
	unsigned int 	address;		//数据地址
	Record_Type 	rec_type;		//数据类型
	unsigned char 	*pdata;			//数据数组
	unsigned int 	chechsum;		//校验和

}Hex,*pHex;


/*
 * 打印hex数据，并且返回数据记录是否已到数据尾部
 * 若到数据尾部则返回true，否则返回false
 */
bool show_Hex(Hex rec);


#define char_to_int_gap	48	//0x30

//hex文件路径
string hexfile="/home/tylwj/file/Hex.hex";

string hex_file="http://tangyutianbulao.gicp.net/IAP_hex/Hex.hex";


/*
 * 从字符串line中获取hex数据
 * 这里的line也就是hex文件中的一行字符
 */
Hex get_Data_Str(const char * line);

/*
 * 打印hexfile
 * 输出hex_file为文件名的hex文件，无返回类型
 */
void print_Hex(string hex_file);

/*
 * 将一个字母转换为一个十六进制的数字
 * 返回转换后的数字
 */
int get_Num(char ch);

/*
 * 测试函数，不用
 */
void test();

/*
 * 主程序，打印hex文件内容
 */
int main()
{
	cout<<"Version 0.1"<<endl;
	print_Hex(hexfile.c_str());

	return 0;
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

/*
 *
 */
Hex get_Data_Str(const char * line)
{
	int i=0;
	Hex rec;
	if(line[i]!=':')
	{
		cout<<"error code!"<<endl;
		rec.rec_type=H_ERR;
		return rec;
	}
	i+=1;	//指向字节数起始位置
	rec.byte_count=16*(get_Num(line[i]))+get_Num(line[i+1]);

	i+=2;	//指向地址段起始位置
	rec.address=16*16*16*get_Num(line[i])
					+16*16*get_Num(line[i+1])
					+16*get_Num(line[i+2])+get_Num(line[i+3]);

	i+=4;	//指向数据记录类型段起始位置
	rec.rec_type=/*16*get_Num(line[i])+*/(Record_Type)get_Num(line[i+1]);	//因为类型段不可能大于5，故。。。

	i+=2;	//指向数据段起始位置
	rec.pdata=new unsigned char[rec.byte_count];
	for(unsigned int k=0;k<rec.byte_count;k++)
	{
		rec.pdata[k]=16*(get_Num(line[i]))+get_Num(line[i+1]);
		i+=2;
	}

	i=i;	//指向校验和段起始位置
	rec.chechsum=16*(get_Num(line[i]))+get_Num(line[i+1]);

	return rec;
}


/*
 *
 */
void print_Hex(string hex_file)
{
	fstream file;
	char line[100];

	bool end_of_data=false;

	file.open(hex_file.c_str(),ios::in);
	if(!file)
	{
		cout<<"open failed!"<<endl;
		exit(-1);
	}
	while(!file.eof()&&!end_of_data)
	{
		file.getline(line,sizeof(line));
		cout<<endl<<"------->"<<line<<"<-------"<<endl;
		end_of_data=show_Hex(get_Data_Str(line));
	}
	file.close();
}

/*
 *
 */
bool show_Hex(Hex rec)
{
	cout<<"Information of Rec:"<<endl;
	cout<<_hex_
#if HP_TYPE
		<<_hex_
		<<"DataType :	"	<<_0x_<<rec.rec_type	<<endl
#endif
#if HP_ADD
		<<_hex_
		<<"Address  :	"	<<_0x_<<rec.address	<<endl
#endif
#if HP_COUNT
		<<_hex_
		<<"ByteCount:	"	<<dec<<rec.byte_count<<endl			//数据段大小始终使用10进制输出
#endif
#if HP_CHSUM
		<<_hex_
		<<"CheckSum :	"	<<_0x_<<rec.chechsum	<<endl
#endif
		<<"";
#if	HP_DATA
	cout<<"Data     :	"	<<endl<<"---->";
	for(unsigned int i=0;i<rec.byte_count;i++)
	{
		cout<<_hex_<<_0x_<<(unsigned int)rec.pdata[i]<<"  .  ";
		//printf("  0x%x.  ",rec.pdata[i]);
	}
#endif
	cout<<endl;
	if(rec.rec_type==H_EOF)
		return true;
	return false;
}



string hex_str=":10002E00E0FE1200B5907F13E04402F0AF10EF3304";
/*
 *
 */
void test()
{
	Record_Type a=H_ERR;
	cout<<a<<endl;
	cout<<get_Num('9')<<endl;
	a=(Record_Type)4;
	cout<<a<<endl;
	cout<<hex_str<<endl;
	show_Hex(get_Data_Str(hex_str.c_str()));
}

