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

string hexfile=work_Path"/Hex.hex";
string binfile=work_Path"/flash.txt";

#define BIN_FILE_SIZE	60		//二进制文件大小，这里以KB记

char nop = 0x00;				//空指令

//是否输出到二进制文件标志
#define TO_FILE	1
//是否使用测试标志
#define TEST	1

#if TEST
	int total_byte=0;
#endif

void convert_Hex_Text(string text_file,string hex_file);

int main()
{
	cout<<"Version 0.4"<<endl;
	convert_Hex_Text(binfile.c_str(),hexfile.c_str());

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
void convert_Hex_Text(string text_file,string hex_file)
{
	fstream file_Hex;
#if TO_FILE
	fstream file_Text;
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
	file_Text.open(text_file.c_str(),ios::out);
	if(!file_Text)
	{
		cout<<"Create Bin File Failed"
			<<""<<endl;
		exit(-1);
	}
#endif

	//开始转换
	while(!file_Hex.eof()&&!end_of_data)
	{
		file_Hex.getline(line,sizeof(line));
#if !TO_FILE
		cout<<endl<<"------->"<<line<<"<-------"<<endl;
		end_of_data=(pHex=new Hex(line))->Show();
#else
		pHex=new Hex(line);
		//pHex->Show();
		//这里end_of_data的判断是鉴于8位单片机的一种不合法的校验方法，参见rec_type定义
		end_of_data=pHex->rec_type;
		char buf[3];
		for(unsigned int i=0;i<pHex->byte_count;i++)
		{
			sprintf(buf,"%x",pHex->pdata[i]);
			if(buf[1]=='\0')
			{
				buf[1]=buf[0];
				buf[0]='0';
				buf[2]='\0';
			}
			file_Text<<_0x_<<_hex_<<buf<<" , ";
		}
		file_Text<<endl;
#endif

#if TEST
		total_byte+=pHex->byte_count;
#endif
		delete pHex;
	}

	//关闭文件
	file_Hex.close();
#if TO_FILE
	file_Text.clear();
#endif
}
