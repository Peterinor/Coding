#include"../inc/SCH.h"


Task taskQueue[MaxTasks];

Bool SchAddTask(tTaskCode task, const tWord delay, const tWord period){
	tByte i = 0;
	while((taskQueue[i].pTask != 0) && (i < MaxTasks)) i++;
	if(i == MaxTasks) return i;
	else{
		taskQueue[i].pTask = task;
		taskQueue[i].delay = delay;
		taskQueue[i].period = period;
		taskQueue[i].ready = 0;
	}
	return i;
}

Bool SchDeleteTask(tByte index){
	if((index > MaxTasks) || (index < 0 )) return false;
	else{
		taskQueue[index].pTask = 0x00;
		taskQueue[index].delay = 0;
		taskQueue[index].period =0;
		taskQueue[index].ready = 0;
	}
	return true;
}

void SchDispatch(void){
	tByte i = 0;
	for(i=0; i<MaxTasks; i++){
		if(taskQueue[i].ready > 0){
			taskQueue[i].pTask();
			taskQueue[i].ready -= 1;
			if(taskQueue[i].period == 0){
				SchDeleteTask(i);
			}
		}
	}
}


void SchUpdate(handlePara){
	//TODO:something related with hardware
	//std::cout<<"Update\n";
	tByte i = 0;
	for(i=0; i<MaxTasks; i++){
		if(taskQueue[i].pTask != 0){
			if(taskQueue[i].delay == 0){
				taskQueue[i].ready += 1;
				taskQueue[i].delay = taskQueue[i].period;
			}else{
				taskQueue[i].delay -= 1;
			}
		}
	}
}


void SchInit(){
	tByte i =0;
	for(i=0; i<MaxTasks; i++){
		SchDeleteTask(i);
	}
	init_sigaction(SchUpdate);
}
void SchStart(){
	init_timer(5000);
}




