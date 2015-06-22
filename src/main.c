/**
 * Reference: http://www.thegeekstuff.com/2012/03/linux-threads-intro/
 **/

#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_THREADS 10
pthread_t tid[NUM_THREADS];

void *do_something(void *arg)
{
    int count = 0;
    struct timespec req;
    struct timespec rem;

    printf("DEBUG: BEGIN do_something(arg=%p)\n", arg);
    printf("DEBUG: do_something: pthread_self=%ld\n", pthread_self());

    req.tv_sec = (time_t)0;
    req.tv_nsec = 1000000l; /* 1 ms */

    while (1) {
        //printf("DEBUG: do_something: count=%d\n", count);
        printf(".");
        //sleep(1);
        nanosleep(&req, &rem);
        count++;
    }
    printf("DEBUG: END do_something\n");
    return NULL;
}

/* This function will eat CPU */
void *do_eat_cpu(void *arg)
{
    printf("DEBUG: BEGIN do_eat_cpu(arg=%p)\n", arg);
    printf("DEBUG: do_eat_cpu: pthread_self=%ld\n", pthread_self());

    while (1) {
        /* Do nothing, apart from eating CPU... */
    }

    printf("DEBUG: END do_eat_cpu\n");
    return NULL;
}


int main(int argc, char *argv[])
{
    int i;
    int err;
    int count = 0;
    //struct timespec req;
    //struct timespec rem;
    //pthread_attr_t attr;

    printf("DEBUG: BEGIN hello-thread: main(argc=%d, argv=%p)\n", argc, argv);

    //req.tv_sec = (time_t)0;
    //req.tv_nsec = 1000000l; /* 1 ms */

    for (i = 0; i < NUM_THREADS; i++) {
        printf("DEBUG: hello-thread: creating thread tid[%d]\n", i);
        switch (i) {
          case 0:
            err = pthread_create(&(tid[i]), NULL, &do_eat_cpu, NULL);
            break;
          default:
            err = pthread_create(&(tid[i]), NULL, &do_something, NULL);
        }
        if (err != 0) {
            printf("\n Can't create thread: [%s]", strerror(err));
        } else {
            printf("\n Thread created successfully\n");
        }
    }

    printf("DEBUG: hello-thread: start loop\n");
    while (1) {
        printf("DEBUG: hello-thread: count=%d\n", count);
        sleep(1);
        //nanosleep(&req, &rem);
        count++;
    }
    printf("DEBUG: hello-thread: end loop\n");

    printf("DEBUG: hello-thread end\n");
    return 0;
}

