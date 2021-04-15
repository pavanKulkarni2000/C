#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h> 
#include<sys/types.h>
#include<sys/stat.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#define max 5
enum {thinking,eating,hungry} state[max];
sem_t self[max];
int phil[max];

void test(int i)
{if(state[i]==hungry && state[(i+1)%max]!=eating && state[(i-1+max)%max]!=eating)
{state[i]=eating;
sem_post(self+i);
}
}

void pickup(int i)
{state[i]=hungry;
test(i);
if(state[i]!=eating)
sem_wait(self+i);
}

void putdown(int i)
{state[i]=thinking;
test((i+1)%max);
test((i-1+max)%max);
}

void *philosopher(void *arg)
{int *i=(int*)arg;
pickup(*i);
printf("Philosopher %d is eating\n",*i);
sleep(rand()%3+3);
putdown(*i);
printf("Philosopher %d put down\n",*i);
}


int main()
{int i;
pthread_t t;
for(i=0;i<max;i++)
{sem_init(self+i,0,0);
state[i]=thinking;
phil[i]=i;
}
for(i=0;i<7;i++)
{
pthread_create(&t,NULL,philosopher,phil+rand()%max);
sleep(rand()%2+1);
}

pthread_join(t,NULL);
for(i=0;i<max;i++)
sem_destroy(self+i);
return 0;
}
