/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.h
 *Copyight	:Copyight Reserved by ty
 *Version	:0.3
 *Date		:2011-4-4
 *Describ	:实现对Hex文件数据的提取
 *			 使用c++类实现算法并且实现文件分离
 ********************************************************************
 */

#ifndef _HEXDATA_H_
#define _HEXDATA_H_

#include"../../includes.h"

//定义Hex文件的行起始字符
#define Start_Code	':'

//设置十六进制的数据输出格式
#define Hex_Print 1

#if 	Hex_Print
#define	_hex_	hex
#define _0x_		"0x"
#else
#define	_hex_	""
#define _0x_ 	""
#endif


//定义打印标志
#define HP_ADD		1
#define HP_DATA		1
#define HP_COUNT	1
#define HP_TYPE		0
#define HP_CHSUM	0

/*
 * Hex类声明
 */

class Hex
{
public:
	Hex();
	Hex(string data);
	Hex(char *data );

	void GetDataStr(char * line);

	bool Show();
	virtual ~Hex();

//数据应该使用什么样的限定，个人觉得应该根据实际应用的方便而定，也就是说使用public限定
//private:
public:
	/*
	 * Hex文件的行记录数据，编译操作
	 */
	unsigned int 	byte_count;		//数据长度
	unsigned int 	address;		//数据地址
//	Record_Type 	rec_type;		//数据类型
	unsigned char 	*pdata;			//数据数组
	unsigned int 	chechsum;		//校验和

	/*
	 * Hex行记录数据类型标志常量定义
	 */
	enum Record_Type		//记录类型
	{
		H_ERR=-1,			//错误记录，根据程序的需要认为添加的一个校验数据
		H_DATA,				//数据记录			(0x00)---->8、16、32位用
		H_EOF,				//文件结束记录		(0x01)---->8、16、32位用
		//下面的数据在8位机器中不会用到，考虑完整性将其加上
		H_ESAR,				//扩展存储段地址记录	(0x02)---->16、32位用
		H_SSAR,				//起始段地址记录		(0x03)---->16、32位用
		H_ELAR,				//扩展线性地址记录		(0x04)---->32位专用
		H_SLAR				//起始线性地址记录		(0x04)---->32位专用
	} rec_type;
};


/*********************************************************
 * 辅助函数声明
 *********************************************************/
/*
 * 将一个字母转换为一个十六进制的数字
 * 返回转换后的数字
 */
int get_Num(char ch);



#endif /* HEXDATA_H_ */
