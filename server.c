//
// Created by nikita on 24.10.2020.
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
#include <sys/shm.h>
# include <sys/ipc.h>

int max_size = 100;

int main (void) {
    int ID = 0;
    ID = shmget(IPC_PRIVATE, 100, 0);
    return 0;
}
