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
	//������ʾDateTime��Ϣ
	void ShowDateTime();
	void show2(int n);		//�����������	

public:
	//��ȡϵͳʱ�䣬��������Ӧ�ı�����������Ʊ��е�����ʵ�ַ���
	void GetDateTime();

	//��ʱ�����͵ı��ת��Ϊ�ַ���
	string ToString();
	void ToString2(int n);		//��ʱ�����͵ı��ת��Ϊ�ַ����ĸ�������
	//����ʱ�����͵��ַ������
	string GetString() const;

	//���ַ���TStr��ʾ��ʱ��ת��Ϊ��Ӧ��ʱ����
	DateTime ToDateTime(const char *TStr);

public:
	//���رȽ�����������ں���ʹ�ã���ʾ��ֻ��Ƚ�����ʱ����ܷ��������ɣ�
	friend bool operator>(DateTime time1,DateTime time2);
	friend bool operator<(DateTime time1,DateTime time2);

	//�����������������������˻������������
	friend ostream &operator<<(ostream &os,DateTime &dateTime);
	friend fstream &operator<<(fstream &os,DateTime &dateTime);
	friend fstream &operator>>(fstream &os,DateTime &dateTime);

	DateTime(void);
	~DateTime(void);
/*
public:
	//���º���Ϊ��ȡDateTime�����Ϣ��������ʵҲ���ò�����
	int GetYear();
	int GetMonth();
	int GetDay();
	int GetHour();
	int GetMinute();
	int GetSecond();*/

	/*���º���Ϊ����DateTime�����Ϣ,���ڸ���ʱ����Ϣ�������ڱ���Ŀ�����൱�ڸ��Ĳ�����¼��
	���ǲ�����ģ����Դ˴����������еĺ�������Ϊ˽�У�������Ϊ�����Ի��Ǳ������䶨��*/
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
