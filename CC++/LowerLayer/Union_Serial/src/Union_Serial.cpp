//============================================================================
// Name        : Union.cpp
// Author      : ty
// Version     :1.0
// Description :  ʹ��Union�ṹ���еĴ���ͨ�����ݽṹ�����������ݴ��䡣
//============================================================================

#include <iostream>
using namespace std;

union sdata
{
	float fdata;
	struct
	{
		unsigned char b1,b2,b3,b4;
	}bdata;
};


int main()
{
	sdata serial;
	serial.fdata=3.14159;
	float fserial;
	unsigned char * pdata=&serial.bdata.b1;
	fserial=*(float *)pdata;
	cout<<"ת����Ľ��Ϊ��"<<endl;
	cout<<fserial<<endl;

	char ch_flo[4];
	ch_flo[0] = serial.bdata.b1;
	ch_flo[1] = serial.bdata.b2;
	ch_flo[2] = serial.bdata.b3;
	ch_flo[3] = serial.bdata.b4;

	float * pflo = (float *)ch_flo;
	cout<<"ת�����Ϊ��"<<endl;
	cout<<*pflo<<endl;
	return 0;
}




















