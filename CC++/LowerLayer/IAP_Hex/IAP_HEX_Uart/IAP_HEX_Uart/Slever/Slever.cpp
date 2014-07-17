#include"../includes.h"

//从机的串口，这里用来模拟单片机
#define slever_Port L"COM3"
CSerial slever;

typedef wchar_t Address_Type,point;
typedef char Data_Type;

string flashfile=work_Path"/flash.bin";

fstream flash;
void flash_Write(	Address_Type dest,			//数据写入地址
					Data_Type * data,			//数据源
					int num);					//写入字节数
void flash_Byte_Write(	Address_Type dest,		//数据写入地址
						Data_Type data);		//写入数据
void flash_Read(	Address_Type dest,			//数据读取地址
					Address_Type src,			//数据存储地址
					int num);					//读取数据字节数
Data_Type flash_Byte_Read(Address_Type src);	//读取一个字节


/*
**串口操作相关函数
*/
/*
**从串口读入一个字符
*/
unsigned char get_Char();

void put_Char(unsigned char ch);



void test()
{
	const char tes[]={0x05,0x09};
	flash.open("flash.bin",ios::out);
	if(!flash)
	{
		cout<<"open failed!"<<endl;
		exit(-1);
	}
	flash.seekp(10);
	flash.write(tes,1);
	flash.close();
}

void down_Load();

int main()
{
	slever.Open(slever_Port);
	slever.Setup(slever.EBaud9600);

	down_Load();

	slever.Close();
	test();
	return 0;
}

void down_Load()
{
	unsigned char ch;
	while((ch=get_Char())!=S_BEGIN);
	while((ch=get_Char())!=S_OVER)
	{
		cout<<hex<<(unsigned int )ch<<"  ";
	}
}

void flash_Write(	Address_Type dest,		//数据写入地址
					Data_Type * data,		//数据源
					int bytenum)			//写入字节数
{
	for(int i=0;i<bytenum;i++)
	{
		flash_Byte_Write(dest+i,data[i]);
	}

}
void flash_Byte_Write(	Address_Type dest,	//数据写入地址
						Data_Type data)		//写入数据
{
	flash.open(flashfile.c_str(),ios::out);

	flash.seekp(dest,ios::out);
	if(!flash)
	{
		cout<<"open failed!"<<endl;
		exit(-1);
	}
	flash.seekp(dest);
	flash.write(&data,1);
	flash.close();
}
void flash_Read(	Address_Type dest,		//数据读取地址
					Address_Type src,		//数据存储地址
					int bytenum)			//读取数据字节数
{
}
Data_Type flash_Byte_Read(Address_Type src)	//读取一个字节
{
	flash.open(flashfile.c_str());

	flash.close();
	return 0x00;
}



/*
**串口操作相关函数
*/
/*
**从串口读入一个字符
*/
unsigned char get_Char()
{
	unsigned char data[2];
	slever.Read(data,1);
	return data[0];
}

void put_Char(unsigned char ch)
{
	slever.Write(&ch,1);
}