#include<stdio.h>
int max(int a,int b)
{
        return(a>b?a:b);
}
void knapsack(int n,int m,int w[20],int v[20][20],int p[20])
{
        int i,j;
        for(i=0;i<=n;i++)
        {
                for(j=0;j<=m;j++)
                {
                        if(i==0||j==0)
                                v[i][j]=0;
                        else if(w[i]>j)
                                v[i][j]=v[i-1][j];
                        else
                                v[i][j]=max(v[i-1][j],(v[i-1][j-w[i]]+p[i]));
                        printf("%d\t",v[i][j]);
                }
		printf("\n");
        }
}
void printoptimalsolution(int n,int m,int w[20],int v[20][20])
{
        int i,j,x[10];
        printf("\noptimal solution is %d\n",v[n][m]);
        for(i=0;i<n;i++)
                x[i]=0;
        i=n;
        j=m;
        printf("\nObj's to be selected:");
        while(i!=0 && j!=0)
        {
                if(v[i][j]!=v[i-1][j])
                {
                        x[i]=1;

                  printf("\n%d",i);
                        j=j-w[i];
                }
                i=i-1;
        }
        printf("\n");
}
int main()
{
        int m,n,i,j,p[20],w[20],v[20][20];
        printf("\nenter the number of objects:");
        scanf("%d",&n);
        printf("\nenter weights of %dobjects:",n);
        for(i=1;i<=n;i++)
                scanf("%d",&w[i]);
        printf("\nenter profits respectively:");
        for(i=1;i<=n;i++)
                scanf("%d",&p[i]);
        printf("enter the capacity of the knapsack\n");
        scanf("%d",&m);
        knapsack(n,m,w,v,p);
        printoptimalsolution(n,m,w,v);
        return 0;
}

