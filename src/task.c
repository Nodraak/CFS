#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "task.h"

static void *task_runner(void *arg);

// Initialize a task
int task_create(s_task_data *task_data) {
    int ret = 0;

    ret = sem_init(&task_data->sem, 0, 0);
    if (ret != 0) {
        printf("Error sem_init\n");
        return 1;
    }

    pthread_t t;
    ret = pthread_create(&t, NULL, task_runner, task_data);
    if (ret != 0) {
        printf("Error pthread_create\n");
        return 1;
    }

    return 0;
}

// Unlock a task
int task_run(s_task_data *task_data) {
    int ret = sem_post(&task_data->sem);
    if (ret != 0) {
        printf("Error sem_post\n");
        return 1;
    }

    return 0;
}

// Wrapper around pthread's callback and sch's unlocking semaphore
void *task_runner(void *arg) {
    s_task_data *data = (s_task_data*)arg;

    while (true) {
        int ret = sem_wait(&data->sem);
        if (ret != 0) {
            printf("Error sem_wait\n");
            exit(1);
        }
        data->callback();
    }

    printf("Should not happen\n");
    return NULL;
}
