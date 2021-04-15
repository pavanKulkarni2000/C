#include<stdio.h>

int bound,curr[10],totcost,visited[10],jb[10];

int init(int a[10],int n,int j)
{
        int i,m=999;
        for(i=0;i<n;i++)
        {
                if(a[i]<m&&!visited[i])
                {
                        m=a[i];
                        curr[j]=m;
                }
        }
        return m;
}

int sum(int n)
{
        int i,sum=0;
        for(i=0;i<n;i++)
                sum+=curr[i];
        return sum;
}
void assignment(int cost[10][10],int n,int r)
{
        int i,j,checkmin=0,min=999,ans;
        if(r==n)
                return;
        for(i=0;i<n;i++)
        {
                if(!visited[i])
                {
                        curr[r]=cost[r][i];
                        visited[i]=1;
                        for(j=r+1;j<n;j++)
                                init(cost[j],n,j);
                        checkmin=sum(n);
                        if(checkmin<min)
                        {
                                min=checkmin;
                                ans=i;
                        }
                        visited[i]=0;
                }
        }
        visited[ans]=1;
		jb[r]=ans+1;
        curr[r]=cost[r][ans];
        assignment(cost,n,r+1);
}

main()
{
        int cost[10][10],i,n,j;
        printf("Enter number of people: ");
        scanf("%d",&n);
        printf("Enter cost matix (rows represent people,columns represent jobs)\n");
        for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                        scanf("%d",&cost[i][j]);
        for(i=0;i<n;i++)
         for(j=0;j<n;j++)
              printf("%d ",cost[i][j]);
        for(i=0;i<n;i++)
                    {
                        visited[i]=0;
                        bound=bound+init(cost[i],n,i);
                    }
         printf("\nLower bound: %d\n",bound);
         assignment(cost,n,0);
         printf("The optimal solution is:\n");
         for(i=0;i<n;i++)
        {
                       printf("Person %d is assigned job %d of cost %d\n",i+1,jb[i],curr[i]);
		       totcost+=curr[i];

                    }

                  printf("\nTotal cost: %d",totcost);

                  return 0;
         }

