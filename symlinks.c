//
// Created by nikita on 12.12.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

static struct option long_opt[] = {
        {"depth",0,0,'d'},
        {"name",0,0,'n'},
        {0,0,0,0}
};
int PATH_MAX = 1000;

int find (char* path){
    DIR* dir = opendir(path);
    struct dirent* entry = readdir(dir);
    struct stat* info;
    char pathName[PATH_MAX];
    if (dir == NULL)
        perror("Problem with open file!");

    while (entry != NULL){
        (void)strncpy( pathName, theDir, PATH_MAX );
        (void)strncat( pathName, "/", PATH_MAX );
        (void)strncat( pathName, entry.d_name, PATH_MAX );
        if (lstat(entry->d_name,info) < 0)
            perror("Problem with stat");
        if(S_ISDIR(info->st_mode) == 1)
            printf("It is dir!\n");

        printf("./%s\n",entry->d_name);
        entry = readdir(dir);
    }


    printf("%s\n",path);

    closedir(dir);
}

int main(int argc, char** argv) {
    char* path = argv[1];

    if (argc == 1){
        printf("Error! No arguments!\n");
        return 0;
    }

    int code = 0;
    int flag = 0;

    while (code != -1) {
        code = getopt_long(argc,argv,"dn",long_opt,NULL);
        switch (code) {
            case 'd' :{
                printf("d");
                flag = 1;
                break;
            }
            case 'n' :{
                printf("n");
                flag = 2;
                break;
            }
            default:
                find(path);
                return 0;
        }
    }
}

