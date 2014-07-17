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
	//����λ���û����������ʱ���ڵĲ�����¼�����ظ�m_ResultList
	LogRecordList &SearchRecord(LogRecordList &ResulteList);
	//����λ��dt1��dt2ʱ���ڵĲ�����¼�����ظ�m_ResultList
	LogRecordList &SearchRecord(DateTime &dt1,DateTime &dt2,
								LogRecordList &Result/*�����ʵ�ο�Ϊm_ResultList,Ҳ����Ϊ�û�ָ�����б�*/
								);

	//���ؼ�¼�б�
	LogRecordList &GetRecordList();
	//�����µĲ�����¼�б�
	LogRecordList &GetNewRecordList();

	//��ʾ��¼�б�toShow�еļ�¼
	void ShowRecordList(LogRecordList toShow);
	
	//����¼�¼
	bool AddRecord(LogRecord &newRecord);

	//��������¼����LogList��ʵ��һ��ΪAccount�е�m_RecordFileName
	bool LoadRecord(fstream &rfile);

	//д���µļ�¼������NewRecordList������׷�ӵ�RecordFile��
	bool WriteRecord(fstream &rfile);

	//�򿪼�¼�ļ�
	bool OpenRecordFile(fstream &rfile,const char * recordFileName,int openmode=ios::out|ios::in|ios::app);
	//�رռ�¼�ļ�
	bool CloseRecordFile(fstream &rfile);

	LogManage(void);
	~LogManage(void);

private:
	/*������¼���������˻�֮���������������¼Ŀ����Ϊ�˷�ֹÿ�η�
	�ʲ�����¼�Ƕ���д��Ӧ�ļ�¼�ļ�������Ч�ʽ��ͣ��˴��Կռ任ʱ�䣬
	����û������һ�ξ���LogList�������һ��������Ϊ�˱��������Ҫȫ
	������д��LogList����ÿ�β����������¼�¼�򲻻�̫�࣬�ʶ��ٴ���
	��һ��NewRecordList�����ֻ��׷�������ݼ��ɣ�*/
	LogRecordList m_LogList;	
	//�¼�¼����
	LogRecordList m_NewRecordList;	
	
	//m_LogList��һ��������
	LogRecordList::iterator logIterator;
};
#endif