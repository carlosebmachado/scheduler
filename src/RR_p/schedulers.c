//
// Created by carlos on 14/05/2021.
//

#include "schedulers.h"

void add(char *name, int tid, int priority, int burst) {
    // init tasks
    if (!tasks[P1]) tasks[P1] = new_queue();
    if (!tasks[P2]) tasks[P2] = new_queue();
    if (!tasks[P3]) tasks[P3] = new_queue();

    int norm_priority = priority - 1;
    if (norm_priority >= MIN_PRIORITY && norm_priority <= MAX_PRIORITY){
        enqueue(tasks[norm_priority], new_task(name, tid, priority, burst));
    }
}

void schedule() {
    TIMER *timer = new_timer(QUANTUM);
    TASK *task = NULL;
    // while has tasks in the list
    while (size(tasks[P1]) > 0 || size(tasks[P2]) > 0 || size(tasks[P3]) > 0) {
        int cur_priority;
        cur_priority = size(tasks[P3]) > 0 ? P3 : -1;
        cur_priority = size(tasks[P2]) > 0 ? P2 : cur_priority;
        cur_priority = size(tasks[P1]) > 0 ? P1 : cur_priority;
        if(cur_priority == -1) return;

        task = front(tasks[cur_priority]);
        start(timer);
        while (!timeout(timer)) {
            run(task, timer->counter + 1);
            --task->burst;
            // break the exec if end of task
            if (task->burst <= 0) {
                break;
            }
        }
        dequeue(tasks[cur_priority]);
        // don't enqueue if task ended
        if (task->burst > 0) {
            enqueue(tasks[cur_priority], task);
        } else {
            free(task);
        }
    }
}
