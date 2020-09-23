#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


int max_size = 10000;
typedef unsigned int* gid_ty;

int main (int argc, char** argv) {

    // Parametrs
    if (argc == 2) {
        if (strcmp(argv[1], "-u") == 0) {
            printf("%d\n",getuid());
            return 0;
        }
        if (strcmp(argv[1],"-n") == 0) {
            printf("%s\n", getpwuid(getgid())->pw_name);
            return 0;
        }
    }

    // Get id
    int uid = getuid();
    int gid = getgid();

    // Get name
    struct passwd* info = NULL;
    struct group* info1 = NULL;

    //Create buf
    gid_ty buf;
    buf = calloc(max_size, sizeof(gid_ty));

    // Number of groups
    int num_gr = getgroups(max_size,buf);

    //Info about names
    info1 = getgrgid(gid);
    assert(info1);
    info = getpwuid(uid);
    assert(info);


    printf("uid=%d",uid);
    printf("(%s) ",info->pw_name);

    printf("gid=%d", gid);
    printf("(%s) ",info1->gr_name);

    printf("groups=%d(%s)", buf[num_gr-1],info1->gr_name);

    for (int i = 0; i< num_gr-1; i++){
        printf(",%d(%s)",buf[i],getgrgid(buf[i])->gr_name);
    }

    printf("\n");
    return 0;
}//
// Created by nikita on 24.09.2020.
//

