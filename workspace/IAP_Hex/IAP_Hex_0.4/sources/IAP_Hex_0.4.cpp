/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.1
 *Date		:2011-4-4
 *Describ	:对Hex类的测试程序
 ********************************************************************
 */

#include"../includes/HexData.h"

string hexfile=work_Path"/Hex.hex";

void print_Hex(string hex_file);


int main()
{
	cout<<"Version 0.4"<<endl;
	print_Hex(hexfile.c_str());

	return 0;
}


/***********************************************************
 *向控制台输出Hex数据
 *数据来源于Hex文件
 ************************************************************/
void print_Hex(string hex_file)
{
	fstream file;
	char line[100];

	bool end_of_data=false;

	Hex *pHex;

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
		end_of_data=(pHex=new Hex(line))->Show();
		delete pHex;
	}
	file.close();
}
