#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main(int argc,char *argv[])
{struct flock lock;
 int fd;
 if(argc==1)
 {printf("No file name!\n");
  return -1;
}
 if((fd=open(argv[1],O_RDWR))==-1)
 {perror("open");
  return -1;
 }
 
 lock.l_type=F_WRLCK;
 lock.l_whence=SEEK_SET;
 lock.l_start=0;
 lock.l_len=100;

 if(fcntl(fd,F_SETLK,&lock)==0)
 {
 printf("Locking the file fd= %d!\n",fd);
 sleep(5);
 }
 else 
 {
  fcntl(fd,F_GETLK,&lock);
   printf("Proc %d has Locked the file!\n",lock.l_pid);
   return -1;
 }
 
 printf("Enter to release!\n");
getchar();
lock.l_type=F_UNLCK;
 lock.l_whence=SEEK_SET;
 lock.l_start=0;
 lock.l_len=100;
 fcntl(fd,F_UNLCK,&lock);
return 0;
}



