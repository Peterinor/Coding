/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.h
 *Copyight	:Copyight Reserved by ty
 *Version	:0.2
 *Date		:2011-4-2
 *Describ	:实现对Hex文件数据的提取
 *			 对实现Hex数据提取需要相关类型声明
 ********************************************************************
 */

#include"includes.h"

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
#define HP_TYPE		1
#define HP_CHSUM	0




/*
 * Hex文件的行记录数据结构，编译操作
 */
typedef struct hex_Rec
{
	unsigned int 	byte_count;		//数据长度
	unsigned int 	address;		//数据地址
	//Hex行记录数据类型标志常量定义
	enum Record_Type		//记录类型
	{
		H_ERR=-1,			//错误记录，根据程序的需要认为添加的一个校验数据
		H_DATA=0,				//数据记录			(0x00)---->8、16、32位用
		H_EOF=1,				//文件结束记录		(0x01)---->8、16、32位用
	}	rec_type;			//数据类型
	unsigned char 	*pdata;			//数据数组
	unsigned int 	chechsum;		//校验和

}Hex,*pHex;


/*
 * 打印hex数据，并且返回数据记录是否已到数据尾部
 * 若到数据尾部则返回true，否则返回false
 */
_Bool show_Hex(Hex rec);

#define char_to_int_gap	48	//0x30

/*
 * 从字符串line中获取hex数据
 * 这里的line也就是hex文件中的一行字符
 */
Hex get_Data_Str(const char * line);

/*
 * 打印hexfile
 * 输出hex_file为文件名的hex文件，无返回类型
 */
void print_Hex(char* hex_file);

/*
 * 将一个字母转换为一个十六进制的数字
 * 返回转换后的数字
 */
int get_Num(char ch);

/*
 * 测试函数，不用
 */
void test();
