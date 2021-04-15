/*Linear search
Binary search*/

#include<stdio.h>
#include<stdlib.h>
int count=0;

void linsea(int a[],int n,int key)
{
	int i=0;count=0;
	while(i<n&&a[i]!=key)
	{
		i++;count++;
	}
	

}

void binsea(int a[],int key,int low,int high)
{
	int mid;
	if(low>high)
	{
		
		return;
	}
	mid=(low+high)/2;
	if(key>a[mid])
	{
	count++;
	binsea(a,key,mid+1,high);
	}
	else if(key<a[mid])
	{
	count++;
	binsea(a,key,low,mid-1);
	}
	else
	{
	count++;


	

	return;
	}	

	
}

main()
{
	int ch,mid,key,a[520],n,i,low,high,j,c1,c2;

	printf("enter the number of elements ");
	scanf("%d",&n);

	printf("enter the elements ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the element to be searched for ");
	scanf("%d",&key);
	
	while(1)
	{
		printf("\nmenu\n1.linear search\n2.binary search\n");
		printf("enter the choice ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				linsea(a,n,key);
				for(i=16;i<520;i=i*2)
				{
					for(j=0;j<i;j++)
					a[j]=j;
					linsea(a,j,a[0]);
					c1=count+1;
					linsea(a,j,a[j-1]);
					c2=count+1;
					printf("no of elements:%d,bestcase:%d,worstcase:%d\n",j,c1,c2);
				}

				break;
			case 2:
				binsea(a,key,0,n-1);
				for(i=16;i<520;i=i*2)
				{
					for(j=0;j<i;j++)
					a[j]=j;
					mid=(j-1)/2;
					count=0;
					binsea(a,a[mid],0,j-1);
					c1=count;
					count=0;
					binsea(a,a[0],0,j-1);
					c2=count;
					printf("no of elements:%d,bestcase:%d,worstcase:%d\n",j,c1,c2);
				}
				break;

			default:
				exit(0);
			}
	}
}


