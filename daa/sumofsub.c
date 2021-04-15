#include<stdio.h>
int n,d,sum=0,remaining=0,a[10],s[10],flag=0;
int j;
void sumOfSubset(int i){

    if(sum+s[i] <= d){
        sum+=s[i];
        remaining-=s[i];
        a[i]=1;
        if(sum == d){

            flag=1;
            printf("\nSubset with elements:");
            for(j=0;j<n;j++)
                if(a[j]==1)
                    printf("\t%d",s[j]);
            printf("\n");

        }
        else if(i+1<n)
            sumOfSubset(i+1);
        sum-=s[i];
        remaining+=s[i];
        a[i]=0;
    }
    if(remaining - s[i] >= d-sum){
        remaining-=s[i];
        if(i+1<n)
            sumOfSubset(i+1);
        remaining += s[i];
    }
}
void main(){
int prev=0;
    printf("\nEnter the size of set:");
    scanf("%d",&n);
    
    printf("\nEnter the elements of set:");
    for(j=0;j<n;j++){

        scanf("%d",&s[j]);
		if(s[j]<prev)
		{	
			printf("please enter the elements in ascending order\n\n");
			j=-1;
			remaining=0;
			prev=0;
		}
		else
		{
			prev=s[j];
		    remaining+=s[j];
		}
    }
    printf("\nEnter the sum value:");
    scanf("%d",&d);
    
    sumOfSubset(0);
    
    if(flag==0)
        printf("\nNone of the subset matches required condition.\n");

    
}

