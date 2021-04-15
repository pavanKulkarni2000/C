#include<stdio.h>
int a[100],n,ct=0;

void swap(int *a,int *b)
{int t=*a;
    *a=*b;
    *b=t;
}


void heapify(int i)
{int left=2*i,right=2*i+1,largest=i;

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
{while(n>1){
 swap(a+1,a+n);
 n--;
 heapify(1);
 }
}


void delete()
{
	int num=a[1];
printf("%d\n",num);
a[1]=a[n];
n--;
heapify(n);
}



int main()
{
int i;
printf("Enter the no of elements:\n");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++)
scanf("%d",a+1+i);
buildheap();
printf("Heap after insertion:\n");
for(i=0;i<n;i++)
printf("%d ",a[1+i]);
int ch=0;
while(1)
{
  printf("\n\nchoice :\n");

scanf("%d",&ch);
switch(ch)
{case 1:
printf("value: ");
scanf("%d",&i);
//inset(i);
break;

case 2:
printf("deleted: ");
delete();
break;

case 3:
printf("printing: ");
for(i=1;i<=n;i++)
printf("%d\t",a[i]);
printf("\n");
break;

default:return 0;
}
}

}







