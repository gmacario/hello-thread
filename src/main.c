/**
 * Reference: http://www.thegeekstuff.com/2012/03/linux-threads-intro/
 **/

#include <stdio.h>
#include <time.h>

main(int argc, char *argv[])
{
    int count = 0;
    struct timespec req;
    struct timespec rem;

    printf("DEBUG: hello-thread start\n");

    req.tv_sec = (time_t)0;
    req.tv_nsec = 1000000l; /* 1 ms */

    while (1) {
        printf("main: count=%d\n", count);
        //sleep(10);
        nanosleep(&req, &rem);
        count++;
    }

    printf("DEBUG: hello-thread stop\n");
    return 0;
}

