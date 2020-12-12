//
// Created by nikita on 19.11.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

const int size_buf = 1024;
int ALL_ACCESS = 0777;
int TRAP = 0;
int BOAT = 1;
int WANT_COST = 2;
int TRAP_DOWN = 3;
int VOYAGE = 4;

//num is number of sem for operation
void sem_use (int sem_id, int num, int val) {
    struct sembuf op = {num, val, 0};
    int err = semop(sem_id, &op, 1);
    if (err < 0)
        perror("P is not work\n");
}


void passanger(int sem_id, int i) {
    printf("I am passanger, my number is [%d]\n", i);
    sem_use(sem_id,TRAP_DOWN,0);
    sem_use(sem_id,BOAT,-1);
    sem_use(sem_id,TRAP,-1);
    printf("Passangers %d on trap\n",i);
    sem_use(sem_id,TRAP,1);
    printf("Passangers %d on boat\n",i);
    sem_use(sem_id,VOYAGE,0);

    sem_use(sem_id,TRAP_DOWN,0);
    sem_use(sem_id,TRAP,-1);
    printf("Passangers %d on trap\n",i);
    sem_use(sem_id,TRAP,1);
    sem_use(sem_id,WANT_COST,-1);
    printf("Passangers %d thanks for trip\n",i);

}

void captain(int sem_id,int pas,int bcap,int tcap,int cyc) {
    printf("Captain is here!\n");
    int i = 0;
    while(i < cyc) {
        printf("Okey, go from the boat\n");
        sem_use(sem_id,BOAT,0);
        sem_use(sem_id,TRAP_DOWN,1);

        printf("Captain wait people on trap\n");
        sem_use(sem_id,TRAP,-tcap);
        sem_use(sem_id,TRAP,tcap);

        printf("Boat are full, go voyage\n");
        i++;
        printf("Okey, voyage is end!\n");
        sem_use(sem_id,TRAP_DOWN,-1);
        sem_use(sem_id,WANT_COST,0);
        printf("Boat is empted!\n");
        sem_use(sem_id,WANT_COST,bcap);

    }
    printf("Thanks for our voyages!");
}

int main(int argc, char** argv)
{

    char buf[size_buf];
    setvbuf(stdout, buf , _IOLBF, size_buf );

    if (argc < 5) {
        printf("Need more args!\n");
        return 0;
    }

    int pas = atoi(argv[1]);
    int bcap = atoi(argv[2]);
    int tcap = atoi(argv[3]);
    int cyc = atoi(argv[4]);

    printf("Number of passangers: %d\n", pas);
    printf("Boat capacity: %d\n", bcap);
    printf("Trap capacity: %d\n", tcap);
    printf("Number of voyages: %d\n", cyc);

    // 0 - trap, 1 - boat
    int sem_id = semget(IPC_PRIVATE, 2, ALL_ACCESS);
    if (sem_id < 0)
        perror("Semget is suck");

    //Close all doors
    sem_use(sem_id,TRAP,-1);
    sem_use(sem_id,BOAT,-1);

    int fork_id = 0;
    fork_id = fork();

    //If you a parent
    if (fork_id != 0) {
        captain(sem_id, pas, bcap, tcap, cyc);
        wait(NULL);
    }
    else
        //If you a child
        for (int i = 0; i < pas + 1; i++)
                passanger(sem_id, i);

    //Removing message query
    if (semctl(sem_id, IPC_RMID, 0) < 0)
        perror("Del wrong\n");
    return 0;
}

