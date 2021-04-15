#include<stdio.h>
#include<stdlib.h>
int count=0;

int selection(int a[],int n)
{
	int i,j,temp;

	for(i=0;i<n-1;i++)
	{
		
		for(j=i+1;j<n;j++)
		{
			count++;
			if(a[j]<a[i])
			{
			count++;	
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			}
		}
	}
}


main()
{
	int i,j,k,n,temp,a[600],b[600],c[600],c1,c2,c3,pos;
	printf("enter the number of elements ");
	scanf("%d",&n);
	printf("enter the items to sort ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selection(a,n);

	printf("\nsorted list is : ");
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
		selection(a,i);
		c1=count;
		count=0;
		selection(b,i);
		c2=count;
		count=0;
		selection(c,i);
		c3=count;

		printf("\nno of elements:%d,best case:%d,worst case:%d,average case:%d",i,c1,c2,c3);
	}

	
}


