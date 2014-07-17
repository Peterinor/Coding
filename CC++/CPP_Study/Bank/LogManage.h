//#pragma once
#ifndef _LOGMANAGE_H_
#define _LOGMANAGE_H_

#include"define.h"
#include"LogRecord.h"
#include"DateTime.h"

#include<vector>

using namespace std;

typedef vector<LogRecord> LogRecordList;

class LogManage
{
public:
	//查找位于用户输入的两个时间内的操作记录，返回给m_ResultList
	LogRecordList &SearchRecord(LogRecordList &ResulteList);
	//查找位于dt1到dt2时间内的操作记录，返回给m_ResultList
	LogRecordList &SearchRecord(DateTime &dt1,DateTime &dt2,
								LogRecordList &Result/*这里的实参可为m_ResultList,也可以为用户指定的列表*/
								);

	//返回记录列表
	LogRecordList &GetRecordList();
	//返回新的操作记录列表
	LogRecordList &GetNewRecordList();

	//显示记录列表toShow中的记录
	void ShowRecordList(LogRecordList toShow);
	
	//添加新纪录
	bool AddRecord(LogRecord &newRecord);

	//将操作记录载入LogList，实参一般为Account中的m_RecordFileName
	bool LoadRecord(fstream &rfile);

	//写入新的记录，即将NewRecordList的内容追加到RecordFile中
	bool WriteRecord(fstream &rfile);

	//打开记录文件
	bool OpenRecordFile(fstream &rfile,const char * recordFileName,int openmode=ios::out|ios::in|ios::app);
	//关闭记录文件
	bool CloseRecordFile(fstream &rfile);

	LogManage(void);
	~LogManage(void);

private:
	/*操作记录向量，打开账户之后立马载入操作记录目的是为了防止每次访
	问操作记录是都读写相应的记录文件而导致效率降低，此处以空间换时间，
	并且没操作玩一次就再LogList后面加入一条，但是为了避免最后需要全
	部重新写入LogList，而每次操作产生的新纪录则不会太多，故而再次新
	建一个NewRecordList，最后只需追加其内容即可！*/
	LogRecordList m_LogList;	
	//新纪录向量
	LogRecordList m_NewRecordList;	
	
	//m_LogList的一个迭代器
	LogRecordList::iterator logIterator;
};
#endif