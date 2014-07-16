/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.1
 *Date		:2011-4-4
 *Describ	:��Hex�ļ���ʽת��λBin�ļ���ʽ����
 ********************************************************************
 */

#include"../includes/HexData.h"

string hexfile=work_Path"/Hex.hex";
string binfile=work_Path"/flash.txt";

#define BIN_FILE_SIZE	60		//�������ļ���С��������KB��

char nop = 0x00;				//��ָ��

//�Ƿ�������������ļ���־
#define TO_FILE	1
//�Ƿ�ʹ�ò��Ա�־
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
	//ʹ��10������ʾ�ֽ���
	cout<<"total byte count is:"<<dec<<total_byte<<endl;
#endif
	return 0;
}


/***********************************************************
 *�����̨���Hex����
 *������Դ��Hex�ļ�
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

	//��Hex�����ļ�
	file_Hex.open(hex_file.c_str(),ios::in);
	if(!file_Hex)
	{
		cout<<"Open Hex File Failed!"
			<<""<<endl;
		exit(-1);
	}

#if TO_FILE
	//����Bin�������ļ�
	file_Text.open(text_file.c_str(),ios::out);
	if(!file_Text)
	{
		cout<<"Create Bin File Failed"
			<<""<<endl;
		exit(-1);
	}
#endif

	//��ʼת��
	while(!file_Hex.eof()&&!end_of_data)
	{
		file_Hex.getline(line,sizeof(line));
#if !TO_FILE
		cout<<endl<<"------->"<<line<<"<-------"<<endl;
		end_of_data=(pHex=new Hex(line))->Show();
#else
		pHex=new Hex(line);
		//pHex->Show();
		//����end_of_data���ж��Ǽ���8λ��Ƭ����һ�ֲ��Ϸ���У�鷽�����μ�rec_type����
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

	//�ر��ļ�
	file_Hex.close();
#if TO_FILE
	file_Text.clear();
#endif
}
