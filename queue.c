#include<stdio.h>
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

int extractmax()
{if(n==0)
  {printf("The heap is empty!\n");
   return -1;
  }
 int max=a[1];
 a[1]=a[n];
 heapify(1);
 n--;
 return max;
}

int main()
{
int i;

while(1)
{printf("Enter the choice:\n1.Build heap\n2.Extract Max\n3.exit\n");
scanf("%d",&i);
switch(i)
{case 1: 
printf("Enter the no of elements:\n");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++)
scanf("%d",a+1+i);
buildheap();
printf("Heap after insertion:\n");
for(i=0;i<n;i++)
printf("%d ",a[1+i]);
printf("\n%d\n",ct);
break;

case 2:printf("max element retrieved is %d \n",extractmax(a));
            printf("heap after deletion is \n");
            for(i=1;i<=n;i++)
                printf("%d ",a[i]);
            break;
    case 3: return 0;
}
}
return 0;
}









