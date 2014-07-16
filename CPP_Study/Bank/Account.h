//#pragma once
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include"define.h"

#include<iostream>
#include<fstream>
#include"LogManage.h"

//using namespace std;

class Account
{
public:
	//���캯��
	Account();
	Account(const char *name,long IDNumber,double balance=0,int accountType=0,double overdraw=0.0);
	Account(const Account &Account);

	~Account();
	

	//��ʼ����¼�ļ���
	void InitLogFileName();
	//�޸������ʺ���
	static double ModifyInterestRate(double );

	static double GetInterestRate();

	//����
	bool Deposit(double saveMoney);
	//ȡ���
	virtual bool DrawMoney(double drawMoney);

	//��ѯ������¼
	void CheckRecord();

	//�޸��˻���Ϣ
	void ModifyInf();
	
	//�鿴�˻�Ȩ��
	void CheckAuthority();
	//�����˻���Ȩ��
	void SetAuthority();

	//�����˻���Ϣ����ʾ�����û���Ϣ,һ�㲻�ṩID_Number���趨��ͨ����ϵͳ�ṩ��
	void SetAccountInf();		
	//���ݲ����趨�û���Ϣ
	void SetAccountInf(	char *name ,
						long ID_number,
						int accountType=0,
						double balance=0);

	void SetAccountInf(	char *name ,
						long ID_number,
						int accountType=0,
						double balance=0.0,
						double overdraw=0.0
						);					


	//�ܶ������ID_Number�ǲ����Ըı�ģ��ʶ��ֳ�������һ�����������ݲ����趨�û���Ϣ
	void SetAccountInf(	char *name ,						
						int accountType=0,
						double balance=0
						);

	//�趨ID�˺�
	void SetIDNumber(long num);

	//����������
	double CalculateMonthlyInterest() const;

	//��ȡ�˻���Ϣ
	char	*GetName(char name[20])const;
	long	GetIDNumber() const;
	double	GetBalance() const;
	int GetAccountType() const;
	double GetOverDraw() const;

	//���ؼ�¼�������
	LogManage &GetLogManage();
	
	//���ؼ�¼�ļ���
	string GetLogFileName();
		
	//��ȡ������
	static double GetAnnualInterestRate();

	//��ʾ�˻���Ϣ
	void Display()const;

	//���رȽ�����������ڲ�ѯ������ʹ��
	friend bool operator==(Account &account1,Account &account2);
	friend bool operator!=(Account &account1,Account &account2);

	friend bool operator<(Account &account1,Account &account2);
	friend bool operator>(Account &account1,Account &account2);

	friend Account operator+(Account &account,double saveMoney);
	friend Account operator-(Account &account,double saveMoney);

	//�����������������������˻������������
	friend ostream &operator<<(ostream &os,Account &account);
	friend fstream &operator<<(fstream &fs,Account &account);
	friend fstream &operator>>(fstream &fs,Account &account);

private:
	char m_Name[20];
	long m_IDNumber;
	double m_Balance;
	int m_AccountType;
	double m_OverDraw;

	string m_LogRecordFileName;

	LogManage m_LogManage;

	//fstream m_LogRecordFile;	

	static double m_AnnualInterestRate;

	
};

#endif
