/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.2
 *Date		:2011-4-2
 *Describ	:ʵ�ֶ�Hex�ļ����ݵ���ȡ
 *			 ʹ��c�ṹʵ���㷨����ʵ���ļ�����
 ********************************************************************
 */

#include"../includes/HexData.h"

/*
 *
 */
int get_Num(char ch)
{
	if(!isalnum(ch))
	{
		printf("Error Code!!\n");
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
	unsigned char k=0;
	Hex rec;
	if(line[i]!=':')
	{
		printf("Error Code!!\n");
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
	rec.rec_type=/*16*get_Num(line[i])+*/get_Num(line[i+1]);	//��Ϊ���Ͷβ����ܴ���5���ʡ�����

	i+=2;	//ָ�����ݶ���ʼλ��
	rec.pdata=(unsigned char *) (malloc(rec.byte_count));;
	for(k=0;k<rec.byte_count;k++)
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
_Bool show_Hex(Hex rec)
{
	unsigned int i=0;
	printf("Information of Rec:\n");
#if HP_TYPE
	printf("DataType :	"_0x_"%d\n",rec.rec_type);
#endif
#if HP_ADD
	printf("Address  :	"_0x_"%x\n",rec.address);
#endif
#if HP_COUNT
	printf("ByteCount:	%d\n",rec.byte_count);		//���ݶδ�Сʼ��ʹ��10�������
#endif
#if HP_CHSUM
	printf("CheckSum :	"_0x_"%x",rec.chechsum);
#endif
#if	HP_DATA
	printf("Data     :	\n---->");
	for(i=0;i<rec.byte_count;i++)
	{
		printf("  "_0x_"%x.  ",rec.pdata[i]);
	}
#endif
	printf("\n");
	if(rec.rec_type==H_EOF)
		return 1;
	return 0;
}

