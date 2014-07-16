#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<stdio.h>

#include<string.h>


#include<string>

#include<iostream>

using namespace std;

int main()
{
	char * myname="./ty";
	int file = open(myname,O_RDWR);
	write(file,"tangyu",7);
	close(file);
	cout<<"Here Begins the Linux!"<<endl;
	return 0;

}
