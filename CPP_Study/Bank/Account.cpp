#include "Account.h"

#include<iostream>
#include <iomanip>
#include<cstring>

#include<cstdlib>
#include<ctime>

using namespace std;


double Account::m_AnnualInterestRate=0.03;

Account::Account()
{
	strcpy(this->m_Name,"no name");
	this->m_Balance=0;
	this->m_OverDraw=0.0;
	this->InitLogFileName();
}

Account::Account( const char *name,long IDNumber,double balance,int accountType,double overdraw)
{
	strcpy(this->m_Name,name);
	this->m_Balance=balance;
	this->m_IDNumber=IDNumber;
	this->m_AccountType=0;
	this->m_Balance=balance;
	this->m_OverDraw=overdraw;
	this->InitLogFileName();
}

Account::Account(const Account &Account)
{
	strcpy(this->m_Name,Account.m_Name);
	this->m_Balance=Account.m_Balance;
	this->m_IDNumber=Account.m_IDNumber;
	this->m_AccountType=Account.m_AccountType;
	if(this->m_AccountType==VIPACCOUNT)this->m_OverDraw=3000.0;
	else this->m_OverDraw=0.0;
	this->InitLogFileName();
}

Account::~Account(){}

void Account::InitLogFileName()
{
	char tempNumStr[15];
	this->m_LogRecordFileName=this->m_LogRecordFileName+itoa(this->m_IDNumber,tempNumStr,10)+"LogRec.txt";
}
double Account::CalculateMonthlyInterest()const
{
	return this->m_Balance*this->m_AnnualInterestRate/12;
}

string Account::GetLogFileName()
{
	return this->m_LogRecordFileName;
}


double Account::ModifyInterestRate(double newRate)
{
	Account::m_AnnualInterestRate=newRate;
	return Account::m_AnnualInterestRate;
}

double Account::GetInterestRate()
{
	return Account::m_AnnualInterestRate;
}

void Account::ModifyInf()
{
	cout<<"Input user Name:";
	cin>>this->m_Name;
	cout<<"\nInput Accout Type (1)VIP (0)Ordinary User: ";
	cin>>this->m_AccountType;
}

void Account::SetAccountInf()
{
	cout<<"Input User Name:";
	cin>>this->m_Name;
	cout<<"\nInput Account Balance:";
	cin>>this->m_Balance;
	cout<<"\nInput Account Type (1)VIP (0)Ordinary User: ";
	cin>>this->m_AccountType;
	if(this->m_AccountType==VIPACCOUNT)this->m_OverDraw=3000.0;
	else this->m_OverDraw=0.0;
}



void Account::SetAccountInf(char *name ,
							long ID_number,
							int accountType,
							double balance)
{
	this->m_AccountType=accountType;
	this->m_IDNumber=ID_number;
	strcpy(this->m_Name,name);
	this->m_Balance=balance;
	this->InitLogFileName();
	if(this->m_AccountType==VIPACCOUNT)this->m_OverDraw=3000.0;
	else this->m_OverDraw=0.0;
}

void Account::SetAccountInf(char *name ,
							long ID_number,
							int accountType,
							double balance,
							double overdraw)
{
	this->m_AccountType=accountType;
	this->m_IDNumber=ID_number;
	strcpy(this->m_Name,name);
	this->m_Balance=balance;
	this->InitLogFileName();
	this->m_OverDraw=overdraw;
}


void Account::SetAccountInf(char *name ,
							int accountType,
							double balance)
{
	this->m_AccountType=accountType;
	strcpy(this->m_Name,name);
	this->m_Balance=balance;
	if(this->m_AccountType==VIPACCOUNT)this->m_OverDraw=3000.0;
	else this->m_OverDraw=0.0;
}

void Account::SetIDNumber(long num)
{
	this->m_IDNumber=num;
	this->InitLogFileName();
}

bool Account::Deposit(double saveMoney)
{
	this->m_Balance+=saveMoney;
	cout<<"Save Seccess, Show Balance?  Y(1)  N(0)"<<endl;
	bool show;
	cin>>show;
	if(show) cout<<"Balance is:"<<this->m_Balance<<endl;
	return true;
}
bool Account::DrawMoney(double drawMoney)
{
	if((this->m_Balance+this->m_OverDraw)<drawMoney)
	{
		cout<<"No enough money,beyond the xinyong!> Draw money failed!"<<endl;
		return false;
	}else
	{
		this->m_Balance-=drawMoney;
		cout<<"Draw Money Seccess, Show Balance? Y(1)  N(0)"<<endl;
		bool show;
		cin>>show;
		if(show) cout<<"Balance is:"<<this->m_Balance<<endl;
		return true;
	}
}

void Account::CheckRecord()
{			
	//读取记录文件里面的记录到记录列表
	//this->m_LogManage.OpenRecordFile(/*this->*/m_LogRecordFile,this->m_LogRecordFileName.c_str(),ios::in);
	//this->m_LogManage.LoadRecord(/*this->*/m_LogRecordFile);;
	char means;
	cout<<"\n Inquery Operate Records: Input a for All Records, b to Inquery by datetime:Money Can be OverDrew: "<<endl;
	cin>>means;
	if(means=='a')
	{
		this->m_LogManage.ShowRecordList(this->m_LogManage.GetRecordList());
		this->m_LogManage.ShowRecordList(this->m_LogManage.GetNewRecordList());
	}
	else
	{
		cout<<"\nInput the start and end time Such as 2010-5-10-12-00-00"<<endl;
		LogRecordList RecordList;
		this->m_LogManage.ShowRecordList(this->m_LogManage.SearchRecord(RecordList));
	}
	//this->m_LogManage.CloseRecordFile(/*this->*/m_LogRecordFile);
}

void Account::CheckAuthority()
{
	cout<<"The Account is:";
	if(this->m_AccountType==VIPACCOUNT)cout<<"VIP User"<<endl;
	else cout<<"Ordinary User"<<endl;
	cout<<"Money Can be OverDrew: "<<this->m_OverDraw<<endl;
}
void Account::SetAuthority()
{
	cout<<"\nInput the Account Type (1)VIP (0)Ordinary: ";
	cin>>this->m_AccountType;
	cout<<"Input Money Can be OverDrew:";
	cin>>this->m_OverDraw;
}
//获取账户信息
char* Account::GetName(char name[20]) const
{
	strcpy(name,this->m_Name);
	return name;
}

double Account::GetBalance() const
{
	return this->m_Balance;
}

long Account::GetIDNumber() const
{
	return this->m_IDNumber;
}

int Account::GetAccountType() const
{
	return this->m_AccountType;
}

double Account::GetOverDraw() const
{
	return this->m_OverDraw;
}


LogManage &Account::GetLogManage()
{
	return this->m_LogManage;
}


double Account::GetAnnualInterestRate()
{
	return Account::m_AnnualInterestRate;
}

void Account::Display() const
{
	cout<<"__________________________\n";
	cout<<this->m_Name<<"'s Account Information is as Follows:"<<endl;
	cout<<"Name: "<<this->m_Name<<endl
		<<"ID_Number: "<<this->m_IDNumber<<endl
		<<"Balance: "<<this->m_Balance<<endl
		<<"Account Type:";
	if(this->m_AccountType==VIPACCOUNT)cout<<"VIP User"<<endl;
	else cout<<"Ordinary User "<<endl;
	cout<<"__________________________\n";
}

Account operator+(Account &account,double saveMoney)
{
	account.m_Balance+=saveMoney;
	return account;
}
Account operator-(Account &account,double drawMoney)
{
	if(account.m_Balance<drawMoney)
	{
		cout<<"No enough Money, Draw Money failed!"<<endl;
		return account;
	}else
	{
		account.m_Balance-=drawMoney;
		cout<<"Draw Money Seccess, Show Balance? Y(1)  N(0)"<<endl;
		bool show;
		cin>>show;
		if(show) account.Display();		
	}	
	return account;
}


//重载比较运算符，便于查询和排序使用
bool operator==(Account &account1,Account &account2)
{
	return true;
}
bool operator!=(Account &account1,Account &account2)
{
	return true;
}

bool operator<(Account &account1,Account &account2)
{
	return true;
}
bool operator>(Account &account1,Account &account2)
{
	return true;
}

ostream &operator<<(ostream &os,Account &account)
{
	account.Display();
	return os;
}

fstream &operator<<(fstream &fs,Account &account)
{
	AccountStruct saccount={"","",account.GetAccountType(),
		account.GetBalance(),account.GetOverDraw()};
	strcpy(saccount.Name,account.GetName(saccount.Name));
	itoa(account.GetIDNumber(),saccount.IDNumber,10);

	fs.write((char *)&saccount, sizeof(AccountStruct ));

	return fs;

}

fstream &operator>>(fstream &fs,Account &account)
{
	AccountStruct saccount;
	fs.read((char *)&saccount, sizeof(AccountStruct ));
	account.SetAccountInf(saccount.Name,atoi(saccount.IDNumber),
		saccount.AccountType,saccount.Balance,saccount.OverDraw);	
	return fs;
}
