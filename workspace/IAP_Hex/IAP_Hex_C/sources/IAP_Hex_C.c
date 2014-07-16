/*
 ********************************************************************
 *Author	:ty
 *File		:HexData.cpp
 *Copyight	:Copyight Reserved by ty
 *Version	:0.1
 *Date		:2011-4-4
 *Describ	:对Hex类的测试程序
 ********************************************************************
 */
#define work_Path "/home/tylwj/file"

#include"../includes/HexData.h"

char * hexfile=work_Path"/Hex.hex";

void print_Hex(char * hex_file);


int main()
{
	printf("Version 0.4\n");
	print_Hex(hexfile);
	printf("Version 0.4\n");
	return 0;
}


/***********************************************************
 *向控制台输出Hex数据
 *数据来源于Hex文件
 ************************************************************/
void print_Hex(char * hex_file)
{
	FILE * file;
	char line[50];

	_Bool end_of_data=0;

	file=fopen(hex_file,"r");
	if(file==NULL)
	{
		printf("open failed!\n");
		exit(-1);
	}
	while(!feof(file)&&!end_of_data)//;//feof(file))
	{
		//fgets(line,sizeof(line),file);
		fscanf(file,"%s",line);
		printf("\n------->%s\n",line);
		end_of_data=show_Hex(get_Data_Str(line));
	}
	fclose(file);
}

