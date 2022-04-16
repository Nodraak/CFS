#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#include "semaphore.h"

typedef struct _s_task_data {
    void (*callback)(void);
    sem_t sem;
} s_task_data;

int task_create(s_task_data *task_data);
int task_run(s_task_data *task_data);

#endif  // TASK_H_INCLUDED
