//============================================================================
// Name        : test_pr.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : ���ڸ��ֺ����Ĳ�����Ŀ
//============================================================================

#include"../includes/includes.h"

int xmain()
{
	time_t tm;
	tm=time(&tm);
	cout<<"����ʱ�䣺"<<endl;
	cout<<ctime(&tm)<<endl;

	return 0;
}
