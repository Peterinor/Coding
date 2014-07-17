#include"../inc/Sig.h"

void init_sigaction(funHandle SchUpdate)
{
	struct sigaction act;
	act.sa_handler=SchUpdate;
	act.sa_flags=0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGPROF,&act,NULL);
}
//in micro seconds
void init_timer(unsigned int interv)
{
	struct itimerval value;
	value.it_value.tv_sec=interv/1000000;
	value.it_value.tv_usec=interv % 1000000;
	value.it_interval=value.it_value;
	
	//cout<<value.it_value.tv_sec<<"  "<<value.it_value.tv_usec<<endl;

	setitimer(ITIMER_PROF,&value,NULL);
}
