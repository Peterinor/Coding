//#pragma once
#ifndef _BANK_H_
#define _BANK_H_
#include"define.h"

#include"AccountManage.h"

using namespace std;

class Bank
{
public:

	//���г���ĺ����������п�ʼ�ϰ��ˣ�ʵ����manage������֮,���������п�ʼ�ϰࡱ,��������������򼸺����еĴ��룡
	void Run();

	//"�����°�"
	void Exit();

	//�����˻���Ϣ
	void LoadAccount();

	//ж���˻���Ϣ
	void UnLoadAccount();

	//д���˻���Ϣ
	bool WriteAccount();

	//Ĭ�Ϲ��캯�����˻��ļ���Ϊaccount.dat
	Bank(void);
	//���ι��캯�����˻��ļ���ΪfileName
	Bank(const char *fileName);
	Bank(string filename);
	~Bank(void);
private:
	//���г�ʼ��
	void Init();
	//����LOGO
	void Logo();

private:
	AccountManage m_Manage;
	//���ܻ��������Ĺ���Ա���˴�����Ҫ��

	string m_AccountFileName;

	fstream m_AccountFile;

	int TotalAccountNumber;

};

#endif
