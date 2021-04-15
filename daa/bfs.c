#include<stdio.h>

#include<stdlib.h>



int n,v[10],a[10][10];

int bfs(int u)
{
	int q[10],f=-1,r=-1,i;
	q[++r]=u;
	f++;
	while(f<=r)
	{
		u=q[f++];
		for(i=0;i<n;i++)	
			if(a[i][u] && !v[i])
			{	q[++r]=i;
				v[i]=1;
				printf(" %d\t",i);
			}
	}
}
int connectivity()
{
	int i,comp=0;
	for(i=0;i<n;i++)
		v[i]=0;
	for(i=0;i<n;i++)
		if(!v[i])
		{
			printf("\ncomp :%d\n",comp++);
			bfs(i);
			printf("\n");
		}
	return comp;
}

int main()
{
	int i,j;
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
		a[i][j]=a[j][i]=1;
	}
	if(connectivity()==1)
		printf("Connected!\n");
	else
		printf("Disconnected!\n");
	return 0;
}



