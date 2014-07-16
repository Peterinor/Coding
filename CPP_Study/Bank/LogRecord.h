//#pragma once
#ifndef _LOGRECORD_H_
#define _LOGRECORD_H_

#include"define.h"

#include"DateTime.h"

class LogRecord
{
public:
	//获取记录中的时间
	DateTime GetDateTime();
	//获取记录中的操作类型
	int GetOperation();
	//获取操作记录中的余额信息
	double GetBalance();

	//在控制台中显示Record的内容
	void ShowRecord();
	
	//将记录类型的表达转换为对应的字符串表达
	string ToString();
	//返回记录的字符串表达
	string GetString();

	//将字符串转换为Record，留待完成！
	void ToRecord(char *recordStr);

	//重载输出输入运算符，便于账户的输出，输入
	friend ostream  &operator<<(LogRecord &logRecord,ostream &os);
	friend fstream &operator<<(LogRecord &logRecord,fstream &fs);
	friend fstream &operator>>(LogRecord &logRecord,fstream &fs);

	friend bool operator==(LogRecord &log1,LogRecord &log2);
	
	//将操作类型从int转换为字符串
	string OperationStr(int operation);
	//将操作类型从字符串转换为int
	int Operation(string &operationStr);
	
	LogRecord(void);
	LogRecord(DateTime dt,int operation,double exMoney,double balance);
	~LogRecord(void);

private:
	DateTime m_Time;
	int m_Operation;
	double ExchangeMoney;	//交易量，即存取款的额度
	double m_Balance;		//余额信息，即为Account的m_Balance
	string m_RecordStr;
	string m_OperationStr;

};

#endif