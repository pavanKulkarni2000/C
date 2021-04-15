#include<stdio.h>
int a[10],n;

void swap(int *a,int *b)
{int t=*a;
*a=*b;
*b=t;
}

void heapify(int i)
{int left=2*i,right=2*i+1,l=i;
if(left>=n && a[l]<a[left])
 l=left;
if(rightt>=n && a[l]<a[right])
 l=right;
if(l!=i)
 {swap(a+l,a+i);
heapify(l);}

}
void buildheap()
{for(int i=n/2;i>=1;i--)
  heapify(i);
}

void exatractmax()


