#include<stdio.h>
int x[15],used[15];
int adj[15][15];
int path[15][15],wght[15];
int c,min;
int path_ok(int k,int n)
{
        if(used[x[k]])
                return 0;
        if(k<n-1)
      return(adj[x[k-1]][x[k]]);
                return(adj[x[k-1]][x[k]]&&adj[x[k]][x[0]]);
}

void TSP(int k,int n) 
{
        int i,sum;
        for(x[k]=1;x[k]<n;x[k]++)
        {
                if(path_ok(k,n))
                {
                        used[x[k]]=1;
                        if(k==n-1)
                        {
                                sum=0;
                                printf("\n\n possible path is %d",c+1);
                                for(i=0;i<n;i++)
                                {
                                        printf("%d\t",x[i]);
                                        path[c][i]=x[i];
                                        sum+=adj[x[i]][x[i+1]];
                                }
                                printf(" %d",sum);
                                wght[c]=sum;
                                if(c==0||sum<min)
                                        min=sum;
                                c++;
                                used[x[k]]=0;
                        }
                        else
                                TSP(k+1,n);
                        used[x[k]]=0;
                }
        }
}
void findmin(int n)
{
        int i,j;
        for(i=0;i<c;i++)
                if(wght[i]==min)
                {
                        printf("\n\n min path");
                        for(j=0;j<n;j++)
                                printf("%d\t",path[i][j]);
                }
}
main()
{
        int i,j,n,x,y,z;
        printf("enter number of cities\n");
        scanf("%d",&n);
        printf("enter cost of edges\ne e w\n");
        for(i=0;i<n;i++)
          for(j=i;j<n;j++)
		adj[i][j]=0;
	while(1)
                {

                        scanf("%d",&x);
			if(x==-1) break;

                        scanf("%d",&y);
			if(y==-1) break;

                        scanf("%d",&z);
			if(z==-1) break;

                        adj[x][y]=adj[y][x]=z;
                }

used[0]=1;
TSP(1,n);
if(!c)
        printf("no hamaltoninan circuit found");
else
{
printf("\nminimum cost is %d \n",min);
findmin(n);
}
}

