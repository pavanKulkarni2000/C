#include<stdio.h>
#include<stdlib.h>
#define inf 999

int v[10],d[100],c[10][10],n,prv[10];

int min_Nbr()
{
    int dist=inf, u=-1;
    for(int i=0;i<n;i++)
    	if(!v[i] && d[i]<dist)
    		dist=d[i], u=i;
    printf("%d-->%d\tweight=%d\n",prv[u],u,dist);
    return u;
}


void prim(int u){

    int i,ct=0;
    for(i=0;i<n;i++)
    {    
    	v[i]=0;
       	prv[i]=u;
       	d[i]=c[u][i];
    }
    v[u]=1;
    do
    {    

        u=min_Nbr();
        
		v[u]=++ct;
        for(i=0;i<n;i++)
            if(!v[i] && c[u][i] < d[i])
                d[i]=c[u][i],prv[i]=u;
    }while(ct<n-1);
}


int main(){
    int src,x,y,z;
    printf("enter number of vertices\n");
    scanf("%d",&n);
    printf("enter matrix\n");
    for(x=0;x<n;x++)
        for(y=0;y<n;y++)
        {
		    scanf("%d",&z);
		    if(z==0)
				z=inf;
		    c[x][y]=z;
		}
for( x=0;x<n;x++)

	{
		printf("\n");

		for( y=0;y<n;y++)

			printf("\t%d",c[x][y]);

		printf("\n");
	}
	
	printf("Edges included\n\n");
    prim(0);
	printf("\n");

    printf("\n");

}




/*
      70
   2 ____ 3
   /\
80/  \6
 /    \
0 ____ 1 ____ 4 ______ 5
   10     20   \  50  /
              10\    /5 
		 \  /
		   6


0 10 80 0 0 0 0
10 0 6 0 20 0 0 
80 6 0 70 0 0 0 
0 0 70 0 0 0 0
0 20 0 0 0 50 10
0 0 0 0 50 0 5
0 0 0 0 10 5 0
*/
