#include<stdio.h>
void towers(int n,char from,char to,char aux)
{if(!(n-1))
  printf("move disk 1 from %c to %c peg\n",from,to);
else
 {towers(n-1,from,aux,to);
  printf("move disk %d from %c to %c peg\n",n,from,to);
  towers(n-1,aux,to,from);
}
}

int main()
{int n;
printf("Enter the number of disks");
scanf("%d",&n);
towers(n,'A','B','C');
return 0;
}
  
