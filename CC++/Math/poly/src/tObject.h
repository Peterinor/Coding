#pragma once

#define str(name) #name


#include<iostream>
#include<string>

using namespace std;

namespace ty
{
	class tObject
	{
	public:
		tObject(void);
		virtual ~tObject(void);

		string Get_Name();
	};

}