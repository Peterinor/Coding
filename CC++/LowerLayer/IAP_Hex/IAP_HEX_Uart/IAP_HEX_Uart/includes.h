#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include<iostream>
#include<string>
#include<fstream>

#include<cstring>

#include<cctype>

#include<cstdlib>


using namespace std;


#include"CSerial/Serial.h"

#pragma comment(lib,"../Release/CSerial.lib")

#undef _UNICODE

#define work_Path "D:/bark_up/php/www.tangyu.com/IAP_Hex"

//定义传输标志信息
enum S_Mark
{	
	S_BEGIN		=	0xff,		//主机数据传送请求标志	
	S_END		=	0xfe,		//主机数据记录传送结束标志
	S_DATA_OK	=	0xfd,		//主机检查数据正确无误确认标志
	S_OVER		=	0xff,		//主机数据发送完毕标志
	S_ANS		=	0xfb		//从机应答标志
	//S_ADD		=	-4,			//主机发送地址数据标志
	//S_BYTE	=	-5,			//主机发送字节数标志
	//S_DATA	=	-6,			//主机放松数据标志
	//S_GET		=	-8,			//从机收到数据后应答
	
};

/*
**通行协议(1)：
**Hex记录发送其标志S_BEGIN(-1)，主机不停的发送S_BEGIN请求发送数据，
**直到从机应答S_ANS(-5)，主机开始发送地址数据标志S_ADD，从机收到后
**同样应答S_ANS，然后主机开始发送两字节地址数据
*/


/*
**通行协议(2)：
**Hex记录发送其标志S_BEGIN(-1)，主机不停的发送S_BEGIN请求发送数据，
**直到从机应答S_ANS(-5)，主机开始发送数据记录，依次为-地址-，-数据
**字节数-，-数据-，从机每收到一个字节数据后返回一个应答信号A_ANS。
**主机发送完一个Hex记录后发送S_END标志，从机进入等待状态，等待主机
**回馈信息，也就是是否有数据丢失。由主机根据接收到的从机应答情况确定
**是否有数据丢失和是否需要重发数据记录。若没有数据丢失情况则主机发送
**S_DATA_OK，从机开始写入程序。
*/

#endif