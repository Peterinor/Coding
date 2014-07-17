/*
 ============================================================================
 Name        : C_StdLib.c
 Author      : ty
 Version     : 1.0
 Copyright   : copyright reserved of ty
 Description : C ��׼����ϵ, Ansi-style
 ============================================================================
 */

//#include"../../C_includes.h"
#include <stdio.h>

int stdiomain(void)
{
	/*2011-4-13�գ���20��20��C��׼�����������ϰ�����ͷ�ļ�stdio.h*/
	/*���Ǵ˴������˵ģ�����ʹ�����stdio.hҲ������ִ����ɴ˿���gcc��Ĭ�ϼ����׼��������������*/
	/*��������ӻ�������implicit declaration of function ��puts���ľ��棬��˼����˵����ʱû���ҵ�puts����
	 *�������������ǵ�������ʽ��������(û�ж��巵��ֵ),�������������������ӵ�ʱ����Զ����ӱ�׼��������⣬�ֿ���
	 *�ҵ�puts������������Ӻ����ж����������---------------�μ�ͷ�ļ��й��ڿ�ķ���˵��
	 *��ˣ�Ϊ�˳�����ȶ��Ժ������ֲ����û��ǰ���ͷ�ļ�����
	 */

	/****************************************************�������****************************************************/
	/*
	 *	puts()  �ú��������ַ�������֮���Զ���ӻ��У�
	 *	��ע��	Write a string, followed by a newline, to stdout.
	 */
	puts("Hello!");
	puts("Hello again\n");
	puts("Hello Come again now!");
	puts("Hello!");

	/*
	 * putchar()
	 * ��ע��	Write a character to stdout.
	 */
	putchar('a');
	putchar('\n');

	putchar('bcd');		//ֵΪd
	putchar('\n');

	putchar("bcd");		//���ʵ����ַ����ĵ�ַ//�����������β���֮��о������ҵ�
	putchar('\n');
	putchar('\n');

	char ch='abcde';	//ֵΪe
	putchar(ch);

	putchar('\n');

	/*
	 * printf()
	 * ��ע��	Write formatted output to stdout.
	 */
	/*������ʽ����d--10����	x/X--�޷���16����	o--8�޷��Ž���*/
	printf("%d   %x   %X   %o  \n",10,10,10,10);
	/*u--�޷�������	i--�з�������(��dһ��)*/
	int idata=4294967295;	//4294967295=0xFFFFFFFF
	printf("%d   %i   %u\n",idata,idata,idata);

	/*��������ʽ����e/E--��ѧ��������ʾ������		f--ʮ���Ƹ�����	g/G�Զ�ѡ�񸡵��������ʽ*/
	float fdata=115.134521;
	printf("%f   %e   %E   %g   %G\n",fdata,fdata,fdata,fdata,fdata);
	fdata=0.000001;
	printf("%f   %e   %E   %g   %G\n",fdata,fdata,fdata,fdata,fdata);
	/*a/A--������ ʮ�������� p-������*/
	fdata=10.0;
	printf("%a  %A\n",fdata,fdata);

	/*�ַ�(��)��ʽ���ƣ�s--�����'\0'��β���ַ����� c--���һ���ַ�*/
	printf("%s = %c\n","tangyu",'t');
	printf("%s = %c\n","tangyu",'ty');

	/*ָ����� p*/
	//.......

	/*����������ȿ���*/
	printf("%d%d\n",10,10);
	printf("%8d%8d\n",10,10);
	printf("%f%f\n",10.0,10.0);
	printf("%8.4f%8.4f\n",10.0,10.0);

	/*************************************************************************************************
	 * ��ʵ����ͷ�ļ�stdio.h�о����ῴ������Write xx to STREAM/stdout ���� Read xx from STREAM/stdin
	 * �������STREAM��ʵ����FILE*��Ҳ����˵����Linux C��ֻ�������������(�����ж����豸��ͳͳ���鵽FILE�ṹ��ϵ��)
	 * ��ʵ����stdout��stdinҲ����FILE�������gets()���õ���
	 *************************************************************************************************
	 */


	/****************************************************���뺯��****************************************************/
	char buf[10];
	/*
	 * gets
	 *��ע��	Get a newline-terminated string from stdin, removing the newline.  DO NOT USE THIS FUNCTION!!
	 *		There is no limit on how much it will read.
	 */
	puts(gets(buf));		//----���棡��
	puts(fgets(buf,10,stdin));	//�����һ����Ľ����������
	/*
	 * getchar()
	 *��ע��		Read a character from stdin.
	 */
	putchar(getchar());
	putchar('\n');putchar('\n');

	//ͬ���ģ���֤�����
	fprintf(stdout,"%s = %c\n","tangyu",'t');



	return 0;
}

