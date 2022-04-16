# README

*CFS: cFS From Scratch*

## Quick start

```
sudo pip3 install invoke
invoke run -t=Linux
```

Output:

```
t=0
Hello, World - module 1 - cycle
t=1
Hello, World - module 2 - cycle
t=2
Hello, World - module 1 - cycle
t=3
Hello, World - module 3 - cycle
t=4
Hello, World - module 1 - cycle
t=5
Hello, World - module 2 - cycle
t=6
Hello, World - module 1 - cycle
t=7
Empty slot
t=8
Hello, World - module 1 - cycle
t=9
Empty slot
```

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
        * `pthread_create()` | `rtems_task_create()`
    * sem
        * `sem_init()` | `rtems_sem_xx()`
        * `sem_post()`
        * `sem_wait()`
