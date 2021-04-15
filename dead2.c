#include<stdio.h>
 
int comp_unalloc(int *unalloc,int *need,int m)
{int i;
for(i=0;i<m;i++)
 if(unalloc[i]<need[i])
  return 0;
 for(i=0;i<m;i++)
  unalloc[i]+=need[i];
 return 1;
}

main()
{int unalloc[10],done[10];
 int max[10][10],need[10][10],alloc[10][10];
 int i,n,m,j,t;
 printf("Processes: ");
 scanf("%d",&n);
 printf("Resources: ");
 scanf("%d",&m);
 printf("Max\n");
 for(i=0;i<n;i++)
 for(j=0;j<m;j++)
 scanf("%d",max[i] +j);
 printf("Alloc\n");
 for(i=0;i<n;i++)
 for(j=0;j<m;j++)
 scanf("%d",alloc[i] +j);
 printf("Need\n");
 for(i=0;i<n;i++)
 {for(j=0;j<m;j++)
 printf("%d ",need[i][j]=max[i][j]-alloc[i][j]);
 done[i]=-1;
 printf("\n");
 }
 printf("Unalloc\n");
 for(i=0;i<m;i++)
 scanf("%d",unalloc+i);

 printf("Allocation:\n");
 t=0;
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 {if(done[j]!=-1)
   continue;
  if(comp_unalloc(unalloc,need[j],m))
   {done[j]=t++;
    printf("P[%d]\n",j);
    break;}
 }

 if(t==n)
{printf("Success\n");
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
  if(done[j]==i)
   {printf("P[%d]\n",j);
    break;}
}
else printf("Fail\n");
return 0;
}










