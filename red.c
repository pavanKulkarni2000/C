#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<semaphore.h>
#include<pthread.h>
#include<fcntl.h> 

int readers =0, count=0;
sem_t mutex,rwmutex;
void *reader()
{
sem_wait(&mutex);
readers ++;
if(readers==1)
sem_wait(&rwmutex);
sem_post(&mutex);

int fd= open("a.txt",0);
char buf[100];
read(fd,buf,100);
printf("The reader read the following : \n %s\n",buf);
close(fd);

sem_wait(&mutex);
readers --;
sleep(rand()%2);
if(readers==0)
sem_post(&rwmutex);
sem_post(&mutex);
}

void *writer()
{int n;
char buf[100];
sem_wait(&rwmutex);
int fd= open("a.txt",1);
lseek(fd,SEEK_SET,0);
printf("Enter the message:\n");
scanf("%[^\n]s",buf);

if((n=write(fd,buf,25))+1)
printf("The writer has written %d chars\n",n);
else
printf("The writer failed\n");
close(fd);
sem_post(&rwmutex);
}

int main()
{
int i;
sem_init(&mutex,0,1);
sem_init(&rwmutex,0,1);
pthread_t write,read[10];
for(i=0;i<10;i++)
{pthread_create(&read[i],NULL,reader,NULL);
if(i==4)
 pthread_create(&write,NULL,writer,NULL);
sleep(1);
}
for(i=0;i<10;i++)
pthread_join(read[i],NULL);
pthread_join(write,NULL);
sem_destroy(&mutex);
sem_destroy(&rwmutex);
}




