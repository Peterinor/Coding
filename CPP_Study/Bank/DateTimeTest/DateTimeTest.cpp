#include "../DateTime.h"

#include <iostream>

#include <fstream>

using namespace std;

int main(){
	DateTime dt;
	cout<<dt<<endl;
	dt.ToDateTime("2011-12-03-22-22-00");
	cout<<dt<<endl;

	fstream file;
	file.open("./date.txt",ios::out|ios::in|ios::trunc);
	if(!file){
		cout<<"File Error"<<endl;
		exit(1);
	}
	file<<dt;

	file.close();

	return 0;
}
	
