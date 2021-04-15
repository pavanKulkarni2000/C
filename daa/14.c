#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int mini(int i,int k)
{
	if(i<k)
		return i;
	else
		return k;
}

void bin(int c[][100],int n,int k)
{
	int i,j;
	if(n<k)
	{
		printf("\n\t invalid ");
		exit(0);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=mini(i,k);j++)
		{
			if(j==0||j==i)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int n,i,j,k,c[100][100];
	printf("\n\tenter n: ");
	scanf("%d",&n);
	printf("\n\tenter k : ");
	scanf("%d",&k);
	bin(c,n,k);
	printf("\n\t binomial coefficient : ");
	printf("%d\n",c[n][k]);
getch();
	return 0;
}

