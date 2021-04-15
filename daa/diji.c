#include<stdio.h>
#define inf 999
int v[10],d[100],c[10][10];
int minUnvis(int n)
{
    int dist=inf,vert;
    for(int i=0;i<n;i++)
        if(!v[i] && d[i]<dist)
            dist=d[i], vert=i;
    return vert;
}
void dijikstra(int n, int u){
    int i,ct=0;
    for(i=0;i<n;i++)
    {    
        d[i]=inf;
        v[i]=0;
    }
    d[u]=0;
    while(ct<n)
    {    
        u=minUnvis(n);
		v[u]=++ct;
        for(i=0;i<n;i++)
            if(!v[i] && d[u]+c[u][i] < d[i])
                d[i]=d[u]+c[u][i];
    }
}
int main(){
    int src,x,y,z,n;
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
/*
    printf("enter edges\n");
    while(1){
        scanf("%d %d %d",&x,&y,&z);
        if(x==-1 || y==-1 || z==-1 )
            break;
        c[x][y]=c[y][x]=z;
    }
*/
    
	while(1)
	{
		printf("enter src:\n");

		scanf("%d",&src);

		if(src<n)
			break;

		printf("invalid src!\n\n");
	}
    dijikstra(n,src);
    printf("\n");
	for(x=0;x<n;x++)
printf("vertex:%d  , distance from source:%d\n\n",x,d[x]);
/*    printf("%d",src);
    while(nxt[src]!=-1)
    {    
        x=nxt[src];
        printf("--%d-->%d",c[x][src],x);
        src=x;
    }
*/
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
