#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int tree[2048];
int total;

int valid(int i)
{while(i!=0)
 {if(i%2)
  i=(i-1)/2;
 else
  i=i/2 -1;
 if(tree[i]>1)
 return 0;
}
return 1;
}

void makedivided(int i)
{while(!i)
 {if(i%2)
  i=(i-1)/2;
 else
  i=i/2 -1;
 tree[i]=1;
}
}

void makeundivided(int i)
{while(!i)
 {if(i%2)
   if(!tree[i+1])
  i=(i-1)/2;
   else return;
 else
 if(!tree[i-1])
  i=i/2 -1;
   else return;
 tree[i]=0;
}
}

void segalloc(int req)
{int level=0,i,size=total;
 if(size<req)
{printf("INsuffecient\n");
return;
}
while(req>size/2)
size/=2,level++;

for(i=pow(2,level)-1;i<=pow(2,level+1)-2;i++)
if(!tree[i] && valid(i))
{tree[i]=req;
makedivided(i);
printf("Allocated\n");
return;}
printf("INsuffecient\n");
}

void segdealloc(int req)
{int i=0;
while(tree[i]!=req)
i++;
tree[i]=0;
makeundivided(i);
}

void print()
{int level=0,i,next,size=total;
do
{next=0;
size=total/pow(2,level);
for(i=pow(2,level)-1;i<=pow(2,level+1)-2;i++)
if(tree[i]==0)
printf("%d(free)",size);
else 
if(tree[i]==1 && (tree[2*i+1]!=0 || tree[2*i+1]!=0))
{next++;
printf("%d(divided)",size);}
else
printf("%d(used:%d)",size,tree[i]);
level++;printf("\n");
}while(next);
}


int main()
{
int cho,req,i; 

printf("      B U D D Y   S Y S T E M  R E Q U I R E M E N T S\n"); 

printf(" *  Enter the Size of the memory  :  ");  
scanf("%d",&total); 
for(int i=0;i<2*total;i++)
tree[i]=0;
while(1) 
 {    
printf(" *  1)   Locate the process into the Memory\n");   
printf(" *  2)   Remove the process from Memory\n");   
printf(" *  3)   Tree structure for Memory allocation Map\n");   
printf(" *  4)   Exit\n");     
printf(" *  Enter your choice  :  ");  
scanf("%d",&cho);   
switch(cho)   
{    case 1: 
printf("\n   M E M O R Y   A L L O C A T I O N \n\n");
printf("\n*  Enter the Process size  : "); 
scanf("%d",&req);
segalloc(req);
     break;
     case 2: 
printf("\n   M E M O R Y   D E A L L O C A T I O N \n\n");
printf("\n*  Enter the Process size  : "); 
scanf("%d",&req);
segdealloc(req); 
     break;
     case 3: 
printf("\n   M E M O R Y   A L L O C A T I O N  M A P\n\n");
print(); 
	break;
    default: 
       exit(0);   
}  
}
return 0;
}











