#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include<iostream>
#include<string>
#include<fstream>

#include<cstring>

#include<cctype>

#include<cstdlib>


using namespace std;


#include"CSerial/Serial.h"

#pragma comment(lib,"../Release/CSerial.lib")

#undef _UNICODE

#define work_Path "D:/bark_up/php/www.tangyu.com/IAP_Hex"

//���崫���־��Ϣ
enum S_Mark
{	
	S_BEGIN		=	0xff,		//�������ݴ��������־	
	S_END		=	0xfe,		//�������ݼ�¼���ͽ�����־
	S_DATA_OK	=	0xfd,		//�������������ȷ����ȷ�ϱ�־
	S_OVER		=	0xff,		//�������ݷ�����ϱ�־
	S_ANS		=	0xfb		//�ӻ�Ӧ���־
	//S_ADD		=	-4,			//�������͵�ַ���ݱ�־
	//S_BYTE	=	-5,			//���������ֽ�����־
	//S_DATA	=	-6,			//�����������ݱ�־
	//S_GET		=	-8,			//�ӻ��յ����ݺ�Ӧ��
	
};

/*
**ͨ��Э��(1)��
**Hex��¼�������־S_BEGIN(-1)��������ͣ�ķ���S_BEGIN���������ݣ�
**ֱ���ӻ�Ӧ��S_ANS(-5)��������ʼ���͵�ַ���ݱ�־S_ADD���ӻ��յ���
**ͬ��Ӧ��S_ANS��Ȼ��������ʼ�������ֽڵ�ַ����
*/


/*
**ͨ��Э��(2)��
**Hex��¼�������־S_BEGIN(-1)��������ͣ�ķ���S_BEGIN���������ݣ�
**ֱ���ӻ�Ӧ��S_ANS(-5)��������ʼ�������ݼ�¼������Ϊ-��ַ-��-����
**�ֽ���-��-����-���ӻ�ÿ�յ�һ���ֽ����ݺ󷵻�һ��Ӧ���ź�A_ANS��
**����������һ��Hex��¼����S_END��־���ӻ�����ȴ�״̬���ȴ�����
**������Ϣ��Ҳ�����Ƿ������ݶ�ʧ�����������ݽ��յ��Ĵӻ�Ӧ�����ȷ��
**�Ƿ������ݶ�ʧ���Ƿ���Ҫ�ط����ݼ�¼����û�����ݶ�ʧ�������������
**S_DATA_OK���ӻ���ʼд�����
*/

#endif