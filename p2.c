#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct STACK
{char st[100];
int top;
} stack;

void push(stack *s,char n)
{
s->st[++s->top]=n;
}

char pop(stack *s)
{
return s->st[s->top--];
}

int prec(char c)
{switch(c)
{case '^':
 case '$':return 3;break;
case '*':
 case '/':return 2;break;
case '+':
 case '-':return 1;break;
 default:return 0;break;
}
}

void InfixPostfix(char infix[],char postfix[])
{
int i,j=0;
char c;
stack s;
s.top=-1;
for(i=0;infix[i]!='\0';i++)
{c=infix[i];
 printf("%c\n",c);
 if(isalnum(c))
  postfix[j++]=c;
 else
  if(c=='(' || s.top==-1 || prec(s.st[s.top])<prec(c))
   push(&s,c);
  else if(c==')')
   while((c=pop(&s))!='(')
    postfix[j++]=c;
  else
   {while(prec(s.st[s.top])>=prec(c))
     postfix[j++]=pop(&s);
    push(&s,c);
   }
 }
while(s.top!=-1 )
 postfix[j++]=pop(&s);
postfix[j]='\0';
}


int main()
{char in[100],post[100];
 printf("Enter the infix expression\n");
 scanf("%s",in);
 InfixPostfix(in,post);
 printf("The Postfix expression\n");
 printf("%s\n",post);
return 0;
}
 
