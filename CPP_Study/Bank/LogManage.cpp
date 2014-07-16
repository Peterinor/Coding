#include "LogManage.h"

LogRecordList &LogManage::SearchRecord(LogRecordList &ResulteList)
{
	char datetime[25];
	cout<<"Inquery the Operate Records:"<<endl;
	cout<<"Input the Start Time: Such as 2010-12-10-12-06-30):";
	cin>>datetime;	
	DateTime dt1;	
	dt1.ToDateTime(datetime);	
	cout<<"\nInput the End Time: Such as 2010-12-10-12-06-30):";
	cin>>datetime;//cin.getline(datetime,sizeof(datetime));
	DateTime dt2;	
	dt2.ToDateTime(datetime);	

	this->SearchRecord(dt1,dt2,ResulteList);

	return ResulteList;
}

LogRecordList &LogManage::SearchRecord(DateTime &dt1,DateTime &dt2,
							LogRecordList &Resulte/*�����ʵ�ο�Ϊm_ResultList,Ҳ����Ϊ�û�ָ�����б�*/
							)
{
	for(this->logIterator=this->m_LogList.begin();this->logIterator!=this->m_LogList.end();this->logIterator++)
	{
		if((this->logIterator->GetDateTime()>dt1)&&(this->logIterator->GetDateTime()<dt2))
		{
			Resulte.push_back(*this->logIterator);
		}		
	}
	for(this->logIterator=this->m_NewRecordList.begin();this->logIterator!=this->m_NewRecordList.end();this->logIterator++)
	{
		if((this->logIterator->GetDateTime()>dt1)&&(this->logIterator->GetDateTime()<dt2))
		{
			Resulte.push_back(*this->logIterator);
		}		
	}
	return Resulte;

}

LogRecordList &LogManage::GetRecordList()
{
	return this->m_LogList;
}
LogRecordList &LogManage::GetNewRecordList()
{
	return this->m_NewRecordList;
}

void LogManage::ShowRecordList(LogRecordList toShow)
{
	cout<<"Operate Records are As Follows:"<<endl;
	LogRecordList::iterator itShow;
	for(itShow=toShow.begin();itShow!=toShow.end();itShow++)
	{
		itShow->ShowRecord();
	}
}


bool LogManage::AddRecord(LogRecord &newRecord)
{
	this->m_NewRecordList.push_back(newRecord);
	if(this->m_NewRecordList[this->m_NewRecordList.size()-1]==newRecord)
		return true;
	else return false;
}


/*********************************�ļ�����********************************************/

//�򿪼�¼�ļ�
bool LogManage::OpenRecordFile(fstream &rfile,const char * recordFileName,int openmode)
{
	//׷�ӵķ�ʽ�򿪼�¼�ļ�
	rfile.open(recordFileName,(std::_Ios_Openmode)openmode);
	if(!rfile)throw *(new OpenFileException("Open RecordFile Failed!"));
	return true;
}
//�رռ�¼�ļ�
bool LogManage::CloseRecordFile(fstream &rfile)
{
	if(!rfile)throw *(new CloseFileException("File is Closed, Open it first!"));
	rfile.close();
	return true;
}

bool LogManage::LoadRecord(fstream &rfile)
{
	LogRecord tempRecord;
	char recordStr[25];
	this->m_LogList.clear();//��ռ�¼�б���ֹ��������¼
	while(!rfile.eof())
	{
		rfile.getline(recordStr,sizeof(recordStr));
		tempRecord.ToRecord(recordStr);
		this->m_LogList.push_back(tempRecord);
	}
	return 1;
}

//д���µĲ�����¼��
bool LogManage::WriteRecord(fstream &rfile)
{
	for(this->logIterator=this->m_NewRecordList.begin();
			this->logIterator!=this->m_NewRecordList.end();
				this->logIterator++)
	{
		rfile<<this->logIterator->GetString()<<endl;
	}
	return true;
}

LogManage::LogManage(void)
{
}

LogManage::~LogManage(void)
{
}


