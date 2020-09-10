#include <stdio.h>
#include <string.h>
#define MODE_ON 1

int main (int ac, char* argv[]) {
	int flag = 0;

	if (ac > 1) {
		if (strcmp(argv[1], "-n") == 0)
			flag = MODE_ON;
	}

	if (ac == 0) {
		printf("\n");
		return 0;	
	}


	if (ac >= 1) {

		for (int i = 1 + flag; i < ac; i++) {
			printf("%s", argv[i]);
			if (i != ac-1)
				printf(" ");
		}

		if (flag != MODE_ON)
			printf("\n");
	}

	return 0;
}

