#ifndef SCHEDULERS_H
#define SCHEDULERS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CPU.h"
#include "queue.h"
#include "timer.h"


#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

#define QUANTUM 10

QUEUE *tasks;

// add a task to the list 
void add(char *name, int tid, int burst);

// invoke the scheduler
void schedule();

#endif //SCHEDULERS_H
