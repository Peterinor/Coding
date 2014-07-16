//#pragma once
#ifndef _ACCOUNTMANAGE_H_
#define _ACCOUNTMANAGE_H_

#include"Account.h"

#include<fstream>
#include<vector>

using namespace std;

typedef vector <Account>	AccountList;

class AccountManage
{
public:
	AccountManage(void);
	~AccountManage(void);

public:
	//新建账户，要添加的账户由管理员输入相关信息构成
	bool NewAccount();
	//新建账户，要添加的账户由参数给出
	bool NewAccount(Account &accountToAdd);

	//删除账户，要删除的用户由管理员输入并由Account SearchAccount()搜索给出
	bool DeleteAccount();
	//删除账户，要删除的账户由参数accountToDelet给出
	bool DeleteAccount(long accountID);

	//搜索账户，要搜索的账户由管理员输入，并将搜索到的结果赋给m_ResultAccount并返回
	Account *SearchAccount();
	//搜索账户，要搜索的账户由参数accountToGet给出，并将搜索到的结果赋给m_ResultAccount并返回
	Account *SearchAccount(long accountID);
	/*以上这两个检索函数虽然不能根据返回结果来判断是否正确检索得到了，但是可以通过检查m_ResultAccount
	的m_IDNumber属性以获得想要信息，因为默认为0。但是将函数改变一下即可得到更好的解决！即返回指针*/

	//显示所有的账户信息
	void ShowAllAccount();
	//获取账户总数目
	int GetSizeOfAccountList();

	//获取账户列表向量
	AccountList &GetAccountList();

	/*对某一个账户进行操作，提示用户输入账号，然后查找，再细化各种
	操作,具体操作见define.h中的定义,操作成功返回true*/
	bool OperateAnAccount(/*int operation*/);
	/*对某账户account进行operation所代表操作,操作成功返回true*/
	bool OperateAnAccount(int operation ,Account &account );


	/**************************文件操作******************************/
	//打开账户文件函数
	bool OpenAccountFile(fstream &file,const char *accountFileName,int mode);

	//关闭账户文件函数
	bool CloseAccountFile(fstream &file);

	//读入账户列表函数
	void ReadAccoutList(fstream &file);

	//写出账户列表函数
	void PutAccountList(fstream &file);

	//
	
	
private:
	AccountList	 m_AccountList;			//账户列表
	Account		 m_ResultAccount;		//检索结果

	AccountList::iterator m_AccountListIterator;		//账户列表迭代器	


};

#endif
