/*
 *File		:cstd_file.c
 *Author	:tangyu
 *Date		:2011-12-05 00:00:00
 *Version	:1.0.0
 *Modify	:2011-12-05 00:00:00
 */

#include <stdio.h>
#include <stdlib.h>

#define work_Path "/home/tylwj/Linux_Program/cstd_file"

int 
main (int argc, char *argv[])
{
	char * filename = "./test.txt";
	//FILE file;
	FILE *fp = NULL;
	fp = fopen(filename,"w");		//must be the hole path of the file, or file can not be opened!
	if(NULL == fp){
		printf("File Open error!\n");
		exit(1);
	}
	printf("File Open Successed!\n");
	printf("Write some words to file\n");
	fprintf(fp,"This is a test of access file with pure c stdlib!\n");
	fprintf(fp,"My age is :%d",22);
	fclose(fp);

	fp = fopen("./cstd_file.c","r");	//Here if you make a mistake with the file_mode....hahah...especially when the mode is 'w'
	if(NULL == fp){
		printf("File Open error!\n");
		exit(1);
	}
	printf("File Open Successed!\n");
	printf("Read some words from file\n");
	char str[100];
	while(!feof(fp)){
		//fscanf(fp,"%s",str);
		//fgets(fp,
		printf("%s",fgets(str,100,fp));
	}
	printf("\n");
	fclose(fp);
	return 0;
}
 

