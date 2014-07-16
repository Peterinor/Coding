/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.1
 *Version	:0.1
 *Date		:2011-4-1
 *Describ	:ʵ�ֶ�Hex�ļ����ݵ���ȡ
 *			 ʹ��c�ṹʵ���㷨����δʵ���ļ�����
 ********************************************************************
 */

#include"../../includes.h"


//����Hex�ļ�������ʼ�ַ�
#define Start_Code	':'

//����ʮ�����Ƶ����������ʽ
#define Hex_Print 1

#if 	Hex_Print
#define	_hex_	hex
#define _0x_		"0x"
#else
#define	_hex_	""
#define _0x_ 	""
#endif


//�����ӡ��־
#define HP_ADD		1
#define HP_DATA		1
#define HP_COUNT	1
#define HP_TYPE		0
#define HP_CHSUM	0


/*
 * Hex�м�¼�������ͱ�־��������
 */
enum Record_Type		//��¼����
{
	H_ERR=-1,			//�����¼�����ݳ������Ҫ��Ϊ��ӵ�һ��У������
	H_DATA,				//���ݼ�¼			(0x00)---->8��16��32λ��
	H_EOF,				//�ļ�������¼		(0x01)---->8��16��32λ��
	//�����������8λ�����в����õ������������Խ������
	H_ESAR,				//��չ�洢�ε�ַ��¼	(0x02)---->16��32λ��
	H_SSAR,				//��ʼ�ε�ַ��¼		(0x03)---->16��32λ��
	H_ELAR,				//��չ���Ե�ַ��¼		(0x04)---->32λר��
	H_SLAR				//��ʼ���Ե�ַ��¼		(0x04)---->32λר��
};

/*
 * Hex�ļ����м�¼���ݽṹ���������
 */
typedef struct hex_Rec
{
	unsigned int 	byte_count;		//���ݳ���
	unsigned int 	address;		//���ݵ�ַ
	Record_Type 	rec_type;		//��������
	unsigned char 	*pdata;			//��������
	unsigned int 	chechsum;		//У���

}Hex,*pHex;


/*
 * ��ӡhex���ݣ����ҷ������ݼ�¼�Ƿ��ѵ�����β��
 * ��������β���򷵻�true�����򷵻�false
 */
bool show_Hex(Hex rec);


#define char_to_int_gap	48	//0x30

//hex�ļ�·��
string hexfile="/home/tylwj/file/Hex.hex";

string hex_file="http://tangyutianbulao.gicp.net/IAP_hex/Hex.hex";


/*
 * ���ַ���line�л�ȡhex����
 * �����lineҲ����hex�ļ��е�һ���ַ�
 */
Hex get_Data_Str(const char * line);

/*
 * ��ӡhexfile
 * ���hex_fileΪ�ļ�����hex�ļ����޷�������
 */
void print_Hex(string hex_file);

/*
 * ��һ����ĸת��Ϊһ��ʮ�����Ƶ�����
 * ����ת���������
 */
int get_Num(char ch);

/*
 * ���Ժ���������
 */
void test();

/*
 * �����򣬴�ӡhex�ļ�����
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
	i+=1;	//ָ���ֽ�����ʼλ��
	rec.byte_count=16*(get_Num(line[i]))+get_Num(line[i+1]);

	i+=2;	//ָ���ַ����ʼλ��
	rec.address=16*16*16*get_Num(line[i])
					+16*16*get_Num(line[i+1])
					+16*get_Num(line[i+2])+get_Num(line[i+3]);

	i+=4;	//ָ�����ݼ�¼���Ͷ���ʼλ��
	rec.rec_type=/*16*get_Num(line[i])+*/(Record_Type)get_Num(line[i+1]);	//��Ϊ���Ͷβ����ܴ���5���ʡ�����

	i+=2;	//ָ�����ݶ���ʼλ��
	rec.pdata=new unsigned char[rec.byte_count];
	for(unsigned int k=0;k<rec.byte_count;k++)
	{
		rec.pdata[k]=16*(get_Num(line[i]))+get_Num(line[i+1]);
		i+=2;
	}

	i=i;	//ָ��У��Ͷ���ʼλ��
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
		<<"ByteCount:	"	<<dec<<rec.byte_count<<endl			//���ݶδ�Сʼ��ʹ��10�������
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

