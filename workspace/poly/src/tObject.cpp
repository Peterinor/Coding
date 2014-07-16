#include "tObject.h"

using namespace ty;


tObject::tObject(void)
{
}


tObject::~tObject(void)
{
}

string tObject::Get_Name()
{
	//cout<<str(*this)<<endl;
	return string("Object");
}