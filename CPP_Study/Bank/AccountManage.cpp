#include "AccountManage.h"

#include "Exception.h"
#include "LogRecord.h"

AccountManage::AccountManage(void)
{
}

AccountManage::~AccountManage(void)
{
}

//添加账户
bool AccountManage::NewAccount()
{
	Account *addAccount=new Account();
	cout<<"Now Adding An Account,Please Follow The Information!"<<endl;
	//cout<<"添加账户,输入以下信息！"<<endl;
	addAccount->SetAccountInf();

	addAccount->SetIDNumber(this->m_AccountList.size()+20100001);
	this->m_AccountList.push_back(*addAccount);
		
	if(this->m_AccountList[this->m_AccountList.size()-1]==*addAccount)
	{
		cout<<"Add successfully!"<<endl;
		//cout<<"成功添加!"<<endl;
		LogRecord newAccount(*(new DateTime()),NEWACCOUNT,addAccount->GetBalance(),addAccount->GetBalance());
		this->m_AccountList[this->m_AccountList.size()-1].GetLogManage().AddRecord(newAccount);
		return true;
	}
	else
	{
		cout<<"Error! Fail to Add"<<endl;
		//cout<<"发生错误! 添加失败"<<endl;
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
	cout<<"Please Input The ID_Number of the Accout！"<<endl;
	//cout<<"请输入账户的ID号！"<<endl;
	
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
//	throw *(new NoFoundException("没有找到该账户，请确认输入信息，并重新输入！"));//\n输入用户ID号(若输入0则返回操作)："));
}


bool AccountManage::DeleteAccount()
{
	if(this->m_AccountList.size()==0)
	{
		cout<<"No a sigle Account!"<<endl;
//		cout<<"目前没有任何一个用户！"<<endl;
		return false;
	}
//	cout<<"Input the IDNumber of The Account You Want To Delete!"<<endl
//		<<"IDNumber : ";
	//cout<<"输入要删除账号的ID号!"<<endl
	//	<<"ID号码 : ";
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
			//cout<<"目前没有任何一个用户可操作！"<<endl;//cout<<"NO Matech Account Found ! Fail to Delete!"<<endl;
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
		//cout<<"目前没有任何一个用户可操作！"<<endl;
		cout<<"No Account to Operate now!"<<endl;
		return false;
	}
	
//	cout<<"输入要操作的账号的ID号!ID号位20100000与账号排序的和，如20100001"<<endl
	cout<<"Input the ID_Number of the Account, Such as 20100001"<<endl
		<<"ID_Number: ";
	
	cin>>IDNumber;

	this->SearchAccount(IDNumber);			
	
	this->m_ResultAccount.Display();

	while(BackOrGo)
	{	
		system("clear");
		this->m_ResultAccount.Display();
	/*	cout<<"请选择操作类型!"<<endl
			<<"(1)存款\n(2)取款\n(3)查询余额\n(4)查看操作记录\n(5)显示账户全部信息\n"
			"(6)修改账户信息\n(7)查看账户权限\n(8)设定账户权限\n(0)返回"<<endl;*/
		cout<<"Choose the Operate!"<<endl
			<<"(1)存款\n(2)取款\n(3)查询余额\n(4)查看操作记录\n(5)显示账户全部信息\n"
			"(6)修改账户信息\n(7)查看账户权限\n(8)设定账户权限\n(0)Back"<<endl;

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
		
		cout<<"\n操作完成，返回(0) 还是对该账户继续进行操作(1)!"<<endl;
		cin>>BackOrGo;
	}
	return true;
}


bool AccountManage::OperateAnAccount(int operation ,Account &account)
{
	int money=0;

	switch(operation)
	{
	case DEPOSITE:			//存款
//		cout<<"Input the Cash Number you want to deposite!"<<endl
//			<<"Cash amount : ";
		cout<<"输入存款金额!"<<endl
			<<"存款金额 : ";
		cin>>money;
		if(!account.Deposit(money))
			return false;
		break;
	case DRAWMONEY:			//取款
//		cout<<"Input the Cash Number you want to get!"<<endl
//			<<"Cash amount : ";
		cout<<"输入取款金额!"<<endl
			<<"取款金额 :  ";
		cin>>money;
		if(!account.DrawMoney(money))
			return false;
		break;
	case GETBALANCE:		//查询余额
		cout<<"账户余额为："<<account.GetBalance()<<endl;
		break;
	case CHECKRECORD:		//查看操作记录
		account.CheckRecord();
		return true;
	case DISPLAY:			//显示账户全部信息
		account.Display();
		break;
	case MODIFYINF:			//修改账户信息
		account.ModifyInf();
		break;
	case CHECKAUTHORITY:
		account.CheckAuthority();
		break;
	case SETAUTHORITY:
		account.SetAuthority();
		break;
	case BACK:				//返回	
		return true;
	default:
		cout<<"输入错误！请重新输入！"<<endl;
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


/**************************文件操作******************************/
//打开账户文件函数
bool AccountManage::OpenAccountFile(fstream &file,const char *accountFileName,int mode)
{
	file.open(accountFileName,(std::_Ios_Openmode)mode);//ios::out|ios::in|ios::binary);//|ios::_Nocreate);
	if(!file)
		throw *(new OpenFileException("Default Accout Data File dosn't exist, Create Now?!Y(1)N(0)"));
	return true;
	
}

//关闭账户文件函数
bool AccountManage::CloseAccountFile(fstream &file)
{
	if(!file)
		//throw *(new CloseFileException("文件尚未打开，请先打开文件！"));
		throw *(new CloseFileException("File is Closed, Open it first!"));
	file.close();
	return true;
}

//读入账户列表函数
void AccountManage::ReadAccoutList(fstream &file)
{
	//清空列表，以防重复载入！
	this->m_AccountList.clear();
	Account *sum,*tempAccount;
	sum=new Account();
	file.seekp(0, ios::beg);
	file>>(*sum);

	//根据PutAccount()的方法，这里sum的Balance存储了银行的利率，此处恢复
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

//写出账户列表函数
void AccountManage::PutAccountList(fstream &file)
{		
	//为了便于操作，这里虚设了一个账户sum用于存储账户总数以及银行的其他信息，从而便于文件读入（见ReadAccoutList）
	Account sum("sum",					//AccountName这里为sum
		this->m_AccountList.size(),		//IDNumber这里为m_AccountList的大小，即为账户总数
		Account::GetAnnualInterestRate(),							//Balance这里为年利率
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
