#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<semaphore.h>
#include<pthread.h>
#include<fcntl.h> 
enum{thinking,eating,hungry} state[5];
sem_t self[5];
int phil[5];

void test(int i)
{if(state[i]==hungry && state[(i+1)%5]!=eating && state[(i+4)%5]!=eating)
{state[i]=eating;
sem_post(&self[i]);
}
}

void pickup(int i)
{state[i]=hungry;
test(i);
if(state[i]!=eating)
sem_wait(&self[i]);
}

void putdown(int i)
{state[i]=thinking;
test((i+1)%5);
test((i+4)%5);
}

void *philosopher(void * arg)
{int *i= arg;
pickup(*i);
printf("Philosopher %d is eating\n",*i);
sleep(rand()%5+5);
putdown(*i);
printf("Philosopher %d has putdown\n",*i);
}

int main()
{int i,k;
pthread_t tid;
for(i=0;i<5;i++)
{state[i]=thinking;
sem_init(self+i,0,0);
phil[i]=i;
}
for(i=0;i<13;i++)
{k=i%5;
pthread_create(&tid,NULL,philosopher,phil+k);
sleep(0.5);
}
pthread_join(tid,NULL);
for(i=0;i<5;i++)
sem_destroy(self+i);
}

 
