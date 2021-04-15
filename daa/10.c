#include<stdio.h>
int topo(int n, int a[10][10], int indegree[10], int temp[10])
{
	int i,j,k=0;
	for(i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			indegree[i]=-1;
			temp[++k]=i;
			for(j=1;j<=n;j++)
			if(indegree[j]!=0&&a[i][j]==1)
				indegree[j]--;
			i=0;
		}
	}
	return k;
}

int main()
{
	int i,j,a[10][10],m,n,b[10],indegree[10];
	printf("\nenter the no of vertices ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		indegree[i]=0;
	}

	printf("\n\tenter adjacency matrix ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==1)
				indegree[j]++;
		}
	}
	m=topo(n,a,indegree,b);
	if(m!=n)
		printf("\n\tnot posible");
	else
	{
		printf("\n\ttopological ordering is ");
		for(i=1;i<=n;i++)
			printf("%d",b[i]);
	}
	return 0;
}

