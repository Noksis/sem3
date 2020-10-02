//
// Created by nikita on 26.09.2020.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>

struct timespec start, final;


long int count_time (struct timespec start, struct timespec final){

    long int sec;
    long int nsec;
    long int time;

    nsec = final.tv_nsec - start.tv_nsec;
    sec = final.tv_sec - start.tv_sec;

    //printf("nsec is %lu\n",nsec);
    //printf("sec is %lu\n", sec);

    time = sec*1000 + nsec/1000000;
    return time;
}

int main (int argc, char** argv) {
    int pid;
    int status = 0;

    pid = fork();
    clock_gettime(CLOCK_REALTIME,&start);
    //perror("Clock start!");

    // If i am child
    if (pid == 0) {
        execvp(argv[1], argv + 1);
        perror("Exec is not working!");
        exit(0);
    }

    wait(&status);
    clock_gettime(CLOCK_REALTIME,&final);
    //perror("Clock final!");

    printf("Process is working [%.3d] ms\n", (int)(count_time(start,final)));

    return 0;
}