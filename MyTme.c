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
#include <ctype.h>
#include <fcntl.h>
#include <string.h>

int fd_stdout = 1;
int fd_stdin = 2;
int count = 1000;
const int MAX_SIZE = 1000;


struct timespec start, final;

void count_words (char* buf, int count) {
    int sum = 0;

    for (int i = 0; i < count; i++ ) {

        if (isspace(buf[i]) != 0)
            i++;

        else {
            while (isspace(buf[i] == 0))
                i++;
            sum++;
        }
    }
    printf("Number of word is [%d]\n",sum);
}

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
    int pid = 0;
    int status = 0;
    int fd = 0;
    long bite_size = 0;
    char buf [MAX_SIZE];
    int pipefd[2] = {0,0};

    if(clock_gettime(CLOCK_REALTIME,&start) < 0)
        perror("Clock gettime start:");

    if(pipe(pipefd) < 0)
        perror("Pipe is");

    pid = fork();

    // If i am child
    if (pid == 0) {

        if(close(pipefd[0]) < 0)
            perror("Pipefd close");

        pipefd[1] = dup2(pipefd[1],1);

        if(execvp(argv[1], argv + 1) < 0)
            perror("Exec is not working!");
        exit(0);
    }

    wait(NULL);

    close(pipefd[1]);

    bite_size = read(pipefd[0],&buf,count);
    write(fd_stdout,buf,bite_size);

    printf("\nBite_size is [%lu]\n",bite_size);

    close(pipefd[0]);

    clock_gettime(CLOCK_REALTIME,&final);

    //count_words(buf,bite_size);
    printf("Process is working [%.3d] ms\n", (int)(count_time(start,final)));

    return 0;
}