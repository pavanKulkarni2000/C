#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct tree
{char info;
 struct tree *left,*right;
} * node;

typedef struct STACK
{node st[10];
 int top;
} stack;


void inorder(node root)
{if(root!=NULL)
{
 inorder(root->left);
 printf("%c ",root->info);
 inorder(root->right);
}
}


node pop(stack *s)
{
return s->st[s->top--];
}
void push(node n,stack *s)
{
s->st[++s->top]=n;
}



node getnode(char c)
{node item=(node)malloc(sizeof(struct tree));
item->info=c;
item->left=item->right=NULL;
return item;
}

int precedence(char c)
{switch(c)
{case '^':
 case '$':return 3;
case '*':
 case '/':return 2;
case '+':
 case '-':return 1;
 default:return 0;
}
}

node ExpTree(char *infix)
{int i;char c;
node temp,t;
stack exp,opr;
exp.top=opr.top=-1;
for(i=0;infix[i]!='\0';i++)
{c=infix[i];
t=getnode(c);
if(isalnum(c))
  push(t,&exp);
else 
 {if(c=='(' || opr.top==-1 || precedence((opr.st[opr.top])->info)<precedence(c))
  push(t,&opr);
 else if(c==')')
  {while(((opr.st[opr.top])->info)!='(')
   {temp=pop(&opr);
    temp->right=pop(&exp);
    temp->left=pop(&exp);
    push(temp,&exp);
inorder(temp);
printf("\n");
   }
   pop(&opr);
  }
  else
   {while(opr.top!=-1 && exp.top!=-1 && precedence((opr.st[opr.top])->info)>=precedence(c) )
    {temp=pop(&opr);
     temp->right=pop(&exp);
     temp->left=pop(&exp);
     push(temp,&exp);
inorder(temp);
    }
    push(t,&opr);
   }
 }
}
printf("End popping\n");
while(opr.top!=-1 && exp.top!=-1)
    {temp=pop(&opr);
     temp->right=pop(&exp);
     temp->left=pop(&exp);
     push(temp,&exp);
inorder(temp);
    }
return pop(&exp);
}


void preorder(node root)
{if(root!=NULL)
{printf("%c ",root->info);
 preorder(root->left);
 preorder(root->right);
}
}

void postorder(node root)
{if(root!=NULL)
{
 postorder(root->left);
 postorder(root->right);
 printf("%c ",root->info);
}
}

int main()
{char infix[100];
printf("Enter the infix expression.\n");
scanf("%s",infix);
node root=ExpTree(infix);
printf("The Infix expression \n");
inorder(root);
printf("\nThe Prefix expression \n");
preorder(root);
printf("\nThe Postfix expression \n");
postorder(root);
return 0;
}
