#include<stdio.h>

#include<stdlib.h>



int stack[10], backE[10] ,vis[10],n,a[10][10],c=0,top=-1;

int dfs(int u)
{
	vis[u]=backE[u]=1;
	for(int i=0;i<n;i++)
		if(a[i][u] )
			if( !vis[i])
				dfs(i);
			else
				if(backE[i])
					{c=1;break;}
	backE[u]=0;
	stack[++top]=u;
}

void topo()
{
	int i,u;
	for(i=0;i<n;i++)
	vis[i]=0;
	for(i=0;i<n;i++)
		if(!vis[i])
			dfs(i);
	if(c)
		printf("graph is cyclic");
	else
		for(i=0;i<=top;i++)
			printf("%d\t",stack[i]);
	printf("\n");
	
}

int main()
{
	int i,j;
	printf("\n topo sort");
	printf("\nenter the number of vertices ");
	scanf("%d",&n);
	printf("enter the edges \n");
	while(1)
	{
		scanf("%d",&i);
		if(i==-1)
		break;
		scanf("%d",&j);
		if(j==-1)
		break;
		a[i][j]=1;
	}
	topo();
	return 0;
}



