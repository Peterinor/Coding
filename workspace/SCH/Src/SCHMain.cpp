//============================================================================
// Name        : SCH.cpp
// Author      : ty
// Version     :
// Copyright   : copyright reserved of ty
// Description : Hello World in C++, Ansi-style
//============================================================================

#include"../inc/SCH.h"

void task1(){
	cout<<"task1<--"<<endl;
}
void task2(){
	cout<<"task2"<<endl;
}

int main()
{
	SchInit();

	SchAddTask(task1,200,200);
	SchAddTask(task2,100,100);

	SchStart();
	while(1){
		SchDispatch();
	}
	exit(0);
}
