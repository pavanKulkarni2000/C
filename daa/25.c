#include<stdio.h>

int w[10],i,j,p[10],n,m;
float unit[10];
int y[10],x[10],fp=-1,fw;

void get()
{
        printf("Enter number of items: ");
        scanf("%d",&n);
        printf("Enter maximum capacity of knapsack: ");
        scanf("%d",&m);
        for(i=0;i<n;i++)
        {
                printf("Enter weight and profit of %d ",i+1);
                scanf("%d%d",&w[i],&p[i]);
        }
}

void show()
{
        float s=0.0;
        printf("\nItem\tWeight\tCost\tProfit\tSelected");

        for(i=0;i<n;i++)
     printf("\n%d\t%d\t%d\t%f\t%d",i+1,w[i],p[i],unit[i],x[i]);
      printf("\nSack now holds: \n");
        for(i=0;i<n;i++)
        if(x[i]==1)
        {       printf("%d\t",i+1);

        s+=p[i]*x[i];
        }
        printf("\nmaximum profit: %f",s);
}
void sort()
{
        int t,t1;float t2;
        for(i=0;i<n;i++)
                unit[i]=(float)p[i]/w[i];
        for(i=0;i<n;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        if(unit[i]<unit[j])
                       {
                                t2=unit[i];unit[i]=unit[j];unit[j]=t2;
                                t=p[i];p[i]=p[j];p[j]=t;
                                t1=w[i];w[i]=w[j];w[j]=t1;
                        }
                }
        }

}
float bound(float cp,float cw,int k)
{
        float b=cp,c=cw;
        for(i=k;i<=n;i++)
        {
                c+=w[i];
                if(c<m)
                        b+=p[i];
                else
                        return (b+(1-(c-m)/(float)w[i])*p[i]);
        }
        return b;
}
void knapsack(int k,float cp,float cw)

{
        if(cw+w[k]<=m)
        {
                y[k]=1;
                if(k<=n)
                        knapsack(k+1,cp+p[k],cw+w[k]);
                if(((cp+p[k])>fp)&&(k==n))
                {
                        fp=cp+p[k];
                        fw=cw+w[k];
                        for(j=0;j<=k;j++)
                                       x[j]=y[j];
                }
        }
        if(bound(cp,cw,k)>=fp)
        {
                y[k]=0;
                if(k<=n)
                        knapsack(k+1,cp,cw);
                if((cp>fp)&&(k==n))
				{
                        fp=cp;
			            fw=cw;
                        for(j=0;j<=k;j++)
                                x[j]=y[j];
                }
        }
}
main()
{
        get();
        printf("Knapsack is arranged in the order:\n");
        sort();
        knapsack(0,0.0,0.0);
        show();
}


