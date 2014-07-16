//此为控制台版的银行账户管理程序
#include"Bank.h"
#include"DateTime.h"
#include"Account.h"
#include<vector>
using namespace std;

void Test();

void test();

int main()
{
	//wcout<<"唐禹"<<endl;

	//system("pause");
	Bank TCLBank("./Account.dat");
	TCLBank.Run();					//银行上班！
	//OR:(new Bank())->Run();		//银行上班！

	TCLBank.Exit();				//银行下班！

	return 0;
	
}


