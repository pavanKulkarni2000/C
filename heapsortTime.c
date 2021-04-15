#include<stdio.h>
#include<stdlib.h>
int a[100],n,ct=0;

void swap(int *a,int *b)
{int t=*a;
    *a=*b;
    *b=t;
}


void heapify(int i)
{int left=2*i,right=2*i+1,largest=i;
ct++;

 if((left<=n) && (a[left]>a[largest]))
   largest=left;
if((right<=n) && (a[right]>a[largest]))
   largest=right;
if(largest!=i)
 {swap(a+largest,a+i);
  heapify(largest);
 }
}

void buildheap()
{for(int i=n/2;i>=1;i--)
   heapify(i);
}

void heapsort()
{while(n){
 swap(a+1,a+n);
 n--;
 heapify(1);
 }
}

int main()
{
int i,j,t;
n=2;
printf("\tAsc\t\t\tdes\t\t\trand:\n");

for(i=2;i<8;i++)
{
ct=0;
n*=2;
for(j=0;j<n;j++)
a[j+1]=j;
buildheap();
printf("%d\tbuild:%d ",n,ct);
ct=0;
t=n;
heapsort();
n=t;
printf("sort:%d\t",ct);

ct=0;
for(j=0;j<n;j++)
a[j+1]=n-j;
buildheap();
printf("build:%d ",ct);
ct=0;
t=n;
heapsort();
n=t;
printf("sort:%d\t",ct);

ct=0;
for(j=0;j<n;j++)
a[j+1]=rand()*j%100;
buildheap();
printf("build:%d ",ct);
ct=0;
t=n;
heapsort();
n=t;
printf("sort:%d\t",ct);
printf("\n");
}

}







