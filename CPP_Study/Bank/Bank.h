//#pragma once
#ifndef _BANK_H_
#define _BANK_H_
#include"define.h"

#include"AccountManage.h"

using namespace std;

class Bank
{
public:

	//运行程序的函数，即银行开始上班了！实例化manage并运行之,即：“银行开始上班”,这里包含了主程序几乎所有的代码！
	void Run();

	//"银行下班"
	void Exit();

	//加载账户信息
	void LoadAccount();

	//卸载账户信息
	void UnLoadAccount();

	//写入账户信息
	bool WriteAccount();

	//默认构造函数，账户文件名为account.dat
	Bank(void);
	//带参构造函数，账户文件名为fileName
	Bank(const char *fileName);
	Bank(string filename);
	~Bank(void);
private:
	//银行初始化
	void Init();
	//银行LOGO
	void Logo();

private:
	AccountManage m_Manage;
	//可能还有其他的管理员，此处不需要！

	string m_AccountFileName;

	fstream m_AccountFile;

	int TotalAccountNumber;

};

#endif
