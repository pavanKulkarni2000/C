#include<stdio.h>
int i,j,k,a,b,u,v,n,ne=1;

int visited[10],min,mincost,cost[10][10];
int main()
{
	printf("\n enter no of nodes ");
	scanf("%d",&n);
	printf("\n enter cost ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
	printf("edges of spanning tree are ");
	visited[0]=1;
	while(ne<n)
	{
		for(i=0,min=999;i<n;i++)
		{
			for(j=0;j<n;j++)
				if(cost[i][j]<min)
				{
					if(visited[i]==0)
						continue;
					else
					{
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
				}
		}
		if(visited[u]==0||visited[v]==0)
		{
			printf("\n%d edge (%d,%d)= %d" ,ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\nmincost=%d\n",mincost);
	return 0;
}

