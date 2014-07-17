#include "Bank.h"

#include<string.h>


Bank::Bank(void)
{
	this->TotalAccountNumber=0;
	this->m_AccountFileName=string("account.dat");
	this->Init();

}

Bank::Bank(const char *fileName)
{
	this->TotalAccountNumber=0;
	this->m_AccountFileName=string(fileName);
	this->Init();
}

Bank::Bank(string fileName)
{
	Bank(fileName.c_str());
	this->Init();
}


Bank::~Bank(void)
{
	this->UnLoadAccount();
}

void Bank::Run()
{
	//this->Init();

	int operation;
	do
	{
		system("pause");
		system("clear");
		this->Logo();

		cout<<"select you operation!"<<endl;
		//cout<<"(10)新开户\n(20)账户操作\n(30)账户统览\n(40)销户\n(50)更改年利率\n(0)退出"<<endl;
		cout<<"(10)New Account\n(20)Operate Account\n(30)Show Accounts\n(40)Delete Account\n(50)Change Interest\n(0)Exit"<<endl;
		
		cin>>operation;

Retry:
		switch(operation)
		{
		case NEWACCOUNT:		//创建新账户
			if(this->m_Manage.NewAccount())
				this->TotalAccountNumber++;
			break;
		case OPERATEACCOUNT://操作账户
			try
			{
				this->m_Manage.OperateAnAccount();
			}catch(NoFoundException ex)
			{
				ex.ShowException();
				goto Retry;
			}
			break;
		case SHOWALLACCOUNT://显示所有用户
			this->m_Manage.ShowAllAccount();
			break;
		case DELETEACCOUNT://销户
			if(this->m_Manage.DeleteAccount())
				this->TotalAccountNumber--;
			break;
		case CHANGERATE://更改年利率
			cout<<"Input the New Interest"<<endl;
			double newRate;
			cin>>newRate;
			Account::ModifyInterestRate(newRate);
			break;
		case EXIT:
			return;//exit(0);
		default:
			cout<<"Input Error,Input again！"<<endl;
		}
		this->WriteAccount();
		
	}while(operation);	
}

void Bank::Exit()
{
	this->UnLoadAccount();
	

	cout<<"\n\nByeBye,See you Next time\n\n"<<endl;
}

void Bank::Init()
{	
	try
	{
		this->LoadAccount();
	}
	catch(Exception ex)
	{
		ex.ShowException();
		exit(0);
	}
	
	//initial code
	this->TotalAccountNumber=this->m_Manage.GetSizeOfAccountList();
	
	this->Logo();

}

void Bank::Logo()
{
	cout<<"_______________________"<<endl;
	cout<<"***********************"<<endl;
	cout<<"Running !\n";
	cout<<"Welcom to TCL Bank!"<<endl;
	cout<<"Current Interest:"<<Account::GetInterestRate()<<endl;
	cout<<"Current TotalAccountNumber:"<<this->TotalAccountNumber<<endl;
	cout<<"***********************"<<endl;
	cout<<"_______________________"<<endl;
}


//加载账户信息
void Bank::LoadAccount()
{
	int createFile;
	int OpenMode=ios::out|ios::in|ios::binary;//|ios::_Nocreate;
RetryOpenFile:
	try
	{
		this->m_Manage.OpenAccountFile(this->m_AccountFile,this->m_AccountFileName.c_str(),OpenMode);
	}
	catch(OpenFileException fex)
	{
		fex.ShowException();		
		cin>>createFile;
		if(createFile)
		{
			cout<<"Creating Account Data File..."<<endl;
			OpenMode=ios::out|ios::in|ios::binary|ios::trunc;
			//fstream f("account.dat",ios::out);
			//f.close();
			//system((string("c:>")+string(this->m_AccountFileName/*"accounttt.txt"*/)).c_str());			
			goto RetryOpenFile;
		}
		else throw *(new Exception("Running Error, exit right now!"));
	}	
	this->m_Manage.ReadAccoutList(this->m_AccountFile);
	this->m_Manage.CloseAccountFile(this->m_AccountFile);
}

bool Bank::WriteAccount()
{
	try
	{
		this->m_Manage.OpenAccountFile(this->m_AccountFile,this->m_AccountFileName.c_str(),ios::out|ios::binary);
		this->m_Manage.PutAccountList(this->m_AccountFile);
		this->m_Manage.CloseAccountFile(this->m_AccountFile);
	}
	catch(FileException fex)
	{
		fex.ShowException();
		return false;
	}
	return true;
}

//卸载账户信息
void Bank::UnLoadAccount()
{
	/*Account *pA;
	AccountList::iterator it;
	for(it=this->m_Manage.GetAccountList().begin();it!=this->m_Manage.GetAccountList().end();)
	{
		*pA=*it;
		it++;
		delete pA;
	}*/
}
