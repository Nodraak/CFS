/*
    Task
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct _s_task_data {
    void (*callback)(void);
    sem_t sem;
} s_task_data;

int task_create(s_task_data *task_data);
void *task_runner(void *arg);

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

int task_run(s_task_data *task_data) {
    int ret = sem_post(&task_data->sem);
    if (ret != 0) {
        printf("Error sem_post\n");
        return 1;
    }

    return 0;
}

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

/*
    Modules
*/

void task_none(void) {
    printf("Empty slot\n");
}

void task1_cycle(void) {
    printf("Hello, World - task 1 - cycle\n");
}

void task2_cycle(void) {
    printf("Hello, World - task 2 - cycle\n");
}

void task3_cycle(void) {
    printf("Hello, World - task 3 - cycle\n");
}

/*
    Sch
*/

#define SCH_TABLE_SIZE 10

typedef enum _e_tasks {
    T_NONE,
    T_T1,
    T_T2,
    T_T3,
    T_LAST,
} e_tasks;

s_task_data task_data_list[T_LAST] = {
    {.callback=task_none, .sem=0}, /* T_NONE */
    {.callback=task1_cycle, .sem=0}, /* T_T1 */
    {.callback=task2_cycle, .sem=0}, /* T_T2 */
    {.callback=task3_cycle, .sem=0}, /* T_T3 */
};

e_tasks scheduling_table[SCH_TABLE_SIZE] = {
    /* 0 */ T_T1,
    /* 1 */ T_T2,
    /* 2 */ T_T1,
    /* 3 */ T_T3,
    /* 4 */ T_T1,
    /* 5 */ T_T2,
    /* 6 */ T_T1,
    /* 7 */ T_NONE,
    /* 8 */ T_T1,
    /* 9 */ T_NONE,
};

int sch_init(void) {
    int i = 0;
    for (i = 0; i < T_LAST; i++) {
        int ret = task_create(&task_data_list[i]);
        if (ret != 0) {
            printf("Error task_create\n");
            return 1;
        }
    }

    return 0;
}

int sch_tick(int t) {
    int dt = t % SCH_TABLE_SIZE;
    s_task_data *task_data = &task_data_list[scheduling_table[dt]];

    int ret = task_run(task_data);
    if (ret != 0) {
        printf("Error task_run\n");
        return 1;
    }

    return 0;
}

/*
    Main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int ret = 0;

    // line buffered
    setvbuf(stdout, NULL, _IOLBF, 0);

    printf("Hello world - main\n");

    // init

    ret = sch_init();
    if (ret != 0) {
        printf("Error sch_init\n");
        exit(1);
    }

    // run

    for (int t = 0; t < 100; t++) {
        printf("t=%d\n", t);

        ret = sch_tick(t);
        if (ret != 0) {
            printf("Error sch_tick\n");
            exit(1);
        }

        usleep(500*1000);
    }

    return 0;
}
