#include<stdio.h>
#include<string.h>
#define maxMesgs 5
#define maxLen 100
typedef struct QUEUE
{char Q[maxMesgs][maxLen]; 
 int front,rear;
} queue;

void enqueue(queue *q,char mesg[])
{if((q->rear+1)%maxMesgs == q->front)
 {printf("Full\n");
 return;
}
q->rear=(q->rear+1)%maxMesgs;
strcpy(q->Q[q->rear],mesg);
if(q->front==-1)
q->front=0;
}

void dequeue(queue *q,char mesg[])
{if(q->rear == -1)
 {printf("Empty\n");
 return;
}
strcpy(mesg,q->Q[q->front]);
if(q->front==q->rear)
q->front=q->rear=-1;
else
q->front=(q->front+1)%maxMesgs;

}

void display(queue q)
{char mesg[maxLen];
while(q.front!=-1)
 {dequeue(&q,mesg);
 printf("%s\n",mesg);
}
}
int main()
{int ch;
queue q;
q.front=q.rear=-1;
char mesg[maxLen];
while(1)
{printf("1.en\n2.de\n3.dis\n");
scanf("%d",&ch);
switch(ch)
{case 1:printf("Enter the mesg:\n");
scanf(" %[^\n]s ",mesg);
enqueue(&q,mesg);
break;
case 2:
dequeue(&q,mesg);
printf("the mesg:\n %s\n",mesg);
break;
case 3:display(q);break;
default:return 0;
}
}
return 0;
}
