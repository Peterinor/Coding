#include "LogRecord.h"


DateTime LogRecord::GetDateTime()
{
	return this->m_Time;
}
int LogRecord::GetOperation(){return 0;}
double LogRecord::GetBalance(){return 0.0;}



void LogRecord::ShowRecord()
{
	cout<<this->m_RecordStr<<endl;
}

string LogRecord::ToString()
{
	char m[50];
	this->m_RecordStr.clear();
	this->m_RecordStr+=(this->m_Time.GetString()+"\t"+this->m_OperationStr+"\tTrans Money:"
		+string(itoa(this->ExchangeMoney,m,10))+"\tBalance:"+string(itoa(this->m_Balance,m,10)));
	return this->m_RecordStr;
}

string LogRecord::GetString()
{
	return this->m_RecordStr;
}

void LogRecord::ToRecord(char *recordStr)
{
	this->m_Time.ToDateTime(recordStr);
	string *Str;
	char *pRStr=recordStr;
	//获取操作名称
	while(*pRStr!='\t')pRStr++;
	pRStr++;
	Str=new string(pRStr);
	//this->m_OperationStr.clear();
	this->m_OperationStr.assign(*Str,0,sizeof("DrawMoney")-1);

	//获取交易金额
	while(*pRStr!=':')pRStr++;
	pRStr++;
	Str=new string(pRStr);
	this->ExchangeMoney=atof(Str->c_str());

	//获取操纵后的余额
	while(*pRStr!=':')pRStr++;
	pRStr++;
	Str=new string(pRStr);
	this->m_Balance=atof(Str->c_str());

	//从文件获取操作类型
	this->Operation(this->m_OperationStr);
	this->ToString(); 

}

int LogRecord::Operation(string &operationStr)
{
	if(operationStr==string("NewAccount"))this->m_Operation=NEWACCOUNT;
	if(operationStr==string("DeleteAccount"))this->m_Operation=DELETEACCOUNT;
	if(operationStr==string("Deposit"))this->m_Operation=DEPOSITE;
	if(operationStr==string("DrawMoney"))this->m_Operation=DRAWMONEY;
	if(operationStr==string("GetBalance"))this->m_Operation=GETBALANCE;
	if(operationStr==string("Display"))this->m_Operation=DISPLAY;		
	if(operationStr==string("ModifyInf"))	this->m_Operation=MODIFYINF;
	if(operationStr==string("CheckAuthority"))this->m_Operation=CHECKAUTHORITY;
	if(operationStr==string("SetAuthority"))this->m_Operation=SETAUTHORITY;
	this->m_Operation=0;

	return this->m_Operation;
	
}

LogRecord::LogRecord(void)
{
	this->m_Time=*(new DateTime());
	this->m_Operation=0;
	this->m_OperationStr=string("do nothing");
	this->ExchangeMoney=0;
	this->m_Balance=0;
}

LogRecord::LogRecord(DateTime dt,int operation,double exMoney,double balance)
{
	this->m_Time=dt;
	this->m_Operation=operation;
	this->ExchangeMoney=exMoney;
	this->m_Balance=balance;

	this->OperationStr(operation);

		
	this->ToString();
}

string LogRecord::OperationStr(int operation)
{
	switch(operation)
	{
	case NEWACCOUNT:
		this->m_OperationStr=string("NewAccount");
		break;
	case DELETEACCOUNT:
		this->m_OperationStr=string("DeleteAccount");
		break;
	case DEPOSITE:			//存款
		this->m_OperationStr=string("Deposit");
		break;
	case DRAWMONEY:			//取款
		this->m_OperationStr=string("DrawMoney");
		break;
	case GETBALANCE:		//查询余额
		this->m_OperationStr=string("GetBalance");
		break;
	case DISPLAY:			//显示账户全部信息
		this->m_OperationStr=string("Display");
		break;	
	case MODIFYINF:
		this->m_OperationStr=string("ModifyInf");
		break;
	case CHECKAUTHORITY:
		this->m_OperationStr=string("CheckAuthority");
		break;
	case SETAUTHORITY:
		this->m_OperationStr=string("SetAuthority");
		break;
	default:
		this->m_OperationStr=string("Other");
	}
	return this->m_OperationStr;
}


//bool LogRecord::OpenRecordFile(char *fileName)
//{
//	this->m_RecordFile.open(fileName);
//	if(!this->m_RecordFile)
//		throw *(new OpenFileException("打开记录文件失败！"));
//	return true;
//}
//bool LogRecord::CloseRecordFile()
//{
//	return true;
//
//}



LogRecord::~LogRecord(void)
{
}


bool operator==(LogRecord &log1,LogRecord &log2)
{
	return (log1.GetString()==log2.GetString());
}


//重载输出输入运算符，便于账户的输出，输入
ostream  &operator<<(LogRecord &logRecord,ostream &os)
{
	logRecord.ShowRecord();
	return os;
}
fstream &operator<<(LogRecord &logRecord,fstream &fs)
{
	fs<<logRecord.m_RecordStr;
	return fs;
}


fstream &operator>>(LogRecord &logRecord,fstream &fs)
{
	//logRecord.m_RecordStr;	--no use
	return fs;
}
