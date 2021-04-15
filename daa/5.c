#include<stdio.h>
#include<stdlib.h>
int count=0;
void insertion(int a[],int n)
{
	int i,j,temp;
	count=0;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0;j--)
		{
			count++;
			if(a[j]>temp)
			{
				a[j+1]=a[j];
			}
			else break;
		}
		a[j+1]=temp;
	}
}


main()
{
	int i,c1,c2,c3,n,j,item,a[600],b[600],c[600];
	printf("enter the number of elements ");
	scanf("%d",&n);

	printf("enter the elements ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertion(a,n);

	printf("\nthe sorted list is : ");

	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}

	for(i=16;i<520;i=i*2)
	{
		for(j=0;j<i;j++)
		{
			a[j]=j;
			b[j]=i-j;
			c[j]=rand()%i;
		}
		count=0;
		insertion(a,i);
		c1=count;
		count=0;
		insertion(b,i);
		c2=count;
		count=0;
		insertion(c,i);
		c3=count;
		printf("\nno of elements:%d,best case:%d,worst case:%d,average case:%d",i,c1,c2,c3);
	}
}

