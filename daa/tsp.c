#include<stdio.h>
#include<stdlib.h>
#define inf 999
int n,h,m[10][10],min[10][2],src;


typedef struct NODE{
int n;
int city;
int visited[10];
int path[10];
int lb;
} node;

node* a[100];
node* soln=NULL;

node* getnode(node* p, int city)
{
int i,j,lb=0,fi,se,f,s;
	node* new=(node*)malloc(sizeof(node));
	new->city=city;
	if(p)
	{
		new->n=p->n+1;
		for( i=0;i<n;i++)
			new->visited[i]=p->visited[i],new->path[i]=p->path[i];
	}
	else
	{
		new->n=1;
		for( i=0;i<n;i++)
			new->visited[i]=0,new->path[i]=-1;
	}
	new->path[new->n-1]=city;
	new->visited[city]=new->n;
	
	//lb
	if(!p)
	{

		for(i=0;i<n;i++)
		{	
			fi=inf,se=inf,f=-1,s=-1;
			for(j=0;j<n;j++)
				if(m[i][j]<fi)
					se=fi,fi=m[i][j],s=f,f=j;
				else if(m[i][j]<se)
					se=m[i][j],s=j;
			min[i][0]=f;
			min[i][1]=s;
			printf("\n%d %d",fi,se);
			lb+=fi+se;
		}

	printf("\nlb=%d\n\n",lb/2);

	}
	else{

		for(i=0;i< new->n-1;i++)
		{	lb+=2*m[new->path[i]][new->path[i+1]];  }
		if(new->n!=n)
		{
				for(i=0;i<n;i++)
					if(!new->visited[i])
						lb+=m[min[i][0]][i]+m[min[i][1]][i];

				if(new->n!=n)
				if(min[new->path[0]][0] != new->path[1])
					lb+=m[ min[new->path[0]][0] ][new->path[0]];
				else
					lb+=m[ min[new->path[0]][1] ][new->path[0]];

				if(min[new->path[new->n-1]][0] != new->path[new->n-2])
					lb+=m[ min[new->path[new->n-1]][0] ][new->path[new->n-1]];
				else
					lb+=m[ min[new->path[new->n-1]][1] ][new->path[new->n-1]];
		}
		else
		{	lb+=2*m[new->path[n-1]][src]; }


	}
	new->lb=lb;
	return new;
}

void swap(node **a,node **b)
{node* t=*a;
    *a=*b;
    *b=t;
}



void heapify(int i)
{int left=2*i,right=2*i+1,largest=i;

 if((left<=h) && (a[left]->lb < a[largest]->lb || (a[left]->lb==a[largest]->lb && a[left]->n>a[largest]->n)) )
   largest=left;
if((right<=h) && (a[right]->lb < a[largest]->lb|| (a[right]->lb==a[largest]->lb && a[right]->n>a[largest]->n)))
   largest=right;
if(largest!=i)
 {swap(a+largest,a+i);
  heapify(largest);
 }
}


node* delete(void)
{
node* leaf=a[1];
a[1]=a[h];
h--;
heapify(1);
return leaf;
}


void print(node* no)
{
printf(" city=%d\n",no->city);
for(int i=0;i<no->n;i++)
printf("%d\t",no->path[i]);
printf("\nlb=  %d\n\n",no->lb);
}


void insert(node* new)
{
	
	if(new->n==n){
		soln=new;
		return;
	}
	a[++h]=new;
	int c,p;
	print(new);
	c=h;
	p=c/2;
	while(p>0 && (a[p]->lb > a[c]->lb || (a[p]->lb == a[c]->lb && a[p]->n < a[c]->n)))
	{
		swap(a+p,a+c);
		c=p;
		p=c/2;
	}
}

/*
int LB(node* c, int j)
{int i;
for(i=0;i<n;i++)
	if(!c->visited[i])
		lb+=min[i][0]+min[i][1];
for(i=1;i<c->n-1;i++)
	lb+=m[i-1][i]+m[i][i+1];


int lb=c->lb;
lb+=-min[c->city][0]-min[c->city][1]-min[i][1]-min[i][0];
lb+=
lb+=2*m[c->city][i];
return lb;
}
*/
void TSP()
{
	int i,citiesCovered=1,d,lb;
	h=0;
	node* c=getnode(NULL,src);
	a[++h]=c;
	do
	{
		c=delete();

		printf("level %d\n--------------------------------------\n",c->n);

		for(i=0;i<n;i++)
		{
			d=m[c->city][i];
			if(!c->visited[i] && d!=inf)
			{
				insert(getnode(c,i));
			}
		}
		citiesCovered=c->n+1;
		lb=c->lb;
		free(c);

		printf("\n\n\n");

		//if(citiesCovered==n && a[1]->n==n && a[1]->lb<=lb)
		if(soln){
			printf("got the soln!");
			break;
		}
	}while(1);

}



int main()
{
	int i,j,d,cost=inf;
	printf("Enter No. of Cities: ");
	scanf("%d",&n);
	printf("\nEnter Cost Matrix: \n");
	for( i=0;i<n;i++)
	{
		for( j=0;j<n;j++)
		{
			scanf("%d",&d);
			if(d==0)
				d=inf;
			m[i][j]=m[j][i]=d;
		}
	}

	printf("\n\nThe cost list is:\n\n");

	for( i=0;i<n;i++)

	{
		printf("\n");

		for( j=0;j<n;j++)

			printf("\t%d",m[i][j]);

		printf("\n");
	}

	while(1)
	{
		printf("enter src:\n");

		scanf("%d",&src);

		if(src<n)
			break;

		printf("invalid src!\n");
	}

	TSP();

	printf("Soultion with cost : %d\n\n",soln->lb/2);

	for (i=0;i<soln->n;i++)
		printf("%d--->",soln->path[i]);
	printf("%d\n\n\n",src);

	free(soln);	

/*
	node * result=delete();

	
	printf("Soultion with cost : %d\n\n",result->lb/2);

	for (i=0;i<result->n;i++)
		printf("%d--->",result->path[i]);
	printf("%d\n\n\n",src);

free(result);

	while(h && a[1]->n==n && a[1]->lb==result->lb)
	{
		result=delete();

		for(i=0;i<n;i++)
			printf("%d--->",result->path[i]);
		printf("%d\n\n",src);

		free(result);

	}*/

	while(h)
		free(delete());

		

}
/*

0 3 1 5 8
3 0 6 7 9
1 6 0 4 2
5 7 4 0 3
8 9 2 3 0


*/






