/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.1
 *Date		:2011-4-4
 *Describ	:将Hex文件格式转换位Bin文件格式程序
 ********************************************************************
 */

#include"../includes/HexData.h"

string hexfile=work_Path"/weather_station.hex";
string binfile=work_Path"/flash.bin";
string txtfile=work_Path"/flash.txt";

#define BIN_FILE_SIZE	60		//二进制文件大小，这里以KB记

char nop = 0x00;				//空指令

//是否输出到二进制文件标志
#define TO_FILE	0
//是否使用测试标志
#define TEST	1

#if TEST
	int total_byte=0;
#endif

void convert_Hex_Bin(string bin_file,string hex_file);

int main()
{
	cout<<"Version 0.4"<<endl;
	convert_Hex_Bin(binfile.c_str(),hexfile.c_str());

#if TEST
	//使用10进制显示字节数
	cout<<"total byte count is:"<<dec<<total_byte<<endl;
#endif
	return 0;
}


/***********************************************************
 *向控制台输出Hex数据
 *数据来源于Hex文件
 ************************************************************/
void convert_Hex_Bin(string bin_file,string hex_file)
{
	fstream file_Hex;
#if TO_FILE
	fstream file_Bin;
#endif

	char line[100];

	bool end_of_data=false;

	Hex *pHex;

	//打开Hex数据文件
	file_Hex.open(hex_file.c_str(),ios::in);
	if(!file_Hex)
	{
		cout<<"Open Hex File Failed!"
			<<""<<endl;
		exit(-1);
	}

#if TO_FILE
	//创建Bin二进制文件
	file_Bin.open(bin_file.c_str(),ios::out);
	if(!file_Bin)
	{
		cout<<"Create Bin File Failed"
			<<""<<endl;
		exit(-1);
	}
	/*
	 * 准备Bin二进制文件，也就是在二进制文件中写入60KB的0x00，相当与清空整个flash
	 * 但是对于单片机来说就相当与NOP指令
	for(int i=0;i<BIN_FILE_SIZE*1024;i++)
	{
		char nop=0x00;
		file_Bin.seekp(i);
		file_Bin.write(&nop,1);
	}*/

	file_Bin.seekp(BIN_FILE_SIZE*1024);
	file_Bin.write(&nop,1);
#endif

	//开始转换
	cout<<endl<<"开始转换到BIN格式，请稍等..."<<endl;
	while(!file_Hex.eof()&&!end_of_data)
	{
		file_Hex.getline(line,sizeof(line));
#if !TO_FILE
		cout<<endl<<"------->"<<line<<"<-------"<<endl;
		end_of_data=(pHex=new Hex(line))->Show();
#else
		pHex=new Hex(line);
		//这里end_of_data的判断是鉴于8位单片机的一种不合法的校验方法，参见rec_type定义
		end_of_data=pHex->rec_type;
		file_Bin.seekp(pHex->address);
		file_Bin.write((char *)pHex->pdata,pHex->byte_count);
#endif

#if TEST
		total_byte+=pHex->byte_count;
#endif
		delete pHex;
	}
	//关闭文件
	file_Hex.close();
#if TO_FILE
	file_Bin.close();
#endif
	cout<<endl<<"BIN格式转换完成！"<<endl;

/***********************************************************************/
	/*
	 *	利用BIN文件对Hex实现有序的的文本转换
	 */
#if TO_FILE
	fstream file_Txt;
	file_Txt.open(txtfile.c_str(),ios::out);
	file_Bin.open(binfile.c_str(),ios::in);
#else
	fstream file_Bin;
	file_Bin.open(binfile.c_str(),ios::in);
	//由前面可知，Bin文件的大小存在total_byte中，但是不准确，此处不用
#endif
	char byte;
	char strbyte[3];
	//定义代码去大小，可以改
	int Code_Size=BIN_FILE_SIZE*1024/10;

	//开始文件转换
	cout<<endl<<"开始转换到BIN——TXT格式，请稍等..."<<endl;
	for(int i=0;i<Code_Size;i++)
	{
		file_Bin.seekp(i);
		file_Bin.read(&byte,1);
		sprintf(strbyte,"%x",(unsigned char )byte);
		//优化显示
		if(strbyte[1]=='\0')
		{
			strbyte[1]=strbyte[0];
			strbyte[0]='0';
			strbyte[2]='\0';
		}
#if TO_FILE
		file_Txt<<_0x_<<strbyte<<" , ";
#else
		cout<<_0x_<<strbyte<<" , ";
#endif
		if((i+1)%16==0)
		{
#if	TO_FILE
			file_Txt<<endl;
#else
			cout<<endl;
#endif
		}

	}
#if TO_FILE
	file_Txt.close();
#else
	file_Bin.close();
#endif
	cout<<endl<<"BIN——TXT格式转换完成OK!"<<endl;

}
