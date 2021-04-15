#include<stdio.h>
int n,d,sum=0,a[10],v[10],flag=0;
int j;

void print()
{
printf("Subset with elements:\n");
for( int i=0;i<n;i++)
if(v[i])
printf("%d\t",a[i]);
printf("\n\n");
}


void dfs(int i){

	if(i>=n)
		return;

	//with ith element
	v[i]=1;
	if (sum+a[i]<d)
	{
		sum+=a[i];
		dfs(i+1);
		sum-=a[i];
	}
	else
	{
		if(sum+a[i]==d)
		{
			flag=1;
			print();
		}
		v[i]=0;
		return;
	}


	//without ith element
	v[i]=0;
	dfs(i+1);

}

void main(){
int prev=-1;
    printf("\nEnter the size of set:");
    scanf("%d",&n);
    
    printf("\nEnter the element of set in ascending order:\n");
    for(j=0;j<n;j++){

        scanf("%d",&a[j]);
		if(a[j]<prev)
		{	
			printf("please enter the elements in ascending order\n\n");
			j=-1;
		}
		else if (a[j]==prev)
		{
			j--;
			printf("please enter non negative non duplicated elements\n");
		}
		else
			prev=a[j];
    }
    printf("\nEnter the sum value:");
    scanf("%d",&d);
    
    dfs(0);
    
    if(flag==0)
        printf("\nNone of the subset matches required condition.\n");

    
}

