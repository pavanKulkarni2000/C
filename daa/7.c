#include<stdio.h>
int count;
int count1;
void dfs2(int ,int [][20], int [], int);
void dfs1(int a[][20],int b[], int n)
{
	int i,s;
	printf("enter the source vertex:");
	scanf("%d",&s);
	count++;
	printf("node reachable from source (%d) are :",s);
	dfs2(s-1,a,b,n);
	/*for(i=0;i<n;i++)
	{
		if(b[i]==0)
		{
			count1++;
			dfs2(i,a,b,n);
		}
	}
	printf("\nthe no of components = %d\n",count1);*/
}
void dfs2(int v, int a[][20],int b[], int n)
{
	int i;
	b[v]=++count;
	for(i=0;i<n;i++)
	{
		if(a[v][i]==1&&b[i]==0)
		{
			if(count)
			printf("%5d",i+1);
			dfs2(i,a,b,n);
		}
	}
}

int main()
{
	int a[20][20],b[20],n,i,j;
	printf("\nenter the no of vertices:");
	scanf("%d",&n);
	printf("\nenter the adjacency matri\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
		b[i]=0;
	}
	count1=1;
	count=0;
	dfs1(a,b,n);
	return 0;
}

