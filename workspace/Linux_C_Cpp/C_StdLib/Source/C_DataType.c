
//#include"../../C_includes.h"
#include <stdio.h>

int typemain(void)
{
	/****************************************整型****************************************************/
	printf("\n*******************************************************************************\n");
	signed int sidata;
	unsigned int uidata;

	sidata=0;
	uidata=0;
	printf("%d,%u\n",sidata,uidata);
	sidata=0xff;
	uidata=0xff;
	printf("%d,%u\n",sidata,uidata);
	sidata=0xffff;
	uidata=0xffff;
	printf("%d,%u\n",sidata,uidata);
	sidata=0xffffffff;
	uidata=0xffffffff;
	printf("%d,%u\n",sidata,uidata);	//--->Linux C中int位32位
	//或者直接
	printf("sizeof int :%d\n",8*sizeof(int));
	printf("sizeof shot int :%d\n",8*sizeof(short int));
	printf("sizeof long :%d\n",8*sizeof(long));			//long为32位！！
	printf("sizeof long long:%d\n",8*sizeof(long long));//long long 才是64位！！
//同理
	/***************************************浮点型****************************************************/
	printf("\n*******************************************************************************\n");
	float fdata;
	printf("sizeof float :%d\n",8*sizeof(float));
	double ddata;
	printf("sizeof double :%d\n",8*sizeof(double));
	printf("sizeof long double :%d\n",8*sizeof(long double));	//96位，不是128位！！
	printf("sizeof char :%d\n",8*sizeof(char));
	//printf("sizeof wchar_t :%d\n",8*sizeof(wchar_t));	可以看到，在c中是不支持wchar_t的，他其实就是int的宏定义

	sidata=15;
	uidata=sidata;		//编译器没有警告！！没有出现问题
	printf("sidata = %d, uidata = %u\n",sidata,uidata);

	sidata=0xffffffff;	//编译器没有警告！！
	uidata=sidata;		//出现问题了，编译器还是没有警告！！--->对于C的这种强大的灵活性要靠自己甄别！！
	printf("sidata = %d, uidata = %u\n",sidata,uidata);

	//不会出现问题，没有警告
	fdata=uidata;
	printf("fdata = %f\n",fdata);

	ddata=uidata;
	printf("dddata = %f\n",ddata);

	//没有警告
	fdata=50.016;
	ddata=67.854;
	sidata=fdata;
	uidata=ddata;
	printf("sidata = %d, uidata = %u\n",sidata,uidata);

	/****************************************字符型****************************************************/
	printf("\n*******************************************************************************\n");
	char ch='a';
	printf("ch = %c\n",ch);
	ch=sidata;				//没有警告
	printf("ch = %c\n",ch);
	ch=uidata;				//没有警告
	printf("ch = %d\n",ch);

	ch=255;
	printf("ch = %d\n",ch);		//输出-1，克制此处char位有符号的，位增强程序移植性可强制指定unsigned

	unsigned char uch=255;
	printf("uch = %d\n",uch);
	//sizeof(wchar_t);			//wchar_t 在linux C中并不是关键字，其实是#define wchar_t int在stddef.h中定义
#include <stddef.h>
	wchar_t wch='a';
	printf("size of wch is: %d\n",8*sizeof(wch));	//输出4

	/****************************************布尔型****************************************************/
	printf("\n******************************************************************************\n");
//bool	注意C的布尔型不是bool，而是_Bool，但是可以包含头文件stdbool使用和C++兼容的bool
	_Bool istrue=15;					//在C中没有true和false，非0即真
	printf("size of _Bool : %d\n",8*sizeof(_Bool));		//输出8位，也就是说_Bool其实就是char
	printf("bistrue = %d\n",istrue);

#include <stdbool.h>
	bool bistrue=true;
	printf("size of bool : %d\n",8*sizeof(bool));		//输出8位，也就是说bool其实就是char，其实#define bool _Bool
	printf("istrue = %d\n",bistrue);


	/********************************复数类型************************************/
	printf("\n*******************************************************************************\n");
//	搞了了半天还是没能搞清楚这个是怎么用的！！
	_Complex c=2;//+50*I;
	printf("c = %4.2f  %4.2f\n",c);

#include <complex.h>
	complex cc=2+5*I;
	printf("size of complex is:%d\n",8*sizeof(complex));		//输出128，也就是说complex高64位存放..低64位存放..
	printf("cc = %f + %fi\n",cc);		//从这里也可以看出来，printf函数其实使用的好像是
	printf("cc = %f + %fi\n",cc,cc);

	float cc_real=cc;
	printf("cc_real  = %f\n",cc_real);		//-------------------->高64位存放虚数低64位存放实部
	float cc_image=*((double*)(((char *)(&cc)+8)));
	printf("cc_image = %f\n",cc_image);


	/**************************************字符串****************************************************/
	printf("\n*******************************************************************************\n");
	char * str="tangyu";
	printf("%s\n",str);
	char astr[20]="tangyu";
	printf("%s\n",astr);
	char aastr[20]={'t','a','n','g','y','u'};
	printf("%s\n",aastr);			//-------------->此处竟然没有执行错误，可能是编译器的处理

	printf("%s\n",&str);	//不正常，错误
	printf("%s\n",&astr);	//正常
	printf("%s\n",&aastr);	//正常	---->说明：&arr--->arr;arr--->arr[0]，这是对于数组而言的，而对于字符指针则不会


	/**扩充型**/
	printf("\n*******************************************************************************\n");
#include <stdint.h>
	int8_t i8ch='a';
	printf("i8ch = %c\n",i8ch);
	int16_t i16data=15;
	printf("size of int16_t is:%d\n",8*sizeof(i16data));
	int32_t i32data=15;
	printf("size of int32_t is:%d\n",8*sizeof(i32data));
	int64_t i64data=15;
	printf("size of int64_t is:%d\n",8*sizeof(i64data));
	intmax_t imaxdata=15;
	printf("size of intmax_t is:%d\n",8*sizeof(imaxdata));		//整型最大位64位！！
	printf("int max value is: %u",INTMAX_MAX);
	///...................




	/***********************************类型判断函数*******************************************************/
	printf("\n*******************************************************************************\n");
#include <ctype.h>
	char bch='6';
	bch='\a';
	printf("iscntrl :%d\n",iscntrl(bch));			//输出2
	bch='\n';
	printf("iscntrl :%d\n",iscntrl(bch));
	bch='\t';
	printf("iscntrl :%d\n",iscntrl(bch));
	bch=' ';
	printf("iscntrl :%d\n",iscntrl(bch));

	bch='6';
	printf("isalnum :%d\n",isalnum(bch));		//输出8 ！！？？
	bch='\n';
	printf("isalnum :%d\n",isalnum(bch));		//输出0

	bch='A';
	printf("isupper :%d\n",isupper(bch));			//256
	bch='a';
	printf("isupper :%d\n",isupper(bch));

	bch='a';
	printf("islower :%d\n",islower(bch));			//512
	bch='A';
	printf("islower :%d\n",islower(bch));

	/*字母*/
	bch='a';
	printf("isalpha :%d\n",isalpha(bch));		//输出1024 ！！？？
	bch='6';
	printf("isalpha :%d\n",isalpha(bch));

	/*数字*/
	bch='6';
	printf("isdigital :%d\n",isdigit(bch));		//输出2048 ！！？？
	bch='a';
	printf("isdigital :%d\n",isdigit(bch));

	/*16进制数字*/
	bch='6';
	printf("isxdigital :%d\n",isxdigit(bch));		//输出4096 ！！？？
	bch='a';
	printf("isxdigital :%d\n",isxdigit(bch));		//输出4096 ！！？？
	bch='h';
	printf("isxdigital :%d\n",isdigit(bch));

	/*空格，保括'\n'  '\t'  ' '*/
	bch=' ';
	printf("isspace :%d\n",isspace(bch));			//输出8192=8*1024
	bch='\n';
	printf("isspace :%d\n",isspace(bch));
	bch='\t';
	printf("isspace :%d\n",isspace(bch));
	bch='\a';
	printf("isspace :%d\n",isspace(bch));

	/*可打印字符，包括空格*/
	bch=' ';
	printf("isprint :%d\n",isprint(bch));			//输出16384=16*1024
	bch='\n';
	printf("isprint :%d\n",isprint(bch));

	/*可打印字符，不包括空格*/
	bch='a';
	printf("isgraph :%d\n",isgraph(bch));			//输出32768=32*1024
	bch=' ';
	printf("isgraph :%d\n",isgraph(bch));

	/*标点符号*/
	bch=',';
	printf("ispunct :%d\n",ispunct(bch));			//输出4
	bch=' ';
	printf("ispunct :%d\n",ispunct(bch));
/*
 * 由上面的过程可以看出，这些类型判断函数结果为真时返回的都不是1，着在应用是切记注意！！
 */




	return 0;
}
