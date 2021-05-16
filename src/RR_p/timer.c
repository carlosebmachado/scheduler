//
// Created by carlos on 16/05/2021.
//

#include "timer.h"


TIMER *new_timer(int interval) {
    TIMER *t = malloc(sizeof(TIMER));
    t->counter = 0;
    t->interval = interval;
    return t;
}

void start(TIMER *timer) {
    timer->counter = timer->interval;
}

int timeout(TIMER *timer) {
    --timer->counter;
    if (timer->counter < 0) {
        timer->counter = timer->interval;
        return 1;
    }
    return 0;
}
