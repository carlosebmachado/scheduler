//
// Created by carlos on 16/05/2021.
//

#include "task.h"


TASK *new_task(char *name, int tid, int burst) {
    TASK *t = malloc(sizeof(TASK));
    t->name = name;
    t->tid = tid;
    t->burst = burst;
    return t;
}
