/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.h
 *Copyight	:Copyight Reserved by ty
 *Version	:0.3
 *Date		:2011-4-4
 *Describ	:ʵ�ֶ�Hex�ļ����ݵ���ȡ
 *			 ʹ��c++��ʵ���㷨����ʵ���ļ�����
 ********************************************************************
 */

#ifndef _HEXDATA_H_
#define _HEXDATA_H_

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
 * Hex������
 */

class Hex
{
public:
	Hex();
	Hex(string data);
	Hex(char *data );

	void GetDataStr(char * line);

	bool Show();
	virtual ~Hex();

//����Ӧ��ʹ��ʲô�����޶������˾���Ӧ�ø���ʵ��Ӧ�õķ��������Ҳ����˵ʹ��public�޶�
//private:
public:
	/*
	 * Hex�ļ����м�¼���ݣ��������
	 */
	unsigned int 	byte_count;		//���ݳ���
	unsigned int 	address;		//���ݵ�ַ
//	Record_Type 	rec_type;		//��������
	unsigned char 	*pdata;			//��������
	unsigned int 	chechsum;		//У���

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
	} rec_type;
};


/*********************************************************
 * ������������
 *********************************************************/
/*
 * ��һ����ĸת��Ϊһ��ʮ�����Ƶ�����
 * ����ת���������
 */
int get_Num(char ch);



#endif /* HEXDATA_H_ */
