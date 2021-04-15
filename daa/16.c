#include<stdio.h>
int min(int a,int b)
{
	if(a<b)
		return a;
	else 
		return b;
}
void floyd(int p[8][8],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<n;i++)
			for(j=1;j<=n;j++)
				p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}


int main()
{
	int j,i,n,a[8][8];
	printf("\nenter no of vertices : ");
	scanf("%d",&n);
	printf("\nenter adjacency matrix : ");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
			a[i][j]=999;
		}
	floyd(a,n);
	printf("\n\t all pair shortest path matrix \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}
	
