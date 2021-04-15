#include<stdio.h>
#include<stdlib.h>

typedef struct STACK
{int st[10];
int top;
} stack;

void push(stack *s,int n)
{

s->st[++s->top]=n;
}

int pop(stack *s)
{return s->st[s->top--];
}

void top3(stack *s)
{if(s->top<2)
 {printf("Insuffecient elements.\n");
  return ;
  }
 stack temp;
 temp.top=-1;
 int i,Y;
 for(i=0;i<2;i++)
 push(&temp,pop(s));

 Y=pop(s);
 printf("%d\n",Y);
 push(s,Y);
 
 for(i=0;i<2;i++)
 push(s,pop(&temp));
}

void last3(stack *s)
{if(s->top<2)
 {printf("Insuffecient elements.\n");
  return ;
  }
 stack temp;
 temp.top=-1;
 int i,Y;
 for(i=0;s->top>2;i++)
 push(&temp,pop(s));

 Y=pop(s);
 printf("%d\n",Y);
 push(s,Y);
 
 for(i=0;temp.top!=-1;i++)
 push(s,pop(&temp));
}

int *popn(stack *s,int n)
{if(s->top>n-1)
 {printf("Insuffecient elements.\n");
   return NULL;
  }
 int *a=(int *)calloc(n,sizeof(int));
 for(int i=0;i<n;i++)
  a[i]=pop(s);
 return a;
}

int main()
{int n,ch,*a,ele;
stack s;
s.top=-1;
while(1)
{printf("Enter the choice\n1.push\n2.pop\n3.popn\n4.top3\n5.last3\nexit\n");
scanf("%d",&ch);
switch(ch)
{case 1:printf("Enter the element\n");
scanf("%d",&ele);
push(&s,ele);
printf("Pushed\n");
break;
case 2:ele=pop(&s);
printf("the element poped %d\n",ele);
printf("Poped\n");
break;
case 3:printf("Enter the number of element\n");
scanf("%d",&n);
a=popn(&s,n);
printf("the elements poped \n");
while(n!=0)
printf("%d\n",a[n]);
printf("Poped\n");
break;
case 4:top3(&s);
break;
case 5:last3(&s);
break;
default:return 1;
}
}
return 0;
}
