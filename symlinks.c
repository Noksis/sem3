//
// Created by nikita on 12.12.2020.
//
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>

static struct option long_opt[] = {
        {"depth",0,0,'d'},
        {"name",0,0,'n'},
        {0,0,0,0}
};

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
                //Find
                return 0;
        }
    }
}
