//
// Created by carlos on 16/05/2021.
//

#include "task.h"


TASK *new_task(char *name, int tid, int priority, int burst) {
    TASK *t = malloc(sizeof(TASK));
    t->name = name;
    t->tid = tid;
    t->priority = priority;
    t->burst = burst;
    return t;
}
