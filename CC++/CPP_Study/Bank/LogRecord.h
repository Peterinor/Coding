//#pragma once
#ifndef _LOGRECORD_H_
#define _LOGRECORD_H_

#include"define.h"

#include"DateTime.h"

class LogRecord
{
public:
	//��ȡ��¼�е�ʱ��
	DateTime GetDateTime();
	//��ȡ��¼�еĲ�������
	int GetOperation();
	//��ȡ������¼�е������Ϣ
	double GetBalance();

	//�ڿ���̨����ʾRecord������
	void ShowRecord();
	
	//����¼���͵ı��ת��Ϊ��Ӧ���ַ������
	string ToString();
	//���ؼ�¼���ַ������
	string GetString();

	//���ַ���ת��ΪRecord��������ɣ�
	void ToRecord(char *recordStr);

	//�����������������������˻������������
	friend ostream  &operator<<(LogRecord &logRecord,ostream &os);
	friend fstream &operator<<(LogRecord &logRecord,fstream &fs);
	friend fstream &operator>>(LogRecord &logRecord,fstream &fs);

	friend bool operator==(LogRecord &log1,LogRecord &log2);
	
	//���������ʹ�intת��Ϊ�ַ���
	string OperationStr(int operation);
	//���������ʹ��ַ���ת��Ϊint
	int Operation(string &operationStr);
	
	LogRecord(void);
	LogRecord(DateTime dt,int operation,double exMoney,double balance);
	~LogRecord(void);

private:
	DateTime m_Time;
	int m_Operation;
	double ExchangeMoney;	//������������ȡ��Ķ��
	double m_Balance;		//�����Ϣ����ΪAccount��m_Balance
	string m_RecordStr;
	string m_OperationStr;

};

#endif