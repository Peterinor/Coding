/*
 ********************************************************************
 *Author	:ty
 *File		:Test.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.1
 *Date		:2011-4-2
 *Describ	:��HexData�Ĳ��Գ���
 ********************************************************************
 */

#include"../includes/HexData.h"

/*
 * ���Ժ���������
 */
void test();

/*
 * �����򣬴�ӡhex�ļ�����
 */
int main()
{
	cout<<"Version 0.2"<<endl;
	print_Hex(hexfile.c_str());

	return 0;
}

string hex_str=":10002E00E0FE1200B5907F13E04402F0AF10EF3304";
/*
 *
 */
void test()
{
	Record_Type a=H_ERR;
	cout<<a<<endl;
	cout<<get_Num('9')<<endl;
	a=(Record_Type)4;
	cout<<a<<endl;
	cout<<hex_str<<endl;
	show_Hex(get_Data_Str(hex_str.c_str()));
}

