#ifndef _DEFINE_H_
#define _DEFINE_H_
//���ļ����ڶ���ͬ��Ĳ����궨���Լ�һЩͬ��ĳ����ȣ���Ҫ���ڿ���̨Ӧ�ó���ʹ�ã�

//�����˻�����
#define VIPACCOUNT		1
#define COMMOMACCOUNT	0


//�����������
#define EXIT			0	//�˳�
#define BACK			0	//����

#define DEPOSITE		1	//���
#define DRAWMONEY		2	//ȡ��
#define	GETBALANCE		3	//��ѯ���
#define	CHECKRECORD		4	//�鿴������¼
#define DISPLAY			5	//��ʾ�˻�ȫ����Ϣ
#define	MODIFYINF		6	//�޸��˻���Ϣ
#define CHECKAUTHORITY  7	//�鿴�˻�Ȩ��Authority
#define SETAUTHORITY	8	//�趨�˻�Ȩ��


#define NEWACCOUNT		10	//�������˻�
#define	OPERATEACCOUNT	20	//�����˻�
#define SHOWALLACCOUNT	30	//��ʾ�����û�
#define	DELETEACCOUNT	40	//����
#define CHANGERATE		50	//����������

struct AccountStruct
{
	char Name[20];
	char IDNumber[10];
	int AccountType;
	double Balance;
	double OverDraw;
	void Show();
};



/*
#include"AccountManage.h"
#include"VipAccount.h"
#include"LogRecord.h"
#include"DateTime.h"
#include"Account.h"
#include"Bank.h"
#include"Bank.h"

#include<vector>
#include<iostream>
#include<string>

using namespace std;
*/

char * itoa ( int value, char * str, int base=10);






#endif

#include"Exception.h"
