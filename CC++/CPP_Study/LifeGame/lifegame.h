/*
 * File		:lifegame.h
 * Author	:tangyu
 * Date		:2011-05-22 22:33:53 
 * Version	:0.1
 * LastMod	:2011-05-24 22:33:55 
 */
#ifndef _LIFEGAME_H_
#define _LIFEGAME_H_

#include"farmland.h"

#include<vector>
#include<algorithm>

using std::vector;

typedef vector<string > StateRec;

typedef unsigned long long Hash_Type	;

typedef	 vector<Hash_Type >	 StateRecHash;

#ifndef _CURRENT_STATE_
#define _CURRENT_STATE_
/*
#define CURRENT_DEAD	0
#define CURRENT_STILL	1
#define	CURRENT_SLIDE	2
#define CURRENT_LOOP	3
*/
#endif

#define String_Verify	1



class LifeGame
{
public:

	LifeGame(void );
	LifeGame(int landsize,string landdata);
	LifeGame(int landsize,unit_type *landdata);
	
	void Play	(void );
	
	void Init	(void );
	
	void Plant			(void );	
	void AutoPlant		(void );
	void MannualPlant	(void );
	
	int CurrentState();
	
#if !String_Verify
	int CurrentState_Hash();
#else
	int CurrentState_Str();
#endif

#if !String_Verify
	Hash_Type HashLand(string landstr);
#endif

	void GameBegin	(void );
	void GameOver	(void );
	
	enum CURRENT_STATE
	{
		CURRENT_UNKNOWING,
		CURRENT_DEAD,
		CURRENT_STILL,
		CURRENT_SLIDE,
		CURRENT_LOOP		
	};	

	
private:
	Farmland 		land;
	int 			landSize;	//maybe no need!!
#if String_Verify
	StateRec 		record;
#else
	StateRecHash	recordHash;
#endif
	CURRENT_STATE	currentState;

};


#endif
