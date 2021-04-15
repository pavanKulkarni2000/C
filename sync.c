#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<semaphore.h>
#include<pthread.h>
#include<fcntl.h> 
#include<string.h>
 
int main(int argc,char *argv[])
{char *file=argv[1];
struct flock lock;
printf("Opening the file %s\n",file);
int fd = open(file,O_WRONLY);
printf("Locking the file.\n");
memset(&lock,0,sizeof(lock));
lock.l_type=F_SETLKW,&lock;
printf("Locked the file, press ENTER to unlock.\n");
getchar();
printf("Releasing the lock.\n");
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLKW,&lock);
close(fd);
}
