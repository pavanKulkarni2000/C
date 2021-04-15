#include<stdio.h>
#include<stdlib.h>
#define min(a, b) ((a<b)?a:b)
#define RUN 8
int count=0;
void swap(int *x,int *y)
{
int t=*x;
*x=*y;
*y=t;
}
  
// this function sorts array from left index to 
// to right index which is of size atmost RUN 
void insertionSort(int arr[], int left, int right) 
{ int i,j,temp;
    for (int i = left + 1; i <= right; i++) 
    { 
        temp = arr[i];  
		for(j=i-1;++count && j>=left ;j--)
        if( arr[j] > temp) 
            arr[j+1] = arr[j]; 
		else
			break;
        arr[j+1] = temp; 
    } 
} 
  
// merge function merges the sorted runs 
void merge(int arr[], int l, int m, int r) 
{ 
/*
int temp[r-l+1],i,j,k=0;
for(i=l,j=m+1;i<=m && j<=r;k++)
{count++;
if(arr[i]<arr[j])
temp[k]=arr[i++];
else
temp[k]=arr[j++];
}
*/
    // original array is broken in two parts 
    // left and right array 
    int len1 = m - l + 1, len2 = r - m; 
    int left[len1], right[len2]; 
    for (int i = 0; i < len1; i++) 
        left[i] = arr[l + i]; 
    for (int i = 0; i < len2; i++) 
        right[i] = arr[m + 1 + i]; 
  
    int i = 0; 
    int j = 0; 
    int k = l; 
  
    // after comparing, we merge those two array 
    // in larger sub array 
    while (i < len1 && j < len2) 
    { count++;
        if (left[i] <= right[j]) 
        { 
            arr[k] = left[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // copy remaining elements of left, if any 
    while (i < len1) 
    { count++;
        arr[k] = left[i]; 
        k++; 
        i++; 
    } 
  
    // copy remaining element of right, if any 
    while (j < len2) 
    { count++;
        arr[k] = right[j]; 
        k++; 
        j++; 
    } /*

while(count++ && i<=m)
temp[k++]=arr[i++];

while(count++ && j<=r)
temp[k++]=arr[j++];

for(i=l;i<=r;i++)
arr[i]=temp[i];
*/
} 
  
// iterative Timsort function to sort the 
// array[0...n-1] (similar to merge sort) 
void timSort(int arr[], int n) 
{ 
    // Sort individual subarrays of size RUN 
    for (int i = 0; i < n; i+=RUN) 
        insertionSort(arr, i, min((i+RUN-1), (n-1))); 
  
    // start merging from size RUN (or 32). It will merge 
    // to form size 64, then 128, 256 and so on .... 
    for (int size = RUN; size < n; size = 2*size) 
    { 
        // pick starting point of left sub array. We 
        // are going to merge arr[left..left+size-1] 
        // and arr[left+size, left+2*size-1] 
        // After every merge, we increase left by 2*size 
        for (int left = 0; left < n; left += 2*size) 
        { 
            // find ending point of left sub array 
            // mid+1 is starting point of right sub array 
            int mid = left + size - 1; 
            int right = min((left + 2*size - 1), (n-1)); 
  
            // merge sub array arr[left.....mid] & 
            // arr[mid+1....right] 
            merge(arr, left, mid, right); 
        } 
    } 
} 

int main() 
{ 
int N,i,j,a[1000],b[1000],c[1000];

printf("Enter n\n");
scanf("%d",&N);

printf("Enter n values\n");
for(i=0;i<N;i++)
scanf("%d",a+i);

timSort(a, N); 
  
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
		timSort(a,i);
		printf("\n%d\t%d\t",i,count);

		count=0;
		timSort(b,i);
		printf("%d\t",count);

		count=0;
		timSort(c,i);
		printf("%d\n",count);
	}
    return 0; 
} 
