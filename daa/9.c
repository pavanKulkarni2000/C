#include<stdio.h>

#include<stdlib.h>

int j=0,pop[10],vis[10];

int dfs(int u,int n,int a[][10])
{
	int i,v,top=-1,s[10];
	vis[u]=1;
	s[++top]=u;
	while(top!=-1)
	{
		for(v=1;v<=n;v++)
		{
			if(a[u][v]==1&&vis[v]==1)
			{
				for(i=top;i>=0;i--)
					if(s[i]==v)
					{
						printf("\ntopo not poss");
						exit(1);
					}
			}
			if(a[u][v]==1&&vis[v]==0)
			{
				vis[v]=1;
				s[++top]=v;
				u=v;
				v=0;
			}
		}
		j++;
		pop[j]=u;
		top--;
		u=s[top];
	}
}

void topo(int n, int a[][10])
{
	int i,u;
	for(i=1;i<=n;i++)
	vis[i]=0;
	for(u=1;u<=n;u++)
	{
		if(vis[u]==0)
			dfs(u,n,a);
	}
}

int main()
{
	int i,k,n,a[10][10];
	printf("\n topo sort");
	printf("\nenter the number of vertices ");
	scanf("%d",&n);
	printf("enter the adjacency matrix ");
	for(i=1;i<=n;i++)
		for(k=1;k<=n;k++)
		{
			scanf("%d",&a[i][k]);
		}
	topo(n,a);
	printf("\ntopo order is ");
	for(i=n;i>0;i--)
		printf("%d",pop[i]);
	return 0;
}



