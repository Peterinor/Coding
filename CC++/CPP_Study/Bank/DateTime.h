//#pragma once
#ifndef _DATETIME_H_
#define _DATETIME_H_

#include"define.h"

#include<time.h>

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class DateTime
{
public:	
	//对外显示DateTime信息
	void ShowDateTime();
	void show2(int n);		//辅助输出函数	

public:
	//获取系统时间，并赋给相应的变量。参照设计表中的两种实现方法
	void GetDateTime();

	//将时间类型的表达转换为字符串
	string ToString();
	void ToString2(int n);		//将时间类型的表达转换为字符串的辅助函数
	//返回时间类型的字符串表达
	string GetString() const;

	//将字符串TStr表示的时间转换为对应的时间表达
	DateTime ToDateTime(const char *TStr);

public:
	//重载比较运算符，便于后期使用（提示，只需比较两个时间的总分钟数即可）
	friend bool operator>(DateTime time1,DateTime time2);
	friend bool operator<(DateTime time1,DateTime time2);

	//重载输出输入运算符，便于账户的输出，输入
	friend ostream &operator<<(ostream &os,DateTime &dateTime);
	friend fstream &operator<<(fstream &os,DateTime &dateTime);
	friend fstream &operator>>(fstream &os,DateTime &dateTime);

	DateTime(void);
	~DateTime(void);
/*
public:
	//以下函数为获取DateTime相关信息，这里其实也是用不到的
	int GetYear();
	int GetMonth();
	int GetDay();
	int GetHour();
	int GetMinute();
	int GetSecond();*/

	/*以下函数为设置DateTime相关信息,用于更改时间信息，但是在本项目里这相当于更改操作记录，
	这是不容许的，所以此处将以下所有的函数都设为私有，但是作为完整性还是保留了其定义*/
private:
	/*
	void SetYear();
	void SetMonth();
	void SetDay();
	void SetHour();
	void SetMinute();
	void SetSecond();

	void SetYear(int y);
	void SetMonth(int m);
	void SetDay(int d);
	void SetHour(int h);
	void SetMinute(int m);
	void SetSecond(int s);*/


private:
	int year,month,day;
	int hour,minute,second;
	time_t m_t;
	string TimeStr;
};

#endif
