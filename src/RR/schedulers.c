//
// Created by carlos on 14/05/2021.
//

#include "schedulers.h"

void add(char *name, int tid, int burst) {
    // init tasks
    if (!tasks) {
        tasks = new_queue();
    }
    enqueue(tasks, new_task(name, tid, burst));
}

void schedule() {
    TIMER *timer = new_timer(QUANTUM);
    TASK *task = NULL;
    // while has tasks in the list
    while (size(tasks) > 0) {
        task = front(tasks);
        dequeue(tasks);
        start(timer);
        while (!timeout(timer)) {
            run(task, timer->counter + 1);
            --task->burst;
            // break the exec if end of task
            if (task->burst <= 0) {
                break;
            }
        }
        // don't enqueue if task ended
        if (task->burst > 0) {
            enqueue(tasks, task);
        } else {
            free(task);
        }
    }
}
