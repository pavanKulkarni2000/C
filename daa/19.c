#include<stdio.h>
int main()
{
int i,j,a,b,u,v,n,m=1,min,mincost=0;
int cost[9][9],parent[9];
printf("\n\t kruskal algorithm");
printf("\n enter no of vertices");
scanf("%d",&n);
printf("\n enter adjacency matrix");
for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
                parent[i]=0;
                scanf("%d",&cost[i][j]);
                if(cost[i][j]==0)
                        cost[i][j]=999;
        }
printf("\n edges of spanning tree are");
while(m<n)
{
        for(i=1,min=999;i<=n;i++)
                for(j=1;j<=n;j++)
                        if(cost[i][j]<min)
                        {
                                min=cost[i][j];
                                a=u=i;
                                b=v=j;
                        }
        while(parent[u])
                u=parent[u];
        while(parent[v])
                v=parent[v];
        if(u!=v)
	{
                printf("\n\t %d edge(%d %d)=%d",
                                m++,a,b,min);
                mincost+=min;
                parent[v]=u;
        }
        cost[a][b]=cost[b][a]=999;
}
printf("\n\t min cost=%d",mincost);
return 0;
}

