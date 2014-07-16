#ifndef _DEFINE_H_
#define _DEFINE_H_
//本文件用于定义同意的操作宏定义以及一些同意的常量等，主要用于控制台应用程序使用！

//定义账户类型
#define VIPACCOUNT		1
#define COMMOMACCOUNT	0


//定义操作类型
#define EXIT			0	//退出
#define BACK			0	//返回

#define DEPOSITE		1	//存款
#define DRAWMONEY		2	//取款
#define	GETBALANCE		3	//查询余额
#define	CHECKRECORD		4	//查看操作记录
#define DISPLAY			5	//显示账户全部信息
#define	MODIFYINF		6	//修改账户信息
#define CHECKAUTHORITY  7	//查看账户权限Authority
#define SETAUTHORITY	8	//设定账户权限


#define NEWACCOUNT		10	//创建新账户
#define	OPERATEACCOUNT	20	//操作账户
#define SHOWALLACCOUNT	30	//显示所有用户
#define	DELETEACCOUNT	40	//销户
#define CHANGERATE		50	//更改年利率

struct AccountStruct
{
	char Name[20];
	char IDNumber[10];
	int AccountType;
	double Balance;
	double OverDraw;
	void Show();
};



/*
#include"AccountManage.h"
#include"VipAccount.h"
#include"LogRecord.h"
#include"DateTime.h"
#include"Account.h"
#include"Bank.h"
#include"Bank.h"

#include<vector>
#include<iostream>
#include<string>

using namespace std;
*/

char * itoa ( int value, char * str, int base=10);






#endif

#include"Exception.h"
