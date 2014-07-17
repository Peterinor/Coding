//============================================================================
// Name        : test_pr.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : 用于各种函数的测试项目
//============================================================================

#include"../includes/includes.h"

int xmain()
{
	time_t tm;
	tm=time(&tm);
	cout<<"现在时间："<<endl;
	cout<<ctime(&tm)<<endl;

	return 0;
}
