//
// Created by nikita on 07.11.2020.
//
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <pwd.h>
#include <pthread.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/shm.h>


pthread_mutex_t mut;

long long int count = 0;

struct data {
    long long int N;
};

void* dumb (void* arg) {

    struct data* d0 =  arg;
    long long int N = d0->N;

    for (int i = 0; i < N; i++){
        count++;
    }

}

void* naive (void* arg) {

    struct data* d0 =  arg;
    long long int N = d0->N;

    for (int i = 0; i < N; i++){
        pthread_mutex_lock(&mut);
        count++;
        pthread_mutex_unlock(&mut);
    }
}

void* wide (void* arg) {

    struct data* d0 =  arg;
    long long int N = d0->N;

    pthread_mutex_lock(&mut);
    for (int i = 0; i < N; i++){
        count++;
    }
    pthread_mutex_unlock(&mut);
}

void* optimum (void* arg) {

    struct data* d0 =  arg;
    long long int N = d0->N;

    int Local_count = 0;


    for (int i = 0; i < N; i++){
        Local_count++;
    }

    pthread_mutex_lock(&mut);
    count += Local_count;
    pthread_mutex_unlock(&mut);
}

int main (int argc, char** argv) {

    if (argc < 4) {
        printf("Error, need more args!");
        return 0;
    }

    pthread_t* thread;
    if (pthread_mutex_init(&mut, NULL) < 0)
        perror ("Mutex_init");


    long long int N =  atoi(argv[1]);
    int m =  atoi(argv[2]);
    int type =  atoi(argv[3]);


    struct data d0;
    d0.N = N / m;

    thread = (pthread_t*) calloc (m, sizeof(pthread_t));

    switch (type) {
        case 1:

            for (int j = 0; j < m; j++) {
                if (pthread_create(&thread[j], NULL, dumb, &d0) < 0)
                    perror("Dumb");
            }

            printf("It is dumb alg\n");

            break;
        case 2:

            for (int j = 0; j < m; j++) {
                if (pthread_create(&thread[j], NULL, naive, &d0) < 0)
                    perror("Naive");
            }

            printf("It is naive alg\n");

            break;
        case 3:

            for (int j = 0; j < m; j++) {
                if (pthread_create(&thread[j], NULL, wide, &d0) < 0)
                    perror("Wide");
            }

            printf("It is wide alg\n");
            break;
        case 4:
            for (int j = 0; j < m; j++) {
                if (pthread_create(&thread[j], NULL, optimum, &d0) < 0)
                    perror("Optimum");
            }

            printf("It is optimum alg\n");
            break;
    }

   for (int  i =0; i < m; i++) {
        pthread_join(thread[i], NULL);
    }

    printf("Count  = [%llu] \n", count);
    return 0;
}
