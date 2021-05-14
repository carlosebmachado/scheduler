//
// Created by carlos on 14/05/2021.
//


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "schedulers.h"

void add(char *name, int priority, int burst) {
    struct task *t = malloc(sizeof(struct task));
    t->name = name;
    t->priority = priority;
    t->burst = burst;
    insert(tasks, t);
}

void schedule() {

}
