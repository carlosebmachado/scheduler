/**
 * Representation of a task in the system.
 */

#ifndef TASK_H
#define TASK_H

#include <stdlib.h>


// representation of a task
typedef struct task {
    char *name;
    int tid;
    int burst;
} TASK;

TASK *new_task(char *name, int tid, int burst);

#endif //TASK_H
