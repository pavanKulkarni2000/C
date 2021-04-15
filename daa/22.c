#include<stdio.h>
#include<stdlib.h>

int place(int p,int x[])
{
        int i;
        for(i=1;i<=(p-1);i++)
                if((x[i]==x[p])||(abs(x[i]-x[p])==(abs(i-p))))
                                return 0;
        return 1;
}

int main()
{
       int i,j,k,n,count=1,x[1500];
       printf("enter the number of queens");
       scanf("%d",&n);
       if(n==0||n==2||n==3)
       printf("no solution!!!\n");
       else
       {
           k=1;
           x[1]=0;
           while(k)
           {
                 x[k]=x[k]+1;
                 while(x[k]<=n&&!place(k,x))
                 x[k]=x[k]+1;
                 if(x[k]<=n)
                 {
                       if(k==n)
                       {
                               printf("solution %d\n",count++);
                               for(i=1;i<=n;i++)
                               {
                                       for(j=1;j<x[i];j++)
                                       printf("* ");
                                       printf("Q ");
                                       for(j=x[i]+1;j<=n;j++)
                                       printf("* " );
                                       printf("\n");
                               }
                        }
                        else
                        {
                               k+=1;
                               x[k]=0;
                        }
                 }
                 else
                      k-=1;
         }

     }
}

