//
// Created by nikita on 02.10.2020.
//
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
const int MAX_SIZE = 10000;
const int MAX_BITS = 10;

static struct option long_opt[] = {
        {"force",0,0,'f'},
        {"interactive",0,0,'i'},
        {0,0,0,0}
};


int my_read (int fd, char* buf, int len){

    int bits = 0;
    int last_read = -1;

    while (last_read != 0 ) {

        last_read = read(fd, buf+bits, MAX_BITS);

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

int copy (char** argv, int i, int flag ) {
    int fd = 0;
    char *buf;
    int bits = 0;

    buf =  calloc(MAX_SIZE, sizeof(char));

    fd = open(argv[i+1],O_RDONLY);
    printf("argv for read is %s\n", argv[i+1]);
    printf("Fd reading file is %d\n", fd);

    if (fd == -1) {
        perror("Open file to read");
        return -1;
    }

    bits = my_read (fd,buf, MAX_SIZE);
    printf ("buf is %s\n", buf);

    if (bits == -1)
        return -1;

    if (close(fd) == -1 )
        perror("Close file to read");

    if (flag == 2){
        if (open(argv[i+2], O_EXCL | O_CREAT | O_WRONLY) == -1) {
            remove(argv[i+2]);
            printf("remove is %s", argv[i+2]);
            fd = open(argv[i+2],O_WRONLY | O_CREAT | O_EXCL);
            if (fd == -1)
                perror("new file ?");
        }
        else
            fd = open(argv[i+2],O_WRONLY & O_TRUNC);
    }

    else if (flag == 0) {
        fd = open(argv[i+2],O_WRONLY | O_TRUNC);
    }

    else if (flag == 1) {
        if (fd = open(argv[i+2],O_WRONLY | O_EXCL) == -1){
            char choice = 0;
            printf("You are rewrite file %s\n"
                   "Accept you choice [Y\\N]???\n", *argv );
            choice = getchar();
            if (choice == 'y' || choice == 'Y') {
                fd = open(argv[i+2],O_WRONLY | O_TRUNC);
            }
            else
                return 0;


        }
    }

    if (fd == -1) {
        perror("Open file to read");
        return -1;
    }

    if (write(fd,buf,bits) == -1)
        perror("Write");

    if (close(fd) == -1 )
        perror("Close file to read");

    return 0;
}

int main (int argc, char** argv) {

    int code = 0;
    int flag = 0;
    int i = 0;

    if (argc == 1){
        printf("Error! No arguments!\n");
        return 0;
    }

    while (code != -1) {


        code = getopt_long(argc,argv,"if",long_opt,NULL);

        switch (code) {
            case 'i' :{
                printf("i");
                flag = 1;
                i++;
                break;
            }
            case 'f' :{
                printf("f");
                flag = 2;
                i++;
                break;
            }
            default:
                printf("flag is [%d] and i is [%d]\n", flag, i);
                copy(argv, i, flag);
                return 0;
        }
    }

}
