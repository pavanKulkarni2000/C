#include<stdio.h>
void warshall(int n,int a[][10],int p[10][10])
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			p[i][j]=a[i][j];
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(p[i][k]==1&&p[k][j]==1)
					p[i][j]=1;
}
void read(int n,int a[][10])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
		printf("\n\t");
	}
}
 void write(int n,int a[][10])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n\t");
	}
}

main()
{
	int n,a[10][10],p[10][10];
	printf("\n\tenter no of nodes : ");
	scanf("%d",&n);
	printf("\n\tenter cost of adjacency matrix : \n\t");
	read(n,a);
	warshall(n,a,p);
	printf("\n\ttransitive closure :\n\t");
	write(n,p);
	return 0;
}

