#include<stdio.h>

#include<stdlib.h>



int vis[10],n,a[10][10];

int getZero()
{int i,j,f;
	for(i=0;i<n;i++)
	{
		if(vis[i]) 
			continue;
			
		f=1;

		for(j=0;j<n;j++)
			if(a[j][i])
				{f=0;break;}

		if(f)
			return i;

	}
	return -1;
}

void makeZero(int i)
{
for(int j=0;j<n;j++)
a[i][j]=0;
}

void topo()
{
	int i,u,q[n];
	for(i=0;i<n;i++)
	vis[i]=0;
	for(i=0;i<n;i++)
	{	u=getZero();
		if(u==-1)
			{printf("graph is cyclic");break;}
		q[i]=u;
		vis[u]=1;
		makeZero(u);
	}
	printf("\n");
	
		for(i=0;i<n;i++)
			printf("%d\t",q[i]);
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



