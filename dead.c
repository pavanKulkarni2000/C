#include<stdio.h>

int is_grater_than_or_equal(int *unalloc,int *res_need,int m)
{for(int i=0;i<m;i++)
  if(unalloc[i]<res_need[i])
    return 0;
 return 1;
}

int main()
{int n, m, unalloc[10], alloc[10][10], done[10], need[10][10], max[10][10],i,k,j,t;
printf("Enter the number of processes :\n");
scanf("%d",&n);
printf("Enter the number of resources :\n");
scanf("%d",&m); 

//max requirement
printf("Enter the maximum resources needed for each process :\n");
for(i=0;i<n;i++)
{printf("P%d.\n",i);
for(j=0;j<m;j++)
 scanf("%d",&max[i][j]);
}

//allocated resources
printf("Enter the number of resources allocated for each process :\n");
for(i=0;i<n;i++)
{printf("P%d.\n",i);
for(j=0;j<m;j++)
scanf("%d",&alloc[i][j]);
}

printf("Resouces needed:\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{need[i][j]=max[i][j]-alloc[i][j];
printf("%d ",need[i][j]);
}
printf("\n");
}


//unallocated resources
printf("Enter the number of unallocated resources :\n");
for(j=0;j<m;j++)
scanf("%d",&unalloc[j]);

//initialization
for(i=0;i<n;i++)
done[i]=-1;

//allocation sequence
k=0;
for(t=0;t<n;t++)
for(i=0;i<n;i++)
{ if(done[i]!=-1)
   continue;
 if(is_grater_than_or_equal(unalloc,need[i],m))
  {done[i]=k++;
   for(j=0;j<m;j++)
     unalloc[j]+=alloc[i][j];
   break;
  }
}


if(k== n)
 {printf("The allocaton is in safe state. The safe squence of execution :\n");
  for(i=0;i<n;i++)
   printf("P %d : %d \n",i,done[i]);
}
else
 printf("The allocaton is in UNSAFE state!\n");

}



