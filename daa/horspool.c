#include<stdio.h>
#include<string.h>
char str[100],ptr[120];
int res,m,n,len,i,j,k,table[256];
void shift(char p[])
{
	len= strlen(p);
	for(i=0;i<256;i++)
		table[i]=len;
	for(j=0;j<len-1;j++)
		table[p[j]]=len-1-j;

}
int horspool(char p[],char t[])
{
	shift(p);
	m=strlen(p);
	n=strlen(t);
	i=m-1;
	while(i<=n-1)
	{
		k=0;
		while((k<=m-1)&&(t[i-k]==p[m-1-k]))
			k++;
		if(k==m)
			return i-m+1;
		else
			i=i+table[t[i]];
	}
	return -1;
}

int main()
{
	printf("\n\tenter the text: ");
	scanf("%[^\n]s",str);
	printf("\nenter the pattern : ");
	scanf("%s",ptr);
	res=horspool(ptr,str);
	if(res==-1)
		printf("\n\t string pattern not found\n\n");
	else
		printf("\n\t string pattern found at position %d\n\n",res+1);
	return 0;
}

