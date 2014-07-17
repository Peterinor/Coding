//============================================================================
// Name        : time.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : 用于时间函数的测试项目
//============================================================================

#include"../includes/includes.h"

void test_function()
{
	unsigned int i,j;
	double y;
	for(i=0;i<5000;i++)
	for(j=0;j<5000;j++)
	y=sin((double)i);
}
int ymain()
{
	struct timeval tpstart,tpend;
	float timeuse;

	gettimeofday(&tpstart,NULL);
	test_function();
	gettimeofday(&tpend,NULL);

	timeuse=1000000*(tpend.tv_sec-tpstart.tv_sec)+tpend.tv_usec-tpstart.tv_usec;
	timeuse/=1000000;

	cout<<"Used Time:"<<timeuse<<" s"<<endl;

	return 0;
}
