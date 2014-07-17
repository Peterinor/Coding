#ifndef _SCH_H_
#define _SCH_H_


#include"../inc/Sig.h"


//Hardware config
#define OSC_Fre 12000000

#define OSC_Per_Inst 12


//plotform define
#define code


//constant define
#ifndef true
#define false 0
#define true (!false)
#endif


//type define
typedef unsigned char tByte;
typedef unsigned int tWord;
typedef unsigned long tLong;
typedef tByte Bool;

typedef void(*tTaskCode)();
//System define
#define MaxTasks 5


//Task struct define
typedef struct _Task{
	tTaskCode pTask;
	tByte ready;
	tWord delay;
	tWord period;

	_Task * prev;
	_Task * next;

}Task;


//
void SchDispatch(void);
Bool SchAddTask(tTaskCode task, const tWord delay, const tWord period);
Bool SchDeleteTask(tByte index);

#define handlePara int

void SchUpdate(handlePara);

void SchInit();
void SchStart();

#endif

