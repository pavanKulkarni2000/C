#include<stdio.h>
void bfs(int n,int a[10][10], int source, int visited[10])
{
	int i,q[10],u;
	int front=1,rear=1;
	q[rear]=source;
	visited[source]=1;
	while(front<=rear)
	{
		u=q[front];
		printf("\t%d\t",u);
		front=front++;
		for(i=1;i<=n;i++)
		{
			if(a[u][i]==1&&visited[i]==0)
			{
				rear=rear+1;
				q[rear]=i;
				visited[i]=1;
			}
		}
	}
}

int main()
{
	int n,a[10][10],i,j,source,visited[10];
	printf("\nenter the number of nodes:");
	scanf("%d",&n);
	printf("\nenter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	printf("\nenter the source node:");
	scanf("%d",&source);
	for(i=1;i<=n;i++)
		visited[i]=0;
	bfs(n,a,source,visited);
}

