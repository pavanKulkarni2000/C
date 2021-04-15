#include<stdio.h>
typedef struct NODE{

int city;
int visited[10];
int lb;
struct NODE* p;
} node;
int main()
{
node p=(node){1,{0,0,0,0,0,0,0,0,0,0},1,NULL};
node* a=&p;
}
