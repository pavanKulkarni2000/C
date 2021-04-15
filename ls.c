#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<grp.h>
#include<pwd.h>
#include<stdlib.h>
char prms[10]="rwxrwxrwx";
int main(int c,char *arg[])
{
struct stat statv;
struct passwd *pwd;
struct group *grp;
char mode[10];
int i,j,st;

if(lstat(arg[1],&statv)==-1)
{printf("ERROR\n");
exit(0);}

st=statv.st_mode;
switch(st & S_IFMT)
{case S_IFDIR:printf("d ");break;
 case S_IFREG:printf("- ");break;
 case S_IFLNK:printf("l ");break;
}

for(i=0,j=(1<<8);i<9;i++,j>>=1)
 if(!(st & j))
 prms[i]='-';
mode[i]='\0';
printf("%s ",prms);

printf("%d ",(int)statv.st_nlink);

grp=getgrgid(statv.st_gid);
pwd=getpwuid(statv.st_uid);
printf("%s ",pwd->pw_name);
printf("%s ",grp->gr_name);

printf("%d ",(int)statv.st_size);
printf("%s \n",arg[1]);
}
