
#include <cstdlib>

#include <ctime>

#include <iostream>

using namespace std;



int main()
{
	srand(time(NULL));
	
	int tw;

	tw=rand()%100;

	cout<<"Generate Num!"<<endl;
	cout<<"********************"<<endl;
	cout<<"***	"<<tw<<"	***"<<endl;
	cout<<"********************"<<endl;

	return 0;
}
