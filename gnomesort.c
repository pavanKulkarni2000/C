#include<stdio.h>
#include<stdlib.h>
 int count=0;
void swap(int *x,int *y)
{
int t=*x;
*x=*y;
*y=t;
}

void gnomeSort(int arr[], int n) 
{ 
    int index = 0; 
  
    while (index < n) { 
count++;
        if (index == 0) 
            index++; 
        if (arr[index] >= arr[index - 1]) 
            index++; 
        else { 
            swap(arr+index, arr+index - 1); 
            index--; 
        } 
    } 
    return; 
} 
  
// Driver code 
int main() 
{ 
int N,i,j,a[1000],b[1000],c[1000];

printf("Enter n\n");
scanf("%d",&N);

printf("Enter n values\n");
for(i=0;i<N;i++)
scanf("%d",a+i);

gnomeSort(a, N); 
  
    printf("Sorted array: \n"); 
    for (int i=0; i<N; i++) 
        printf("%d ", a[i]); 

        printf("\n%d \n", count); 


	printf("\n\nsize\tasc\tdesc\trandom\n");
	for(i=4;i<520;i*=2)
	{
		for(j=0;j<i;j++)
		{
			a[j]=j;
			b[j]=i-j;
			c[j]=rand()%i;
		}
		count=0;
		gnomeSort(a,i);
		printf("\n%d\t%d\t",i,count);

		count=0;
		gnomeSort(b,i);
		printf("%d\t",count);

		count=0;
		gnomeSort(c,i);
		printf("%d\n",count);
	}
    return 0; 
} 
