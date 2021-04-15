#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 int tree[2050],tsize;

int valid(int i){
while(i>1)
{i/=2;
if(tree[i]>1)
return 0;
}
return 1;
}

void makedivided(int i)
{while(i>1)
{i/=2;
if(tree[i]==1)
return;
tree[i]=1;
}
}

void makeundivided(int i)
{while(i>1)
{
if(i%2)
 if(tree[i-1]==0)
  i/=2;
 else
  return;
else
 if(tree[i+1]==0)
  i/=2;
 else
  return;
tree[i]=0;
}
}

void segalloc(int req)
{int level=0,size=tsize,i;
 if(req>tsize){
printf("Too large!\n");
return;
}
while(req<=size/2)
{level++;
size/=2;
}

printf("size = %d level= %d\n",size,level);

for(i=pow(2,level);i<pow(2,level+1);i++)
if(!tree[i] && valid(i)){
tree[i]=req;
makedivided(i);
return;
}
printf("Insuffecient Memory!\n");
}

void segdealloc(int req)
{int i=0;
while(tree[i]!=req)
i++;
tree[i]=0;
makeundivided(i);
}

void print()
{int next,i,level=0,size;
do
{size=tsize/pow(2,level);
next=0;
for(i=pow(2,level);i<pow(2,level+1);i++)
 if(!tree[i])
   if(valid(i))
    printf("%d(free)",size); 
   else
    printf("%d(used)",size); 
 else
   if(tree[i]==1 && size!=1)
    printf("%d(divided)",size),next=1; 
   else
    printf("%d(used:%d)",size,tree[i]);
level++;
printf("\n");
}while(next);
} 

void main()
{
int c,size;
printf("Enter the total size of the memory:\n");
scanf("%d",&tsize);
for(int i=1;i<=tsize*2;i++)
tree[i]=0;
while(1)
{printf("Enter the choice   :\n1 .\tNew Allocation.\n2 .\tDelete Allocation.\n3 .\tPrint tree\n\t:");
scanf("%d",&c);
switch(c)
{case 1:printf("Enter the Size of allocation  :   ");
scanf("%d",&size);
segalloc(size);
printf("\n");
break;
case 2:printf("Enter the Size of deallocation  :   ");
scanf("%d",&size);
segdealloc(size);
printf("\n");
break;
case 3:print( );
printf("\n");
break;
default : exit(0);
}
}
}
