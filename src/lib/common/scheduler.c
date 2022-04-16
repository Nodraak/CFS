#include <stdio.h>

#include "scheduler.h"
#include "scheduler_data.h"
#include "task.h"

// Create all tasks
int sch_init(void) {
    int i = 0;

    for (i = 0; i < SCHEDULING_TASK_DATA_LIST_LEN; i++) {
        int ret = task_create(&scheduling_task_data_list[i]);
        if (ret != 0) {
            printf("Error task_create\n");
            return 1;
        }
    }

    return 0;
}

// Execute the slot's task, depending on the time
int sch_tick(int t) {
    int dt = t % SCHEDULING_TABLE_LEN;
    s_task_data *task_data = &scheduling_task_data_list[scheduling_table[dt]];
    // TODO: check bounds

    int ret = task_run(task_data);
    if (ret != 0) {
        printf("Error task_run\n");
        return 1;
    }

    return 0;
}

// Idle task
void sch_task_none(void) {
    printf("Empty slot\n");
}
