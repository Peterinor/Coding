//��Ϊ����̨��������˻��������
#include"Bank.h"
#include"DateTime.h"
#include"Account.h"
#include<vector>
using namespace std;

void Test();

void test();

int main()
{
	//wcout<<"����"<<endl;

	//system("pause");
	Bank TCLBank("./Account.dat");
	TCLBank.Run();					//�����ϰ࣡
	//OR:(new Bank())->Run();		//�����ϰ࣡

	TCLBank.Exit();				//�����°࣡

	return 0;
	
}


