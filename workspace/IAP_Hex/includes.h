/*
 ********************************************************************
 *Author	:ty
 *File		:includes.h
 *Copyight	:Copyight Reserved by ty
 *Version	:0.1
 *Date		:2011-4-2
 *Describ	:����Ĺ�������ͷ�ļ�
 ********************************************************************
 */

#ifndef _INCLUDE_H_
#define _INCLUDE_H_

//Linuxϵͳͷ�ļ�����
#include <unistd.h> /*linux��׼��������*/
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> /*�ļ����ƶ���*/
#include <termios.h> /*POSIX�ն˿��ƶ���*/
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

//��׼��C����ͷ�ļ�����
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>

#include <cctype>

#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


#define work_Path "/home/tylwj/file"

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
