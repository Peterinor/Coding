#ifndef _SIG_H_
#define _SIG_H_

#include"../inc/includes.h"


typedef void(*funHandle)(int);

void init_sigaction(funHandle);

void init_timer(unsigned int interv);


#endif
