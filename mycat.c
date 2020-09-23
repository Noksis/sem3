#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int max_size = 10000;


int main (int argc, char* argv[] ) {

	int fd = 0;
	
//	for (int i =1; i < argc; i++){
//		printf("%s", argv[i]);
//	}
	
	for (int i = 1; i < argc; i++) {
		fd = open(argv[i],0777);

		if (fd == -1)
			printf("%s ", argv[i]);

//		printf("%d",fd);

		read(fd,stdout,max_size);
	}
	return 0;
}
