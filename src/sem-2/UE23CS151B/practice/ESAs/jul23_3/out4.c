#include<stdio.h>
#include<string.h>
int main()
{
	char p[] = "PESUB";
	char t;
	int i,j=strlen(p)-1;
	for(i=0; i<=j; i++)
	{
		t = p[i];
		p[i] = p[j-i];
		p[j-i] = t;
	}
	p[i]='\0';
	printf("%s\n",p);
	return 0;
}
