/*
 * File		:main.cpp
 * Author	:tangyu
 * Date		:2011-05-22 22:30:01 
 * Version	:0.1
 * LastMod	:2011-05-24 22:30:10 
 */
#include<iostream>

#include"lifegame.h"

#include<algorithm>
#include<vector>


using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout<<"LifeGame Here!"<<endl;

	unit_type land[]={	1,1,1,0,0,
						0,1,1,1,0,
						0,0,0,1,1,
						0,1,1,0,1,
						0,1,1,0,0
					};	
	cout<<endl;
	
	LifeGame game(5,land);
	
	game.Play();
	
	return 0;
}

