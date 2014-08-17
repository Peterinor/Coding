#include"HexData.h"


//hex�ļ�·��
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
