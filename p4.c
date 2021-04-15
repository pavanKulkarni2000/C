#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{int coef,exp;
 struct NODE *next;
} node;

node *getnode(int coef,int exp)
{
node *item=(node *)malloc(sizeof(node));
item->next=NULL;
item->coef=coef;
item->exp=exp;
return item;
}

node * insertrear(node *head,int coef,int exp)
{node *new=getnode(coef,exp),*temp;
if(head==NULL)
return new;
for(temp=head;temp->next!=NULL;temp=temp->next);
temp->next=new;
return head;
}

void multiply(node *head1,node *head2,node *head3)
{node *p,*q,*temp;
int coef,exp,flag;
for(p=head1;p!=NULL;p=p->next)
for(q=head2;q!=NULL;q=q->next)
{coef=p->coef*q->coef;
exp=p->exp+q->exp;
flag=0;
for(temp=head3;temp!=NULL;temp=temp->next)
if(temp->exp==exp)
{temp->coef+=coef;printf("Re\n");
flag=1;
break;}
if(!flag)
 {head3=insertrear(head3,coef,exp);
 printf("New\n");}
}
}
void display(node *head)
{while(head!= NULL )
{printf("%d*x ^ %d\n",head->coef,head->exp);
head=head->next;
}
}

void main()
{int c,e,i,j,n;
node* head[3]={NULL,NULL,NULL};
for(i=0;i<2;i++)
{printf("Enter the no of terms in exp\n");
scanf("%d",&n);
for(j=0;j<n;j++)
{scanf("%d %d",&c,&e);
head[i]=insertrear(head[i],c,e);
}
display(head[i]);
}
multiply(head[0],head[1],head[2]);
display(head[2]);
}




