#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "task.h"
#include "scheduler.h"
#include "scheduler_data.h"

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
