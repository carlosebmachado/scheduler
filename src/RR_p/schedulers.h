#ifndef SCHEDULERS_H
#define SCHEDULERS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CPU.h"
#include "queue.h"
#include "timer.h"


#define MIN_PRIORITY 0
#define MAX_PRIORITY 2

#define P1 0
#define P2 1
#define P3 2

#define QUANTUM 10

QUEUE *tasks[3];

// add a task to the list 
void add(char *name, int tid, int priority, int burst);

// invoke the scheduler
void schedule();

#endif //SCHEDULERS_H
