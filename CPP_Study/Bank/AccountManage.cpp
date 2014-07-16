#include "AccountManage.h"

#include "Exception.h"
#include "LogRecord.h"

AccountManage::AccountManage(void)
{
}

AccountManage::~AccountManage(void)
{
}

//����˻�
bool AccountManage::NewAccount()
{
	Account *addAccount=new Account();
	cout<<"Now Adding An Account,Please Follow The Information!"<<endl;
	//cout<<"����˻�,����������Ϣ��"<<endl;
	addAccount->SetAccountInf();

	addAccount->SetIDNumber(this->m_AccountList.size()+20100001);
	this->m_AccountList.push_back(*addAccount);
		
	if(this->m_AccountList[this->m_AccountList.size()-1]==*addAccount)
	{
		cout<<"Add successfully!"<<endl;
		//cout<<"�ɹ����!"<<endl;
		LogRecord newAccount(*(new DateTime()),NEWACCOUNT,addAccount->GetBalance(),addAccount->GetBalance());
		this->m_AccountList[this->m_AccountList.size()-1].GetLogManage().AddRecord(newAccount);
		return true;
	}
	else
	{
		cout<<"Error! Fail to Add"<<endl;
		//cout<<"��������! ���ʧ��"<<endl;
		return false;
	}
}

bool AccountManage::NewAccount(Account &accountToAdd)
{
	this->m_AccountList.push_back(accountToAdd);	
	if(this->m_AccountList[this->m_AccountList.size()-1]==accountToAdd)
	{
		this->m_AccountList[this->m_AccountList.size()-1].SetIDNumber(this->m_AccountList.size()+20100001);

		LogRecord newAccount(*(new DateTime()),NEWACCOUNT,accountToAdd.GetBalance(),accountToAdd.GetBalance());
		accountToAdd.GetLogManage().AddRecord(newAccount);

		return true;
	}
	else return false;
}


Account *AccountManage::SearchAccount()
{
	int IDToSearch;
	cout<<"Please Input The ID_Number of the Accout��"<<endl;
	//cout<<"�������˻���ID�ţ�"<<endl;
	
	cin>>IDToSearch;
	
	return this->SearchAccount(IDToSearch);	
}

Account *AccountManage::SearchAccount(long  accountID)
{
	for(this->m_AccountListIterator=this->m_AccountList.begin();
			this->m_AccountListIterator!=this->m_AccountList.end();
			this->m_AccountListIterator++)
	{
		if(this->m_AccountListIterator->GetIDNumber()==accountID)
		{
			this->m_ResultAccount=*this->m_AccountListIterator;
			return &this->m_ResultAccount;
		}
	}	
	throw *(new NoFoundException("No Account Found, Confirm and Input again!"));
//	throw *(new NoFoundException("û���ҵ����˻�����ȷ��������Ϣ�����������룡"));//\n�����û�ID��(������0�򷵻ز���)��"));
}


bool AccountManage::DeleteAccount()
{
	if(this->m_AccountList.size()==0)
	{
		cout<<"No a sigle Account!"<<endl;
//		cout<<"Ŀǰû���κ�һ���û���"<<endl;
		return false;
	}
//	cout<<"Input the IDNumber of The Account You Want To Delete!"<<endl
//		<<"IDNumber : ";
	//cout<<"����Ҫɾ���˺ŵ�ID��!"<<endl
	//	<<"ID���� : ";
	cout<<"Input the ID_Number of the Account!"<<endl
		<<"IDNumber: ";
	int IDNumber;
	cin>>IDNumber;

	return this->DeleteAccount(IDNumber);
}

bool AccountManage::DeleteAccount(long AccountID)
{
	this->SearchAccount(AccountID);
	
	if(this->m_AccountListIterator->GetIDNumber()==AccountID)
	{
		LogRecord newAccount(*(new DateTime()),DELETEACCOUNT,
			this->m_AccountListIterator->GetBalance(),this->m_AccountListIterator->GetBalance());
		this->m_AccountListIterator->GetLogManage().AddRecord(newAccount);
		//delete this->m_AccountListIterator!
		this->m_AccountList.erase(this->m_AccountListIterator);
		//cout<<"Delete successfully!"<<endl;		
		return true;
	}

			cout<<"No Account to Operate!"<<endl;//cout<<"NO Matech Account Found ! Fail to Delete!"<<endl;
			//cout<<"Ŀǰû���κ�һ���û��ɲ�����"<<endl;//cout<<"NO Matech Account Found ! Fail to Delete!"<<endl;
	return false;
}


void AccountManage::ShowAllAccount()
{
	if(this->m_AccountList.size()==0)
	{
		cout<<"No Account to Display!"<<endl;
		return ;
	}

	for(this->m_AccountListIterator=this->m_AccountList.begin();
			this->m_AccountListIterator!=this->m_AccountList.end();
				this->m_AccountListIterator++)
	{
		this->m_AccountListIterator->Display();
	}
}


bool AccountManage::OperateAnAccount(/*int operation*/)
{
	long IDNumber;
	int operation;
	bool BackOrGo=true;		//go

	if(this->m_AccountList.size()==0)
	{
		//cout<<"Ŀǰû���κ�һ���û��ɲ�����"<<endl;
		cout<<"No Account to Operate now!"<<endl;
		return false;
	}
	
//	cout<<"����Ҫ�������˺ŵ�ID��!ID��λ20100000���˺�����ĺͣ���20100001"<<endl
	cout<<"Input the ID_Number of the Account, Such as 20100001"<<endl
		<<"ID_Number: ";
	
	cin>>IDNumber;

	this->SearchAccount(IDNumber);			
	
	this->m_ResultAccount.Display();

	while(BackOrGo)
	{	
		system("clear");
		this->m_ResultAccount.Display();
	/*	cout<<"��ѡ���������!"<<endl
			<<"(1)���\n(2)ȡ��\n(3)��ѯ���\n(4)�鿴������¼\n(5)��ʾ�˻�ȫ����Ϣ\n"
			"(6)�޸��˻���Ϣ\n(7)�鿴�˻�Ȩ��\n(8)�趨�˻�Ȩ��\n(0)����"<<endl;*/
		cout<<"Choose the Operate!"<<endl
			<<"(1)���\n(2)ȡ��\n(3)��ѯ���\n(4)�鿴������¼\n(5)��ʾ�˻�ȫ����Ϣ\n"
			"(6)�޸��˻���Ϣ\n(7)�鿴�˻�Ȩ��\n(8)�趨�˻�Ȩ��\n(0)Back"<<endl;

		cin>>operation;

		if(operation==BACK) return false;	//do nothing

		this->OperateAnAccount(operation,this->m_ResultAccount);

		for(this->m_AccountListIterator=this->m_AccountList.begin();
				this->m_AccountListIterator!=this->m_AccountList.end();
					this->m_AccountListIterator++)
		{
			if(this->m_AccountListIterator->GetIDNumber()==this->m_ResultAccount.GetIDNumber())
			{
				*this->m_AccountListIterator=this->m_ResultAccount;
			}
		}
		
		cout<<"\n������ɣ�����(0) ���ǶԸ��˻��������в���(1)!"<<endl;
		cin>>BackOrGo;
	}
	return true;
}


bool AccountManage::OperateAnAccount(int operation ,Account &account)
{
	int money=0;

	switch(operation)
	{
	case DEPOSITE:			//���
//		cout<<"Input the Cash Number you want to deposite!"<<endl
//			<<"Cash amount : ";
		cout<<"��������!"<<endl
			<<"����� : ";
		cin>>money;
		if(!account.Deposit(money))
			return false;
		break;
	case DRAWMONEY:			//ȡ��
//		cout<<"Input the Cash Number you want to get!"<<endl
//			<<"Cash amount : ";
		cout<<"����ȡ����!"<<endl
			<<"ȡ���� :  ";
		cin>>money;
		if(!account.DrawMoney(money))
			return false;
		break;
	case GETBALANCE:		//��ѯ���
		cout<<"�˻����Ϊ��"<<account.GetBalance()<<endl;
		break;
	case CHECKRECORD:		//�鿴������¼
		account.CheckRecord();
		return true;
	case DISPLAY:			//��ʾ�˻�ȫ����Ϣ
		account.Display();
		break;
	case MODIFYINF:			//�޸��˻���Ϣ
		account.ModifyInf();
		break;
	case CHECKAUTHORITY:
		account.CheckAuthority();
		break;
	case SETAUTHORITY:
		account.SetAuthority();
		break;
	case BACK:				//����	
		return true;
	default:
		cout<<"����������������룡"<<endl;
	}
	LogRecord newAccount(*(new DateTime()),operation,money,account.GetBalance());
	account.GetLogManage().AddRecord(newAccount);
	return true;
}

int AccountManage::GetSizeOfAccountList()
{
	return this->m_AccountList.size();
}


AccountList &AccountManage::GetAccountList()
{
	return this->m_AccountList;
}


/**************************�ļ�����******************************/
//���˻��ļ�����
bool AccountManage::OpenAccountFile(fstream &file,const char *accountFileName,int mode)
{
	file.open(accountFileName,(std::_Ios_Openmode)mode);//ios::out|ios::in|ios::binary);//|ios::_Nocreate);
	if(!file)
		throw *(new OpenFileException("Default Accout Data File dosn't exist, Create Now?!Y(1)N(0)"));
	return true;
	
}

//�ر��˻��ļ�����
bool AccountManage::CloseAccountFile(fstream &file)
{
	if(!file)
		//throw *(new CloseFileException("�ļ���δ�򿪣����ȴ��ļ���"));
		throw *(new CloseFileException("File is Closed, Open it first!"));
	file.close();
	return true;
}

//�����˻��б���
void AccountManage::ReadAccoutList(fstream &file)
{
	//����б��Է��ظ����룡
	this->m_AccountList.clear();
	Account *sum,*tempAccount;
	sum=new Account();
	file.seekp(0, ios::beg);
	file>>(*sum);

	//����PutAccount()�ķ���������sum��Balance�洢�����е����ʣ��˴��ָ�
	Account::ModifyInterestRate(sum->GetBalance());	
	for(int i=1;i<=sum->GetIDNumber();i++)
	{	
		//char temp[20];
		tempAccount=new Account();
		file.seekp(sizeof(AccountStruct)*i, ios::beg);
		file>>(*tempAccount);		
		this->m_AccountList.push_back(*tempAccount);
	}
}

//д���˻��б���
void AccountManage::PutAccountList(fstream &file)
{		
	//Ϊ�˱��ڲ���������������һ���˻�sum���ڴ洢�˻������Լ����е�������Ϣ���Ӷ������ļ����루��ReadAccoutList��
	Account sum("sum",					//AccountName����Ϊsum
		this->m_AccountList.size(),		//IDNumber����Ϊm_AccountList�Ĵ�С����Ϊ�˻�����
		Account::GetAnnualInterestRate(),							//Balance����Ϊ������
		0,
		0.0);
	Account temp;
	file<<sum;

	for (this->m_AccountListIterator=this->m_AccountList.begin();
			this->m_AccountListIterator!=this->m_AccountList.end();
				this->m_AccountListIterator++)
	{
		temp=(*this->m_AccountListIterator);
		file<<temp;//(*this->m_AccountListIterator);
	}
}
