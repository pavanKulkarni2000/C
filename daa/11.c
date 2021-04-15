#include<stdio.h>
#include<stdlib.h>
void perm(int n);
void dos(int *permut,int size);
void perm(int n)
{
int *array,*dir,temp,tempz,i,max;
array=(int *)malloc(sizeof(int)*n);
dir=(int *)calloc(n,sizeof(int));
for(i=0;i<n;i++)
array[i]=i;
max=n-1;
if(n!=1)
do
{
dos(array,n);
temp=array[max];
tempz=dir[max];
i=!dir[max]?max-1:max+1;
array[max]=array[i];
array[i]=temp;
dir[max]=dir[i];
dir[i]=tempz;
for(i=0;i<n;i++)
 if(array[i]>temp)
   dir[i]=!dir[i];
max=n;
for(i=0;i<n;i++)
if(((!dir[i]&&(i!=0)&&(array[i]>array[i-1]))||(dir[i]&&i!=(n-1)&&(array[i]>array[i+1])))&&(array[i]>array[max]||max==n))
max=i;

}while(max<n);
dos(array,n);
free(dir);
free(array);
}

void dos(int *permut,int size)
{
int i;
for(i=0;i<size;i++)
printf("%d\t",permut[i]);
printf("\n");
}

main()
{
int s;
printf("enter the size\n");
scanf("%d",&s);
perm(s);
}

