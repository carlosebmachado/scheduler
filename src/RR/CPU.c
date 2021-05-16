/**
 * "Virtual" CPU that also maintains track of system time.
 */

#include <stdio.h>

#include "task.h"


// run this task for the specified time slice
void run(TASK *task, int slice) {
    printf("Running task: NAME[%s] TID[%d] BURST[%d] for %d units.\n", task->name, task->tid, task->burst, slice);
}
