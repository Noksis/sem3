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

const int fd_stdout = 1;
const int fd_stdin = 2;
const int count = 1000;
const int MAX_SIZE = 1000;


struct timespec start, final;

int my_read (int fd, char* buf, int len){

    int bits = 0;
    int last_read = -1;
    int one_read_size = 10;

    while (last_read != 0 ) {

        last_read = read(fd, buf+bits, one_read_size);

        if (last_read == -1) {
            perror("My_read");
            return -1;
        }

        bits = bits + last_read;

        if (bits > len) {
            printf("Size buf less than file!");
            return -1;
        }
    }
    return bits;
}


void count_words (char* buf, int count) {
    int sum = 0;
    int strings = 0;
    for (int i = 0; i < count; i++ ) {
        if (isspace(buf[i]) != 0) {
            if (buf[i] == '\n')
                strings++;
            i++;
        }
        else {
            while (isspace(buf[i]) == 0) {
                if (buf[i] == '\n')
                    strings++;
                i++;
            }
            sum++;
        }
    }
    printf("Number of word is [%d]\n",sum);
    printf("Number of string is [%d]\n", strings);
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
    long bite_size = 0;
    char* buf;
    int pipefd[2] = {0,0};

    buf = calloc(MAX_SIZE, sizeof(char));

    //Start time
    if(clock_gettime(CLOCK_REALTIME,&start) < 0)
        perror("Clock gettime start:");

    //Create pipe
    if(pipe(pipefd) < 0)
        perror("Pipe is");

    pid = fork();

    // If i am child
    if (pid == 0) {

        //Close read pipe
        if(close(pipefd[0]) < 0)
            perror("Pipefd close");

        //Stdout of function is write pipe
        pipefd[1] = dup2(pipefd[1],fd_stdout);

        //Start function
        if(execvp(argv[1], argv + 1) < 0)
            perror("Exec is not working!");

        exit(0);
    }

    //Wait child
    wait(NULL);

    //Close pipe to write
    close(pipefd[1]);

    //Read from pipe
    bite_size = my_read(pipefd[0],buf,count);

    //Write to stdout
    write(fd_stdout,buf,bite_size);

    //Print bits
    printf("\nBite_size is [%lu]\n",bite_size);

    count_words(buf,bite_size);

    close(pipefd[0]);

    //Stop time
    clock_gettime(CLOCK_REALTIME,&final);


    printf("Process is working [%.3d] ms\n", (int)(count_time(start,final)));

    return 0;
}