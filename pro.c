#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<semaphore.h>
#include<pthread.h>
#include<fcntl.h> 
#define max 5
int in=0,out=0;
sem_t empty,full;

 
void *producer()
{for(int i=0;i<5;i++)
{sem_wait(&empty);
printf("Producer produced at %d.\n",in);
in=(in+1)%max;
sleep(rand()%3);
sem_post(&full);
}
}

void *consumer()
{for(int i=0;i<5;i++)
{sem_wait(&full);
printf("Consumer Consumed at %d.\n",out);
out=(out+1)%max;
sleep(rand()%3);
sem_post(&empty);
}
}

int main()
{pthread_t prod,cons;
sem_init(&empty,0,max);
sem_init(&full,0,0);
pthread_create(&prod,NULL,producer,NULL);
pthread_create(&cons,NULL,consumer,NULL);
pthread_join(prod,NULL);
pthread_join(cons,NULL);
sem_destroy(&empty);
sem_destroy(&full);
}
