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
	string myname="/home/tylwj/ty";
	int file = open(myname.c_str(),O_RDWR);
	write(file,"tangyu",7);
	close(file);
	cout<<"Here Begins the Linux!"<<endl;
	return 0;

}
