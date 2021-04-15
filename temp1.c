#include<stdio.h>
#include<math.h>
int tree[2050],tsize;

void makediv(int i)
{while(i>1)
{i/=2;
if(tree[i]==1) return;
tree[i]=1;
}}

void makeundiv(int i)
{while(i>1)
{if(i%2)
if(!tree[i-1])
 i/=2;
else 
 return;
else
if(!tree[i-1])
 i/=2;
else
 return;
tree[i]=0;
}}


int valid(int i)
{while(i>1)
{i/=2;
if(tree[i]>1) return 0;
}
return 1;
}

void segalloc(int req)
{int level=0,size=tsize,i;
if(req>size)
{printf("\tTooo large!\n");
return ;
}

while(req<=size/2)
{size/=2;
level++;
}
for(i=pow(2,level);i<pow(2,level+1);i++)
if(!tree[i] && valid(i))
{tree[i]=req;
printf("\tAllocated at level %d!\n",level);
makediv(i);
return;
}
printf("\tMemory insuffecient\n");
}

void segdealloc(int req)
{int i;
while(i!=req) i++;
tree[i]=0;
makeundiv(i);
}

void print()
{int next,level=0,size=tsize,i;
do
{next=0;
for(i=pow(2,level);i<pow(2,level+1);i++)
if(!tree[i] )
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
size/=2;
}while(next);
}

int main()
{int size,ch,i;
printf("\tEnter total size\n");
scanf("%d",&tsize);
for(i=1;i<tsize*2;i++)
tree[i]=0;
 while(2)
{printf("\tEnter chioce:\n\t1.Allocate segment\n\t2.Deallocate segment\n\t3.print\n\texit\n");
scanf("%d",&ch);
switch(ch)
{case 1:printf("\tEnter size:\n");
scanf("%d",&size);
segalloc(size);
break;
case 2:printf("\tEnter size:\n");
scanf("%d",&size);
segdealloc(size);
printf("\tDeallocated!\n");
break;
case 3:print();
break;
default:return 0;}}return 0;}
