#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <assert.h>
#define _GNU_SOURCE

int max_size = 10000;
typedef unsigned int* gid_ty;

int main (void) {
	
	int uid = getuid();
	int gid = getgid();
	gid_ty buf;
	struct passwd* info = NULL;
	struct group* info1 = NULL;
	
	buf = calloc (sizeof(gid_ty),max_size);
	
	int num_gr = getgroups(max_size,buf);
//	printf("%d",num_gr);

	info1 = getgrgid(gid);
	assert(info1);

	info = getpwuid(uid);
	assert(info);
	
	//	printf("Pw is [%s]", buff);
	//
	printf("uid = %d",uid);
	printf("(%s) ",info->pw_name);
	
	printf("gid = %d", gid);
	printf("(%s) ",info1->gr_name);
	
	printf("groups =%d(%s)  ", buf[num_gr-1],info1->gr_name);
	for (int i = 0; i< num_gr-1; i++){
		printf("%d(%s), ",buf[i],getgrgid(buf[i])->gr_name);
	}

	printf("\n");
	return 0;
}
