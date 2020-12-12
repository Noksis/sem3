//
// Created by nikita on 26.09.2020.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <assert.h>
#include <stdlib.h>

int main (int argc, char** argv) {
    int status = 0;

    int number = 0;
    int pid = getpid();


    if (argc == 1) {
        printf("Need arg!\n");
        return 0;
    }

    printf("Parent [%d]\n",getpid());

    number = strtol(argv[1],NULL,10);
    pid = fork();
    for (int i = 0; i < number; i++) {

        // If i am child!
        if (pid == 0) {
            printf("I am child [%d], my parent is [%d], and i am going to die\n", getpid(), getppid());
            pid = fork();
            if (pid != 0) {
                wait(&status);
                exit(0);
            }
        }
    }

    // Wait child.
    for (int i = 0; i < number; i++)
        wait(&status);
    return 0;
}

