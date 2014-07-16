//============================================================================
// Name        : Serial.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : C++ Linux 串行通信程序
//============================================================================
#include <unistd.h> /*linux标准函数定义*/
#include <assert.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> /*文件控制定义*/
#include <termios.h> /*POSIX终端控制定义*/

#include <stdlib.h>
#include <iostream>
using namespace std;

#define	COM1_Str	"/dev/ttyS0"

//#define	COM1_Str	"/dev/pts/5"

int 	Com1_Open();
void 	Com1_Init();
void 	Com1_Close(int com1);

int main()
{
//	const char *COM1 =
//	char buf[512];
	int com1=Com1_Open();
	//while(1)
	//{
	//	write(com1,"ttt",10);
		//read(com1,buf,512);
	//}
	sleep(5);

	Com1_Close(com1);
	return 0;
}

int Com1_Open()
{
	int com1 = open(COM1_Str,O_RDWR);
	if (com1==-1)
	{
		cout<<"Can't Open Serial Port!\n";
		//错误退出
		exit(-1);
	}
	cout<<"Open Seccessfully"<<endl;
	return com1;
}
void Com1_Init()
{
//此处书写串口初始化代码
}
void Com1_Close(int com1)
{
	int com_1=close(com1);
	if(com_1==-1)
	{
		cout<<"Close com1 error"<<endl;
		exit(-1);
	}
	cout<<"com1 closed"<<endl;
}


























