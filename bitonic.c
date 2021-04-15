#include<stdio.h>
#include<stdlib.h>
 int count=0;
void swap(int *x,int *y)
{
int t=*x;
*x=*y;
*y=t;
}

/*The parameter dir indicates the sorting direction, ASCENDING 
   or DESCENDING; if (a[i] > a[j]) agrees with the direction, 
   then a[i] and a[j] are interchanged.*/
void compAndSwap(int a[], int i, int j, _Bool dir) 
{ 
count++;
    if (dir==(a[i]>a[j])) 
        swap(a+i,a+j); 

} 
  
/*It recursively sorts a bitonic sequence in ascending order, 
  if dir = 1, and in descending order otherwise (means dir=0). 
  The sequence to be sorted starts at index position low, 
  the parameter cnt is the number of elements to be sorted.*/
void bitonicMerge(int a[], int low, int cnt, _Bool dir) 
{ 
    if (cnt>1) 
    {
        int k = cnt/2; 
        for (int i=low; i<low+k; i++) 
            compAndSwap(a, i, i+k, dir); 
        bitonicMerge(a, low, k, dir); 
        bitonicMerge(a, low+k, k, dir); 
    } 
} 
  
/* This function first produces a bitonic sequence by recursively 
    sorting its two halves in opposite sorting orders, and then 
    calls bitonicMerge to make them in the same order */
void bitonicSort(int a[],int low, int cnt, _Bool dir) 
{ 
    if (cnt>1) 
    {
        int k = cnt/2; 
  
        // sort in ascending order since dir here is 1 
        bitonicSort(a, low, k, 1); 
  
        // sort in descending order since dir here is 0 
        bitonicSort(a, low+k, k, 0); 
  
        // Will merge wole sequence in ascending order 
        // since dir=1. 
        bitonicMerge(a,low, cnt, dir); 
		//printf("bitonic return\n%d\n",count);
    } 


} 
  
/* Caller of bitonicSort for sorting the entire array of 
   length N in ASCENDING order */
void sort(int a[], int N, int up) 
{ 
    bitonicSort(a,0, N, up); 
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
    int up = 1;   // means sort in ascending order 
    sort(a, N, up); 
  
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
		sort(a,i, up);
		printf("\n%d\t%d\t",i,count);

		count=0;
		sort(b,i, up);
		printf("%d\t",count);

		count=0;
		sort(c,i, up);
		printf("%d\n",count);
	}
    return 0; 
} 
