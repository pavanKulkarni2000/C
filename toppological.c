#include<stdio.h>
#include<stdlib.h>
int stack[100],n,top=-1;
_Bool m[100][100],vis[100],back[100],cycle;

void dfs(int v)
{int i;
vis[v]=back[v]=1;
for(i=0;i<n;i++)
if(m[v][i])
if(!vis[i])
dfs(i);
else if(back[i])
{
cycle=1;
printf("backedge from %d to %d\n",i,v);
for(i=0;i<n;i++)
vis[i]=1;
}
back[v]=0;
stack[++top]=v;
}

void topological()
{int i;
for(i=0;i<n;i++)
vis[i]=back[i]=0;
for(i=0;i<n;i++)
if(!vis[i])
dfs(i);
if(cycle) 
printf("Graph has a cycle\n");
else
while(top+1)
printf("%d\t",stack[top--]);
}

int main()
{int x,y,i,j;
printf("enter vertecies:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
for(j=0;j<n;j++)
m[i][j]=0;
printf("enter edges:\n");
while(1)
{
scanf("%d",&x);
if(x==-1)
break;
scanf("%d",&y);
if(y==-1)
break;
m[x][y]=1;
}
topological();
}

