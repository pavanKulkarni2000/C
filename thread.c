#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<grp.h>
#include<pthread.h>
int a[3][3]={{109901,2,353},{5,1009765,4},{10,3,5000}};
int b[3][3]={{125,552,3},{566,551,33454},{74410,54133,5000}};
int sum[3][3];
void *run(void *arg)
{int *row=arg,i,j,s;
printf("%d\n",*row);
for(j=0;j<3;j++)
 {s=0;
 for(i=0;i<3;i++)
   s+=(a[*row][i])*(b[i][j]);
 sum[*row][j]=s;
 }
  pthread_exit(0);
}

void main()
{
pthread_t t[3];
pthread_attr_t a;
pthread_attr_init(&a);
int rows[3]={0,1,2},i,j;
for(i=0;i<3;i++)
{printf("row thread%d\n",i);
pthread_create(t+i,&a,run,rows+i);
}
for(i=0;i<3;i++)
pthread_join(t[i],NULL);
for(i=0;i<3;i++)
{for(j=0;j<3;j++)
  printf("%d  ",sum[i][j]);
 printf("\n");
}
}
