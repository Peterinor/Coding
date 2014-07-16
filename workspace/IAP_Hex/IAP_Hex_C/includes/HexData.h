/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.h
 *Copyight	:Copyight Reserved by ty
 *Version	:0.2
 *Date		:2011-4-2
 *Describ	:ʵ�ֶ�Hex�ļ����ݵ���ȡ
 *			 ��ʵ��Hex������ȡ��Ҫ�����������
 ********************************************************************
 */

#include"includes.h"

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
#define HP_TYPE		1
#define HP_CHSUM	0




/*
 * Hex�ļ����м�¼���ݽṹ���������
 */
typedef struct hex_Rec
{
	unsigned int 	byte_count;		//���ݳ���
	unsigned int 	address;		//���ݵ�ַ
	//Hex�м�¼�������ͱ�־��������
	enum Record_Type		//��¼����
	{
		H_ERR=-1,			//�����¼�����ݳ������Ҫ��Ϊ��ӵ�һ��У������
		H_DATA=0,				//���ݼ�¼			(0x00)---->8��16��32λ��
		H_EOF=1,				//�ļ�������¼		(0x01)---->8��16��32λ��
	}	rec_type;			//��������
	unsigned char 	*pdata;			//��������
	unsigned int 	chechsum;		//У���

}Hex,*pHex;


/*
 * ��ӡhex���ݣ����ҷ������ݼ�¼�Ƿ��ѵ�����β��
 * ��������β���򷵻�true�����򷵻�false
 */
_Bool show_Hex(Hex rec);

#define char_to_int_gap	48	//0x30

/*
 * ���ַ���line�л�ȡhex����
 * �����lineҲ����hex�ļ��е�һ���ַ�
 */
Hex get_Data_Str(const char * line);

/*
 * ��ӡhexfile
 * ���hex_fileΪ�ļ�����hex�ļ����޷�������
 */
void print_Hex(char* hex_file);

/*
 * ��һ����ĸת��Ϊһ��ʮ�����Ƶ�����
 * ����ת���������
 */
int get_Num(char ch);

/*
 * ���Ժ���������
 */
void test();
