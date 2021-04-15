#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int count;

void merge(int a[],int l,int m,int h)
{
	int i,j,k,c[10000];
	i=k=l;
	j=m+1;
	while(i<=m&&j<=h)
	{
		count++;
		if(a[i]<a[j])
		c[k++]=a[i++];
		else
		c[k++]=a[j++];
	}
	while(i<=m)
	{c[k++]=a[i++];count++;}
	while(j<=h)
	{c[k++]=a[j++];count++;}
	for(i=l;i<k;i++)
	a[i]=c[i];
}

void mergesort(int a[],int l,int h)
{
	int m;
	//count++;
	if(l<h)
	{
		m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
	}
}

main()
{
	int a[600],b[600],c[600],i,j,c1,c2,c3,n;
	printf("MERGE SORT\n");
	printf("\nenter the size of array:");
	scanf("%d",&n);
	printf("\nenter the elements one by one\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	count=0;
	mergesort(a,0,n-1);
	printf("\narray after sorting:");
	for(i=0;i<n;i++)
		printf("\t%d",a[i]);
	printf("\nno of counts:%d",count);
	printf("\n\nsize\tasc\tdesc\trandom\n");
	for(i=16;i<520;i=i*2)
	{
		for(j=0;j<i;j++)
		{
			a[j]=j;
			b[j]=i-j;
			c[j]=rand()%i;
		}
		count=0;
		mergesort(a,0,i-1);
		c1=count;
		count=0;
		mergesort(b,0,i-1);
		c2=count;
		count=0;
		mergesort(c,0,i-1);
		c3=count;
		printf("\n%d\t%d\t%d\t%d",i,c1,c2,c3);
	}
	printf("\n");
}

