//
// Created by nikita on 10.10.2020.
//
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>
#include <string.h>
#include <sys/msg.h>
const int size_buf = 1024;
const long start_race = 1000;
const long num_end = 999999;

struct timespec starting, final;

struct msgbuf {
    long mtype;
};

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

int judge (int N, int ID) {
    struct msgbuf output;
    struct msgbuf start;
    struct msgbuf end;

    printf("Daddy is here!\n");

    //Accept sportsmen
    for (int i = 1; i < N+1; i++) {
        if(msgrcv(ID, &output, 0, i, 0) == -1)
            perror("Accept sportsmen\n");

        printf("I am see you [%d] sportsmen\n", i);
    }

    printf("Okey, boys, lets start runs!\n");


    //Ready for a running?
    start.mtype = start_race;
    printf("To the start! Attention! March!\n");

    for (int i =1; i < N+1; i++) {
        if(msgsnd(ID, &start, 0, 0) == -1)
            perror("Start run judge");
    }


    //Start time
    if(clock_gettime(CLOCK_REALTIME,&starting) < 0)
        perror("Clock gettime start:");

    start.mtype = 1;

    //Start runs
    if(msgsnd(ID, &start, 0, 0) == -1)
        perror("Start run judge");


    //Finish run
    if(msgrcv(ID, &end, 0, num_end, 0) == -1)
        perror("Finish run judge");
    printf("Okey boys! Finish race.\n");



    //Stop time
    clock_gettime(CLOCK_REALTIME,&final);
    printf("Your time is  [%.3d] ms\n", (int)(count_time(starting,final)));
    printf("God job! Lets g relax\n");

    return 0;
}

int runner (int N, int ID, int number) {

    struct msgbuf start;
    struct msgbuf input;
    struct msgbuf putstick;
    struct msgbuf getstick;
    struct msgbuf end;


    // Runner is input
    input.mtype = number;
    printf("My number is [%d], i am input stadium \n", number);
    if(msgsnd(ID, &input, 0, 0 ) == -1)
        perror("Runner input");

    //Start run!
    if(msgrcv(ID, &start, 0, start_race, 0) == -1)
        perror("Start runner");

    //Put\get stick
    if (number != N) {
        if (msgrcv(ID, &getstick, 0, number, 0) == -1)
            perror("getstick");

        printf("I get stick! My number is [%d]\n", number);

        putstick.mtype = number + 1;

        if (msgsnd(ID, &putstick, 0, 0) == -1)
            perror("Putstick");
    }

    //Finish run
    if (number == N) {
        end.mtype = num_end;

        if (msgrcv(ID, &getstick, 0, number, 0) == -1)
            perror("getstick");

        printf("I get stick! My number is [%d]\n", number);

        printf("Judge it is a stick! Finish race!\n");
        if(msgsnd(ID, &end, 0, 0) == -1)
            perror("Last put stick");


    }

    return 0;

}

int main (int argc, char** argv) {

    char buf[size_buf];
    setvbuf(stdout, buf , _IOLBF, size_buf );

    int pid = 0;
    int N = atoi(argv[1]);
    int ID = 0;

    printf("Create queue\n");
    ID = msgget(IPC_PRIVATE,S_IRWXU);

    int i = 1;
    for (i = 1; i < N+1; i++) {
        pid = fork();
        if (pid == 0)
            break;
    }

    if (pid != 0) {
        judge(N, ID);
        wait(NULL);
        msgctl(ID,IPC_RMID,NULL);
    }


    //if i am child
    if (pid == 0) {
        printf("Runner [%d] is create\n", i);
        runner(N, ID, i);
    }



    return 0;
}
