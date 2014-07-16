/*
 *File		:First_glance.c
 *Author	:tangyu
 *Date		:2011-12-05 00:00:00
 *Version	:1.0.0
 *Modify	:2011-12-05 00:00:00
 */

#include <stdio.h>

int 
main (int argc, char *argv[])
{
	printf("The first glance at c programming in linux System!\n");
	printf("The argments is:\n");
	for( int i = 0; i < argc; i++ )
	{
		printf("%d:  %s\n",i,argv[i]);
	}
	return 0;
}
