#include <stdio.h>
#include<malloc.h>

typedef struct NODE{
    int c;
    struct NODE *next;
} *node;

node get_node(int val){
    node n=(node)malloc(sizeof(struct NODE));
    n->c=val;
    n->next=NULL;
    return n;
}


node insert(int c,node head){
    if(head==NULL)
        return get_node(c);
    
    node temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=get_node(c);
    return head;
    
}

void dfs(int c,unsigned int vis,node ls[],node comp){
    int i;
    node temp=ls[c];
    while(temp){
        i=temp->c;
        if(!(vis & 1u<<i))
        {
            comp=insert(i,comp);
            dfs(i,vis,ls,comp);
        }
        temp=temp->next;
    }
}


int get_connected(node ls[],int n,node *comps){
    unsigned int vis=0;
    int i,ct=0;
    for(i=0;i<n;i++)
    if(!(vis & 1u<<i))
    {
        comps[ct]=insert(i,comps[ct]);
        dfs(i,vis,ls,comps[ct]);
        ct++;
    }

    return ct;
    
}
int get_sum(node head,int cost[]){
    int s=0;
    while(head){
        s+=cost[head->c];
        head=head->next;
    }
    return s;
}

int main(void) {
	
	int n,m,i,x,y;
	scanf("%d %d",&n,&m);
	node ls[n],temp,*comps;
 //intialize the node
for(i=0;i<n;i++)
ls[n]=NULL;
	int cost[n];
	for(i=0;i<m;i++)
	{
	    scanf("%d %d",&x,&y);
	    ls[y-1]=insert(x-1,ls[y-1]);
	    ls[x-1]=insert(y-1,ls[x-1]);
	}
	for(i=0;i<n;i++)
	    scanf("%d",cost+i);
	   
    i=get_connected(ls,n,comps);
    if(i>1)
    {
        int first_max,sec_max,s=0;
        x=get_sum(comps[0],cost);
        y=get_sum(comps[1],cost);
        if(x>y)
            first_max=x,sec_max=y;
        else
            first_max=y,sec_max=x;
        s=x+y;
        for(y=2;y<i;y++)
        {
            x=get_sum(comps[i],cost);
            if(x>first_max)
                sec_max=first_max,first_max=x;
            else if(x>sec_max)
                sec_max=x;
            s+=x;
        }
        printf("%d\n",2*s-first_max-sec_max);
    }
    else
        printf("%d\n",-1);
	return 0;
}















/*
6 6
1 2
2 3
1 3
4 5
5 6
4 6
1
3
5
2
4
6
*/















