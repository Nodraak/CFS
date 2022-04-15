# README

*cFS From Scratch*

## Features

* MVP
    * Task + Semaphore
    * Scheduler
* Data exchange
    * Queue
    * Datapool

## Implementation

* app
    * thread
        * pthread_create() | rtems_task_create()
    * sem
        * sem_init() | rtems_sem_xx()
        * sem_post()
        * sem_wait()
