//============================================================================
// Name        : Union.cpp
// Author      : ty
// Version     :1.0
// Description :  使用Union结构进行的串行通信数据结构，更方便数据传输。
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
	cout<<"转换后的结果为："<<endl;
	cout<<fserial<<endl;

	char ch_flo[4];
	ch_flo[0] = serial.bdata.b1;
	ch_flo[1] = serial.bdata.b2;
	ch_flo[2] = serial.bdata.b3;
	ch_flo[3] = serial.bdata.b4;

	float * pflo = (float *)ch_flo;
	cout<<"转换结果为："<<endl;
	cout<<*pflo<<endl;
	return 0;
}




















