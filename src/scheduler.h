#ifndef SCHEDULER_H_INCLUDED
#define SCHEDULER_H_INCLUDED

int sch_init(void);
int sch_tick(int t);
void sch_task_none(void);

#endif  // SCHEDULER_H_INCLUDED
