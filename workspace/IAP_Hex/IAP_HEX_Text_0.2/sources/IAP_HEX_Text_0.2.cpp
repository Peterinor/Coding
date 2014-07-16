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

string hexfile=work_Path"/weather_station.hex";
string binfile=work_Path"/flash.bin";
string txtfile=work_Path"/flash.txt";

#define BIN_FILE_SIZE	60		//�������ļ���С��������KB��

char nop = 0x00;				//��ָ��

//�Ƿ�������������ļ���־
#define TO_FILE	0
//�Ƿ�ʹ�ò��Ա�־
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
	//ʹ��10������ʾ�ֽ���
	cout<<"total byte count is:"<<dec<<total_byte<<endl;
#endif
	return 0;
}


/***********************************************************
 *�����̨���Hex����
 *������Դ��Hex�ļ�
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
	file_Bin.open(bin_file.c_str(),ios::out);
	if(!file_Bin)
	{
		cout<<"Create Bin File Failed"
			<<""<<endl;
		exit(-1);
	}
	/*
	 * ׼��Bin�������ļ���Ҳ�����ڶ������ļ���д��60KB��0x00���൱���������flash
	 * ���Ƕ��ڵ�Ƭ����˵���൱��NOPָ��
	for(int i=0;i<BIN_FILE_SIZE*1024;i++)
	{
		char nop=0x00;
		file_Bin.seekp(i);
		file_Bin.write(&nop,1);
	}*/

	file_Bin.seekp(BIN_FILE_SIZE*1024);
	file_Bin.write(&nop,1);
#endif

	//��ʼת��
	cout<<endl<<"��ʼת����BIN��ʽ�����Ե�..."<<endl;
	while(!file_Hex.eof()&&!end_of_data)
	{
		file_Hex.getline(line,sizeof(line));
#if !TO_FILE
		cout<<endl<<"------->"<<line<<"<-------"<<endl;
		end_of_data=(pHex=new Hex(line))->Show();
#else
		pHex=new Hex(line);
		//����end_of_data���ж��Ǽ���8λ��Ƭ����һ�ֲ��Ϸ���У�鷽�����μ�rec_type����
		end_of_data=pHex->rec_type;
		file_Bin.seekp(pHex->address);
		file_Bin.write((char *)pHex->pdata,pHex->byte_count);
#endif

#if TEST
		total_byte+=pHex->byte_count;
#endif
		delete pHex;
	}
	//�ر��ļ�
	file_Hex.close();
#if TO_FILE
	file_Bin.close();
#endif
	cout<<endl<<"BIN��ʽת����ɣ�"<<endl;

/***********************************************************************/
	/*
	 *	����BIN�ļ���Hexʵ������ĵ��ı�ת��
	 */
#if TO_FILE
	fstream file_Txt;
	file_Txt.open(txtfile.c_str(),ios::out);
	file_Bin.open(binfile.c_str(),ios::in);
#else
	fstream file_Bin;
	file_Bin.open(binfile.c_str(),ios::in);
	//��ǰ���֪��Bin�ļ��Ĵ�С����total_byte�У����ǲ�׼ȷ���˴�����
#endif
	char byte;
	char strbyte[3];
	//�������ȥ��С�����Ը�
	int Code_Size=BIN_FILE_SIZE*1024/10;

	//��ʼ�ļ�ת��
	cout<<endl<<"��ʼת����BIN����TXT��ʽ�����Ե�..."<<endl;
	for(int i=0;i<Code_Size;i++)
	{
		file_Bin.seekp(i);
		file_Bin.read(&byte,1);
		sprintf(strbyte,"%x",(unsigned char )byte);
		//�Ż���ʾ
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
	cout<<endl<<"BIN����TXT��ʽת�����OK!"<<endl;

}
