#include"../includes.h"

extern string hexfile;

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
