#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int count=0;
void swap(int a[],int b[])
{int t=*a;
*a=*b;
*b=t;
}
int partition(int a[],int l,int h)
{
	int i,j,key;
	key=a[l];
	i=l+1;
	j=h;
	while(1)
	{
		for(;++count && a[i]<=key && i<h;i++);
		for(;++count && a[j]>key && j>l;j--);
		if(i<j)
			swap(a+i,a+j);
		else
			break;
	}
	swap(a+l,a+j);
	return j;
}

void quicksort(int a[],int l,int h)
{
	int p;
	if(l<h)
	{
		p=partition(a,l,h);
		quicksort(a,l,p-1);
		quicksort(a,p+1,h);
	}
}

main()
{
	int a[600],b[600],c[600],i,j,c1,c2,c3,n;
	printf("QUICK SORT\n");
	printf("\nenter the size of arry: ");
	scanf("%d",&n);
	printf("\nenter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	count=0;
	quicksort(a,0,n-1);
	printf("\narray after sorting: ");
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
	printf("\nno of counts: %d",count);
	printf("\n\nsize\tasc\tdesc\trandom\n");
	for(i=16;i<520;i*=2)
	{
		for(j=0;j<i;j++)
		{
			a[j]=j;
			b[j]=i-j;
			c[j]=rand()%i;
		}
		count=0;
		quicksort(a,0,i-1);
		c1=count;

		count=0;
		quicksort(b,0,i-1);
		c2=count;

		count=0;
		quicksort(c,0,i-1);
		c3=count;

		printf("\n%d\t%d\t%d\t%d",i,c1,c2,c3);
	}
	printf("\n");
}
