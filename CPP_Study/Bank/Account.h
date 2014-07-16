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
	//构造函数
	Account();
	Account(const char *name,long IDNumber,double balance=0,int accountType=0,double overdraw=0.0);
	Account(const Account &Account);

	~Account();
	

	//初始化记录文件名
	void InitLogFileName();
	//修改年利率函数
	static double ModifyInterestRate(double );

	static double GetInterestRate();

	//存款函数
	bool Deposit(double saveMoney);
	//取款函数
	virtual bool DrawMoney(double drawMoney);

	//查询操作记录
	void CheckRecord();

	//修改账户信息
	void ModifyInf();
	
	//查看账户权限
	void CheckAuthority();
	//设置账户的权限
	void SetAuthority();

	//设置账户信息，提示输入用户信息,一般不提供ID_Number的设定，通常由系统提供！
	void SetAccountInf();		
	//根据参数设定用户信息
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


	//很多情况下ID_Number是不可以改变的，故而又出现这样一个函数，根据参数设定用户信息
	void SetAccountInf(	char *name ,						
						int accountType=0,
						double balance=0
						);

	//设定ID账号
	void SetIDNumber(long num);

	//计算月利率
	double CalculateMonthlyInterest() const;

	//获取账户信息
	char	*GetName(char name[20])const;
	long	GetIDNumber() const;
	double	GetBalance() const;
	int GetAccountType() const;
	double GetOverDraw() const;

	//返回记录管理对象
	LogManage &GetLogManage();
	
	//返回记录文件名
	string GetLogFileName();
		
	//获取年利率
	static double GetAnnualInterestRate();

	//显示账户信息
	void Display()const;

	//重载比较运算符，便于查询和排序使用
	friend bool operator==(Account &account1,Account &account2);
	friend bool operator!=(Account &account1,Account &account2);

	friend bool operator<(Account &account1,Account &account2);
	friend bool operator>(Account &account1,Account &account2);

	friend Account operator+(Account &account,double saveMoney);
	friend Account operator-(Account &account,double saveMoney);

	//重载输出输入运算符，便于账户的输出，输入
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
