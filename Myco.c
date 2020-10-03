//
// Created by nikita on 02.10.2020.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>


int main (int argc, char** argv) {

    int code = 0;

    static struct option long_opt[] = {
            {"force",0,0,'f'},
            {"interactive",0,0,'i'},
            {0,0,0,0}
    };

    if (argc == 1){
        printf("Error! No argument!");
        return 0;
    }

    while (code != -1) {
        code = getopt_long(argc,argv,"if",long_opt,NULL);
        switch (code) {
            case 'i' :{
                printf("i");
                break;
            }
            case 'f' :{
                printf("f");
                break;
            }
            default:
                return 0;
        }
    }

    return 0;
}
