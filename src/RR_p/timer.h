//
// Created by carlos on 16/05/2021.
//

#ifndef TIMER_H
#define TIMER_H

#include <stdlib.h>

typedef struct timer {
    int counter;
    int interval;
} TIMER;

TIMER *new_timer(int interval);

void start(TIMER *timer);

int timeout(TIMER *timer);

#endif //TIMER_H
