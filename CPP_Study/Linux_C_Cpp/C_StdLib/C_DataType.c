
//#include"../../C_includes.h"
#include <stdio.h>

int typemain(void)
{
	/****************************************����****************************************************/
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
	printf("%d,%u\n",sidata,uidata);	//--->Linux C��intλ32λ
	//����ֱ��
	printf("sizeof int :%d\n",8*sizeof(int));
	printf("sizeof shot int :%d\n",8*sizeof(short int));
	printf("sizeof long :%d\n",8*sizeof(long));			//longΪ32λ����
	printf("sizeof long long:%d\n",8*sizeof(long long));//long long ����64λ����
//ͬ��
	/***************************************������****************************************************/
	printf("\n*******************************************************************************\n");
	float fdata;
	printf("sizeof float :%d\n",8*sizeof(float));
	double ddata;
	printf("sizeof double :%d\n",8*sizeof(double));
	printf("sizeof long double :%d\n",8*sizeof(long double));	//96λ������128λ����
	printf("sizeof char :%d\n",8*sizeof(char));
	//printf("sizeof wchar_t :%d\n",8*sizeof(wchar_t));	���Կ�������c���ǲ�֧��wchar_t�ģ�����ʵ����int�ĺ궨��

	sidata=15;
	uidata=sidata;		//������û�о��棡��û�г�������
	printf("sidata = %d, uidata = %u\n",sidata,uidata);

	sidata=0xffffffff;	//������û�о��棡��
	uidata=sidata;		//���������ˣ�����������û�о��棡��--->����C������ǿ��������Ҫ���Լ���𣡣�
	printf("sidata = %d, uidata = %u\n",sidata,uidata);

	//����������⣬û�о���
	fdata=uidata;
	printf("fdata = %f\n",fdata);

	ddata=uidata;
	printf("dddata = %f\n",ddata);

	//û�о���
	fdata=50.016;
	ddata=67.854;
	sidata=fdata;
	uidata=ddata;
	printf("sidata = %d, uidata = %u\n",sidata,uidata);

	/****************************************�ַ���****************************************************/
	printf("\n*******************************************************************************\n");
	char ch='a';
	printf("ch = %c\n",ch);
	ch=sidata;				//û�о���
	printf("ch = %c\n",ch);
	ch=uidata;				//û�о���
	printf("ch = %d\n",ch);

	ch=255;
	printf("ch = %d\n",ch);		//���-1�����ƴ˴�charλ�з��ŵģ�λ��ǿ������ֲ�Կ�ǿ��ָ��unsigned

	unsigned char uch=255;
	printf("uch = %d\n",uch);
	//sizeof(wchar_t);			//wchar_t ��linux C�в����ǹؼ��֣���ʵ��#define wchar_t int��stddef.h�ж���
#include <stddef.h>
	wchar_t wch='a';
	printf("size of wch is: %d\n",8*sizeof(wch));	//���4

	/****************************************������****************************************************/
	printf("\n******************************************************************************\n");
//bool	ע��C�Ĳ����Ͳ���bool������_Bool�����ǿ��԰���ͷ�ļ�stdboolʹ�ú�C++���ݵ�bool
	_Bool istrue=15;					//��C��û��true��false����0����
	printf("size of _Bool : %d\n",8*sizeof(_Bool));		//���8λ��Ҳ����˵_Bool��ʵ����char
	printf("bistrue = %d\n",istrue);

#include <stdbool.h>
	bool bistrue=true;
	printf("size of bool : %d\n",8*sizeof(bool));		//���8λ��Ҳ����˵bool��ʵ����char����ʵ#define bool _Bool
	printf("istrue = %d\n",bistrue);


	/********************************��������************************************/
	printf("\n*******************************************************************************\n");
//	�����˰��컹��û�ܸ�����������ô�õģ���
	_Complex c=2;//+50*I;
	printf("c = %4.2f  %4.2f\n",c);

#include <complex.h>
	complex cc=2+5*I;
	printf("size of complex is:%d\n",8*sizeof(complex));		//���128��Ҳ����˵complex��64λ���..��64λ���..
	printf("cc = %f + %fi\n",cc);		//������Ҳ���Կ�������printf������ʵʹ�õĺ�����
	printf("cc = %f + %fi\n",cc,cc);

	float cc_real=cc;
	printf("cc_real  = %f\n",cc_real);		//-------------------->��64λ���������64λ���ʵ��
	float cc_image=*((double*)(((char *)(&cc)+8)));
	printf("cc_image = %f\n",cc_image);


	/**************************************�ַ���****************************************************/
	printf("\n*******************************************************************************\n");
	char * str="tangyu";
	printf("%s\n",str);
	char astr[20]="tangyu";
	printf("%s\n",astr);
	char aastr[20]={'t','a','n','g','y','u'};
	printf("%s\n",aastr);			//-------------->�˴���Ȼû��ִ�д��󣬿����Ǳ������Ĵ���

	printf("%s\n",&str);	//������������
	printf("%s\n",&astr);	//����
	printf("%s\n",&aastr);	//����	---->˵����&arr--->arr;arr--->arr[0]�����Ƕ���������Եģ��������ַ�ָ���򲻻�


	/**������**/
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
	printf("size of intmax_t is:%d\n",8*sizeof(imaxdata));		//�������λ64λ����
	printf("int max value is: %u",INTMAX_MAX);
	///...................




	/***********************************�����жϺ���*******************************************************/
	printf("\n*******************************************************************************\n");
#include <ctype.h>
	char bch='6';
	bch='\a';
	printf("iscntrl :%d\n",iscntrl(bch));			//���2
	bch='\n';
	printf("iscntrl :%d\n",iscntrl(bch));
	bch='\t';
	printf("iscntrl :%d\n",iscntrl(bch));
	bch=' ';
	printf("iscntrl :%d\n",iscntrl(bch));

	bch='6';
	printf("isalnum :%d\n",isalnum(bch));		//���8 ��������
	bch='\n';
	printf("isalnum :%d\n",isalnum(bch));		//���0

	bch='A';
	printf("isupper :%d\n",isupper(bch));			//256
	bch='a';
	printf("isupper :%d\n",isupper(bch));

	bch='a';
	printf("islower :%d\n",islower(bch));			//512
	bch='A';
	printf("islower :%d\n",islower(bch));

	/*��ĸ*/
	bch='a';
	printf("isalpha :%d\n",isalpha(bch));		//���1024 ��������
	bch='6';
	printf("isalpha :%d\n",isalpha(bch));

	/*����*/
	bch='6';
	printf("isdigital :%d\n",isdigit(bch));		//���2048 ��������
	bch='a';
	printf("isdigital :%d\n",isdigit(bch));

	/*16��������*/
	bch='6';
	printf("isxdigital :%d\n",isxdigit(bch));		//���4096 ��������
	bch='a';
	printf("isxdigital :%d\n",isxdigit(bch));		//���4096 ��������
	bch='h';
	printf("isxdigital :%d\n",isdigit(bch));

	/*�ո񣬱���'\n'  '\t'  ' '*/
	bch=' ';
	printf("isspace :%d\n",isspace(bch));			//���8192=8*1024
	bch='\n';
	printf("isspace :%d\n",isspace(bch));
	bch='\t';
	printf("isspace :%d\n",isspace(bch));
	bch='\a';
	printf("isspace :%d\n",isspace(bch));

	/*�ɴ�ӡ�ַ��������ո�*/
	bch=' ';
	printf("isprint :%d\n",isprint(bch));			//���16384=16*1024
	bch='\n';
	printf("isprint :%d\n",isprint(bch));

	/*�ɴ�ӡ�ַ����������ո�*/
	bch='a';
	printf("isgraph :%d\n",isgraph(bch));			//���32768=32*1024
	bch=' ';
	printf("isgraph :%d\n",isgraph(bch));

	/*������*/
	bch=',';
	printf("ispunct :%d\n",ispunct(bch));			//���4
	bch=' ';
	printf("ispunct :%d\n",ispunct(bch));
/*
 * ������Ĺ��̿��Կ�������Щ�����жϺ������Ϊ��ʱ���صĶ�����1������Ӧ�����м�ע�⣡��
 */




	return 0;
}
