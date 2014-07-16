#include<stdio.h>

int main()
{
	int a = 3;
	printf("~a+a=%d\n",~a+a);
	unsigned short b = 6;
	printf("~b+b=%d\n",~b+b);
	char ch = 'A';
	switch( ch )
	{
	case 'A':printf("A\n");break;
	default :printf("other\n");
	}
	return 0;
}
