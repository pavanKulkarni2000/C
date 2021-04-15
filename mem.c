#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int tree[2048];

void makedivided(int node)
{while(node!=0)
 {printf("node= %d\n",node);
  if(!node%2)//even
   node=node/2 -1;
  else
   node=(node-1)/2;
  printf("node= %d\n",node);
  tree[node]=1;//make parent 1 to mark it as divided
 }
} 

void makeundivided(int node)
{while(node!=0)
 {//check if the right child (if node is odd) or left child (if node is even) is also 0
  if(node%2==0)
   if(!tree[node-1])
    {printf("zero=%d\n",tree[node-1]);
    node=node/2 -1;}

   else
    return;
  else
   if(!tree[node+1])
{printf("zero=%d\n",tree[node-1]);
    node=(node-1)/2;}
   else
    return;
  tree[node]=0;//make parent 1 to mark it as divided
 }
} 

int valid(int node)
{while(node!=0)
 {if(!node%2)
   node=node/2 -1;
  else
   node=(node-1)/2;
  if(tree[node]>1)//check if parent is divided
   {printf(" invalid\n");
    return 0;
   }
 }
printf(" valid\n");
return 1;
} 


void segalloc(int total,int req)
{int size=total,level=0,i;

if(req>size)
{printf("  Result    :    Memory insuffecient(1).\n");
return;}

while(1)
{if(req>size/2)
  break;
 size/=2;
 level++;
}
printf("size = %d level= %d\n",size,level);
for(i=(int)pow(2,level)-1;i<=(int)pow(2,level+1)-2;i++)
{printf("i=%d\n",i);
if(tree[i]==0 && valid(i))
{
 tree[i]=req;
 makedivided(i);
 printf("  Result    :     Successful Allocation.\n");
 return;
}}
printf("  Result    :    Memory insuffecient.\n");
return;
}

void makefree(int request)
{
int node=0;
while(1)
{if(tree[node]==request)
  break;
 node++;
}
tree[node]=0;
makeundivided(node);
}

void print(int total)
{int level=0,i,next=0,size;
for(i=0;i<2*total;i++)
printf("%d",tree[i]);

do
{size=total/(int)pow(2,level);
 next=0;
for(i=(int)pow(2,level)-1;i<=(int)pow(2,level+1)-2;i++)
 if(tree[i]==0)
   printf("%d(free)\t",size);
 else 
  if((tree[i]==1)&&(tree[2*i+1]!=0 || tree[2*i+2]!=0))
   {printf("%d(divided)\t",size);
    next=1;} 
  else
    printf("%d(used:%d)\t",size,tree[i]);
level++;
printf("\n");
}while(next);
}


int main()
{
int totsize,cho,req,i; 

printf("      B U D D Y   S Y S T E M  R E Q U I R E M E N T S\n"); 

printf(" *  Enter the Size of the memory  :  ");  
scanf("%d",&totsize); 
for(int i=0;i<2*totsize;i++)
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
segalloc(totsize,req);
     break;
     case 2: 
printf("\n   M E M O R Y   D E A L L O C A T I O N \n\n");
printf("\n*  Enter the Process size  : "); 
scanf("%d",&req);
makefree(req); 
     break;
     case 3: 
printf("\n   M E M O R Y   A L L O C A T I O N  M A P\n\n");
print(totsize); 
	break;
    default: 
       exit(0);   
}  
}
return 0;
}




