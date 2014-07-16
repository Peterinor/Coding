/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.2
 *Date		:2011-4-2
 *Describ	:实现对Hex文件数据的提取
 *			 使用c结构实现算法并且实现文件分离
 ********************************************************************
 */

#include"../includes/HexData.h"


//hex文件路径
string hexfile=work_Path"/Hex.hex";


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

