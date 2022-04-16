#ifndef SCHEDULER_DATA_H_INCLUDED
#define SCHEDULER_DATA_H_INCLUDED

#include "modules.h"
#include "scheduler.h"
#include "task.h"

typedef enum _e_tasks {
    T_NONE,
    T_T1,
    T_T2,
    T_T3,
    T_LAST,
} e_tasks;

#define SCHEDULING_TASK_DATA_LIST_LEN T_LAST
static s_task_data scheduling_task_data_list[SCHEDULING_TASK_DATA_LIST_LEN] = {
    {.callback=sch_task_none, .sem=0}, /* T_NONE */
    {.callback=module_1_cycle, .sem=0}, /* T_T1 */
    {.callback=module_2_cycle, .sem=0}, /* T_T2 */
    {.callback=module_3_cycle, .sem=0}, /* T_T3 */
};

#define SCHEDULING_TABLE_LEN 10
static const e_tasks scheduling_table[SCHEDULING_TABLE_LEN] = {
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

#endif  // SCHEDULER_DATA_H_INCLUDED
