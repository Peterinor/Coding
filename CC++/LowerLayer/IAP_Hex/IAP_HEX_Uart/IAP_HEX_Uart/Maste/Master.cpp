#include"../includes.h"
#include"HexData.h"

#define _TEST	0

//主机串口，这里作为下载器
#define master_Port L"COM2"
CSerial master;

fstream hex_file;

void send_Hex(string hexfile);
void send_Data(unsigned char * pdata,int num);
void send_Byte(unsigned char byte);

unsigned char get_Char();
void put_Char(unsigned char ch);

int main(void)
{
	master.Open(master_Port);
	master.Setup(master.EBaud9600);			//9600波特率

	send_Hex(hexfile);

	//用于检验机器是小端模式还是大端模式，此处结果为小段模式
	/*int a=0xfe5f;
	unsigned char* pa=(unsigned char *)&a;
	cout<<hex<<(unsigned int )pa[1]<<"--"<<(unsigned int )pa[0];*/

	master.Close();
	return 0;
}


void send_Hex(string hex_File_Name)
{
	fstream hex_File;
	char line[100];
	Hex rec;

	unsigned char mark=S_BEGIN;

	bool end_of_data=false;

	hex_File.open(hex_File_Name.c_str(),ios::in);
	if(!hex_File)
	{
		cout<<"open failed!"<<endl;
		exit(-1);
	}

	mark=S_BEGIN;
	send_Data(&mark,1);
	//mark=S_END;
	while(!hex_File.eof()&&!end_of_data)
	{
		hex_File.getline(line,sizeof(line));
//#if _TEST
//		cout<<endl<<"------->"<<line<<"<-------"<<endl;
//		end_of_data=show_Hex(get_Data_Str(line));
//#else
		end_of_data=((rec=get_Data_Str(line)).rec_type==H_EOF);
		//发送开始标志
		//从机没有应答则一直请求，直到从机应答
		//mark=S_BEGIN;
		//send_Data(&mark,1);
		//mark=S_END;
		//do{
		//	send_Data(&mark,1);
		//}
		//while(S_ANS!=get_Char());		
		
		//从机应答，开始发送数据
		//发送地址数据
		unsigned char * padd=(unsigned char *)&rec.address;
		//---->PC机为小端模式，故此处不适合同时发送两个字节，应先发送高位数据地址，在发送低位
		//send_Data((unsigned char*)&rec.address,2);	//由低到高发送
		send_Byte(padd[1]);
		send_Byte(padd[0]);
		
		//发送字节数数据
		send_Byte((unsigned char )rec.byte_count);
		
		//发送记录数据
		send_Data(rec.pdata,rec.byte_count);
		
		//接收发送校验，由从机发送接收数据总数
		//get_Char();	
		//::Sleep(50);
//#endif
#if _TEST
		cout<<end_of_data<<endl;
#endif
	}
	//发送数据完毕
	mark=S_OVER;
	send_Data(&mark,1);

	hex_File.close();
}

void send_Data(unsigned char * pdata,int num)
{
#if _TEST
	cout<<"--->";
#endif
	for(int i=0;i<num;i++)
	{
		send_Byte(pdata[i]);
		//::Sleep(50);
	}
#if _TEST
	cout<<endl;
#endif
}

void send_Byte(unsigned char byte)
{
#if _TEST
	cout<<_hex_<<_0x_<<(unsigned int)byte<<"  .  ";
#else
	master.Write(&byte,1);
#endif
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
	master.Read(data,1);
	return data[0];
}

void put_Char(unsigned char ch)
{
	master.Write(&ch,1);
}