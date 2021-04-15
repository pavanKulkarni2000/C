#include<stdio.h>
int count=0;
void heapup(int a[],int i)
{
        int b;
        b=a[i];
        count+=2;
        while(i>0&&a[(i-1)/2]<b)
        {
                a[i]=a[(i-1)/2];
                i=(i-1)/2;
        }
        a[i]=b;
}
void heapdown(int a[],int n)
{
        int b,i,j;
        b=a[0];
        i=0;
        j=2*i+1;
        count++;
        while(j<n)
        {
                if((j+1)<n&&a[j]<a[j+1])
                        j=j+1;
                if(a[j]<b)
                        break;
                a[(j-1)/2]=a[j];
                j=2*j+1;
        }
        a[(j-1)/2]=b;
}
void heapsort(int a[],int n)
{
        int i,tempn,temp;
        for(i=1;i<n;i++)
                heapup(a,i);
        tempn=n;
        for(i=0;i<tempn;i++)
        {
                count++;
                temp=a[0];
                a[0]=a[n-1];
                a[n-1]=temp;
                n=n-1;
                heapdown(a,n);
        }
}
main()
{
        int a[520],i,j,n,c1,c2,c3;
        printf("\n Enter the number of elements in the array : ");
        scanf("%d",&n);
        printf("\n Enter the array elements : \n");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        printf("\n The unsorted array : \n");
        for(i=0;i<n;i++)
                printf("%d\t",a[i]);
        heapsort(a,n);
        printf("\n The sorted array : \n");
        for(i=0;i<n;i++)
                printf("%d\t",a[i]);
        printf("\n");
        for(i=16;i<513;i=i*2)
        {
                count=0;
                for(j=0;j<i;j++)
                        a[j]=j;
                heapsort(a,i);
                        c1=count;
                count=0;
                for(j=0;j<i;j++)
                        a[j]=i-j;
                heapsort(a,i);
                        c2=count;
                count=0;
                for(j=0;j<i;j++)
                        a[j]=rand();
                heapsort(a,i);
                        c3=count;
                printf("\n%d\t\t%d\t\t%d\t\t%d\n",i,c1,c2,c3);
        }
}

