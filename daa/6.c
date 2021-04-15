#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int i,j,v,x,u,n,flag=0;
int visited[10],cost[10][10];

void dfs(int v)
{
	int w;
	visited[v]=1;
	for(w=0;w<n;w++)
	{
		if(cost[v][w]==1&&visited[w]==0)
			
		dfs(w);
	}
}

int main()
{
	
	printf("\n\tenter no of vertices:\n");
	scanf("%d",&n);
	printf("enter cost of matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&cost[i][j]);
	dfs(0);
	for(i=1;i<n;i++)
	{
		if(visited[i]==0)
			flag=1;
	}
	
	if(flag==0)
		printf("\nthe graph is connected \n");
	else
		printf("\nthe graph is disconnected \n");
}

