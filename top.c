#include<stdio.h>
int n,m[10][10],stack[10],top=-1,c=0;
_Bool visit[10],s[10];

void dfs(int v)
{int i;
visit[v]=s[v]=1;
for(i=0;i<n;i++)
if(m[v][i])
if(!visit[i])
dfs(i);
else
if(s[i])
{//Graph is cyclic
for(i=0;i<n;i++)
visit[i]=1;
c=1;
break;
}
s[v]=0;
stack[++top]=v;
}

void topological()
{int i;
for(i=0;i<n;i++)
{visit[i]=s[i]=0;
}
for(i=0;i<n;i++)
if(!visit[i])
dfs(i);
if(c)
printf("The graph is cyclic!\n");
else
while(top+1)
printf("%d\t",stack[top--]);
printf("\n");
}

int main()
{printf("enter n\n");
scanf("%d",&n);
printf("enter edges\n");
int x,y,i,j;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
m[i][j]=0;
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


