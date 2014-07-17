#include"tPoly.h"
#include<iostream>
#include<string>

using namespace std;
using namespace ty;

int main()
{
	cout<<"************************************"<<endl;
	cout<<"From char *:"<<endl;
	//tPoly tp("5x^10+6x^8+17x^2+160x^1+90");
	//tPoly tp("5x^5+17x^2+6x^1+9");
	tPoly tp("3x^2+2x^1+6");
	tp.show();
	//cout<<tp.poly<<endl;
	cout<<tp(1)<<"-"<<tp(0)<<endl<<endl;
	
	cout<<"From string:"<<endl;
	//string s("5x^3+7x^2+6x^1+90");
	string s("2x^3+2x^1+7");
	tPoly ttp(s);

	ttp.show();
	cout<<ttp(1.0)<<"-"<<ttp(0)<<endl<<endl;
	
	cout<<"From array:"<<endl;
	double a[]={10,1,1,5,9};
	tPoly arr_p(4,a);
	arr_p.show();
	cout<<arr_p(1)<<"-"<<arr_p(0)<<endl;
		
	cout<<"\n\n************************************"<<endl;
	cout<<"多项式运算\n";
	cout<<"-"<<endl;
	(ttp-tp).show();
	cout<<"+"<<endl;
	(ttp+tp).show();
	cout<<"*"<<endl;
	(ttp*tp).show();
	cout<<"***"<<endl;
	(tp*tp*tp*tp).show();

	cout<<"\n\n";
	tPoly ty=ttp;
	ttp.show();

	/*cout<<"Test of Inner_q():"<<endl;
	double a_[]={6,2,3};
	double b_[]={7,2,0,2};
	for(int i=0;i<=5;i++)
	{
		cout<<"i="<<i<<"--";
		cout<<Inner_q(i,a_,b_,2,3)<<endl;
	}
	*/
	/*<<Inner_q(i,b_,a_,3,2)*/
	return 0;
}