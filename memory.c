#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>

int tree[2050],i,j,k; 


int place(int node) 
{  while(node!=0)  
   {    node=(node%2==0)?(node-1)/2:node/2;   
	if(tree[node]>1)    
	return 0;  
   }  
  return 1; 
}


void makedivided(int node) 
{  while(node!=0)  
  {   node=node%2==0?(node-1)/2:node/2;   
      tree[node]=1;  
  } 
} 


int power2(int i)
{if(!i)
return 1;
int x=2;
for(;i>1;i--)
x*=2;
printf("\n%d\n",x);
return x;
}

void segmentalloc(int totsize,int req)
{int flevel=0,size;
  size=totsize;
  if(req>totsize)
  {  
   return;  } 
  while(1)
{
if( req > size/2)
   break;
else
{   size/=2;
    flevel++;
}
}
printf("\n *  size= %d level=%d \n",size,flevel);  
//from begining of level (2^n -1) to (2^n+1 -2)
for(i=power2(flevel)-1;i<=(power2(flevel+1)-2);i++)
{printf("\n%d\n",tree[i]);
if(tree[i]==0  && place(i)) 			   
{tree[i]=req;					   
 makedivided(i);
 printf("  Result    :     Successful Allocation\n"); 
 return;
}
}
printf("    Result  :    The system don't have enough free memory\n");
return;
}

void makefree(int req)
{int node=0;
 while(1)
{if(tree[node]==req)
  break;
 else
  node++;
}
tree[node]=0;
while(node!=0)
{if(tree[node%2?node-1:node+1]==0 && tree[node]==0) 
{    tree[node%2==0?(node-1)/2:node/2]=0;    
     node=node%2==0?(node-1)/2:node/2;   }   
else 
break;  
} 
} 


void printing(int totsize,int node) 
{  int permission=0,llimit,ulimit,tab;
  if(node==0)   permission=1;
  else if(node%2)
   permission=tree[(node-1)/2]==1?1:0;
  else
   permission=tree[node/2]==1?1:0;
  if(permission)
  {   llimit=ulimit=tab=0;
   while(1)   
{    if(node>=llimit && node<=ulimit)
     break;
    else    
{     tab++;     
     llimit=ulimit+1;     
      ulimit=2*ulimit+2;    
}   
}   
printf(" %d ",totsize/power2(tab));
   if(tree[node]>1)
    printf("---> Allocated %d",tree[node]);
   else if(tree[node]==1)
    printf("---> Divided");
   else printf("---> Free");
   printing(totsize,2*node+1);
   printing(totsize,2*node+2);  
} 
} 


int main()
{
int totsize,cho,req; 

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
segmentalloc(totsize,req);
     break;
     case 2: 
printf("\n   M E M O R Y   D E A L L O C A T I O N \n\n");
printf("\n*  Enter the Process size  : "); 
scanf("%d",&req);
makefree(req); 
     break;
     case 3: 
printf("\n   M E M O R Y   A L L O C A T I O N  M A P\n\n");
printing(totsize,0); 
	break;
    default: 
       exit(0);   
}  
}
return 0;
}



