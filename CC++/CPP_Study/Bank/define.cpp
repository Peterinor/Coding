#include"define.h"

#include<cstdio>

char * itoa ( int value, char * str, int base)
{
	sprintf(str,"%d",value);
	return str;
}
