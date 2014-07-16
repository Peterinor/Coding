/*
 ============================================================================
 Name        : C_StdLib.c
 Author      : ty
 Version     : 1.0
 Copyright   : copyright reserved of ty
 Description : C 标准库联系, Ansi-style
 ============================================================================
 */

//#include"../../C_includes.h"
#include <stdio.h>

int stdiomain(void)
{
	/*2011-4-13日，晚20：20，C标准输入输出库练习，添加头文件stdio.h*/
	/*但是此处测试了的，好像即使不添加stdio.h也不会出现错误，由此看来gcc是默认加入标准输入输出函数库的*/
	/*但这个样子会有类似implicit declaration of function ‘puts’的警告，意思就是说编译时没有找到puts函数
	 *而编译器把他们当成是隐式函数声明(没有定义返回值),但是由于连接器在链接的时候会自动链接标准输入输出库，又可以
	 *找到puts函数，因而链接和运行都不会出错！！---------------参见头文件中关于库的访问说明
	 *因此，为了程序的稳定性和最大移植性最好还是包含头文件！！
	 */

	/****************************************************输出函数****************************************************/
	/*
	 *	puts()  该函数会在字符串结束之后自动添加换行！
	 *	库注释	Write a string, followed by a newline, to stdout.
	 */
	puts("Hello!");
	puts("Hello again\n");
	puts("Hello Come again now!");
	puts("Hello!");

	/*
	 * putchar()
	 * 库注释	Write a character to stdout.
	 */
	putchar('a');
	putchar('\n');

	putchar('bcd');		//值为d
	putchar('\n');

	putchar("bcd");		//访问的是字符串的地址//不过多做几次测验之后感觉这是乱的
	putchar('\n');
	putchar('\n');

	char ch='abcde';	//值为e
	putchar(ch);

	putchar('\n');

	/*
	 * printf()
	 * 库注释	Write formatted output to stdout.
	 */
	/*整数格式控制d--10进制	x/X--无符号16进制	o--8无符号进制*/
	printf("%d   %x   %X   %o  \n",10,10,10,10);
	/*u--无符号整数	i--有符号整数(和d一样)*/
	int idata=4294967295;	//4294967295=0xFFFFFFFF
	printf("%d   %i   %u\n",idata,idata,idata);

	/*浮点数格式控制e/E--科学计数法表示浮点数		f--十进制浮点数	g/G自动选择浮点数输出格式*/
	float fdata=115.134521;
	printf("%f   %e   %E   %g   %G\n",fdata,fdata,fdata,fdata,fdata);
	fdata=0.000001;
	printf("%f   %e   %E   %g   %G\n",fdata,fdata,fdata,fdata,fdata);
	/*a/A--浮点数 十六进制数 p-计数法*/
	fdata=10.0;
	printf("%a  %A\n",fdata,fdata);

	/*字符(串)格式控制，s--输出以'\0'结尾的字符串， c--输出一个字符*/
	printf("%s = %c\n","tangyu",'t');
	printf("%s = %c\n","tangyu",'ty');

	/*指针输出 p*/
	//.......

	/*关于输出精度控制*/
	printf("%d%d\n",10,10);
	printf("%8d%8d\n",10,10);
	printf("%f%f\n",10.0,10.0);
	printf("%8.4f%8.4f\n",10.0,10.0);

	/*************************************************************************************************
	 * 其实，在头文件stdio.h中经常会看到诸如Write xx to STREAM/stdout 或者 Read xx from STREAM/stdin
	 * 而这里的STREAM其实就是FILE*，也就是说，在Linux C中只有两种输入输出(不论有多少设备，统统都归到FILE结构体系中)
	 * 其实就连stdout和stdin也都是FILE，下面的gets()就用到了
	 *************************************************************************************************
	 */


	/****************************************************输入函数****************************************************/
	char buf[10];
	/*
	 * gets
	 *库注释	Get a newline-terminated string from stdin, removing the newline.  DO NOT USE THIS FUNCTION!!
	 *		There is no limit on how much it will read.
	 */
	puts(gets(buf));		//----警告！！
	puts(fgets(buf,10,stdin));	//针对上一问题的解决方法！！
	/*
	 * getchar()
	 *库注释		Read a character from stdin.
	 */
	putchar(getchar());
	putchar('\n');putchar('\n');

	//同样的，验证可输出
	fprintf(stdout,"%s = %c\n","tangyu",'t');



	return 0;
}

