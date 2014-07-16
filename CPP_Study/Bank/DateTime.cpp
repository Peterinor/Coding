#include "DateTime.h"
//#include<windows.h>

#include<string.h>

void DateTime::ShowDateTime()
{
	cout<<this->TimeStr;

	/*这是原来的方式
	cout<<year;
	show2(this->month);
	show2(this->day);
	show2(this->hour);
	show2(this->minute);
	show2(this->second);
	cout<<endl;*/
	//cout<<month<<"-"<<day<<"-"<<hour
	//	<<"-"<<minute<<"-"<<second<<endl;
}

void DateTime::show2(int n)
{
	if(n<10)cout<<'-'<<0<<n;
	else cout<<'-'<<n;
}

string DateTime::ToString()
{
	char temp[5];
	TimeStr.clear();
	TimeStr=TimeStr+string(itoa(this->year,temp,10));
	ToString2(this->month);
	ToString2(this->day);
	ToString2(this->hour);
	ToString2(this->minute);
	ToString2(this->second);
	
	return this->TimeStr;
}

string DateTime::GetString() const
{
	return this->TimeStr;
}
void DateTime::ToString2(int n)
{
	char temp[5];
	if(n<10)
		TimeStr=TimeStr+"-0"+string(itoa(n,temp,10));
	else
		TimeStr=TimeStr+"-"+string(itoa(n,temp,10));
}

DateTime DateTime::ToDateTime(const char *TStr)
{
	//char *ts=TStr;
	this->year=atoi(TStr);
	TStr+=5;
	this->month=atoi(TStr);
	TStr+=3;
	this->day=atoi(TStr);
	TStr+=3;
	this->hour=atoi(TStr);
	TStr+=3;
	this->minute=atoi(TStr);
	TStr+=3;
	this->second=atoi(TStr);
	TStr+=3;
	this->ToString();

	this->m_t=(this->year-1900)*365*24*60+this->month*30*24*60+this->day*24*60+this->minute;

	return *this;
}

void DateTime::GetDateTime()
{
	tm t;
	m_t=time(NULL);
	t=*localtime(&m_t);
	this->year=t.tm_year+1900;
	this->month=t.tm_mon+1;
	this->day=t.tm_mday;
	this->hour=t.tm_hour;
	this->minute=t.tm_min;
	this->second=t.tm_sec;
	
	this->m_t=(this->year-2000)*365*24*60+this->month*30*24*60+this->day*24*60+this->minute;

}

DateTime::DateTime(void )
{
	this->GetDateTime();
	
	this->ToString();
}

DateTime::~DateTime(void )
{
}

//重载运算符————————————————————————————————————————
bool operator>(DateTime time1,DateTime time2)
{
	return time1.m_t>time2.m_t;
}
bool operator<(DateTime time1,DateTime time2)
{
	return time1.m_t<time2.m_t;
}

//重载输出输入运算符，便于账户的输出，输入
ostream &operator<<(ostream &os,DateTime &dateTime)
{
	dateTime.ShowDateTime();
	return os;
}
	
fstream &operator<<(fstream &fs,DateTime &dateTime)
{
	fs<<dateTime.TimeStr;
	return fs;
}
fstream &operator>>(fstream &fs,DateTime &dateTime)
{
	fs>>dateTime.TimeStr;
	return fs;
}


//设置和获取时间！————————————————————————————————————
/*
int DateTime:: GetYear()
{
	return this->year;
}
int DateTime:: GetMonth()
{
	return this->month;
}
int DateTime:: GetDay()
{
	return this->day;
}
int DateTime:: GetHour()
{
	return this->hour;
}
int DateTime:: GetMinute()
{
	return this->minute;
}
int DateTime:: GetSecond()
{
	return this->second;
}

void DateTime:: SetYear(){}
void DateTime:: SetMonth(){}
void DateTime:: SetDay(){}
void DateTime:: SetHour(){}
void DateTime:: SetMinute(){}
void DateTime:: SetSecond(){}

void DateTime:: SetYear(int y)
{
	this->year=y;
}
void DateTime:: SetMonth(int m)
{
	this->month=m;
}
void DateTime:: SetDay(int d)
{
	this->day=d;
}
void DateTime:: SetHour(int h)
{
	this->hour=h;
}
void DateTime:: SetMinute(int m)
{
	this->minute=m;
}
void DateTime:: SetSecond(int s)
{
	this->second=s;
}
*/
