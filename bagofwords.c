#include <stdio.h>
#include <string.h>
int main(){
	char t[100];
	char s[100];
	char *c;
	char *d;
	printf("enter your 1st string\n");
	gets(t);
	printf("enter your 2nd string\n");
	gets(s);
	printf("---------------splitting string1---------------\n");
	c=strtok(t," ");
	while(c!=NULL)
	{
		printf("%s\n",c);
		c=strtok(NULL," ");
	}
	printf("---------------splitting string2---------------\n");
	d=strtok(s," ");
	while(d!=NULL)
	{
		printf("%s\n",d);
		d=strtok(NULL," ");
	}
	return 0;
}

/*char s1[200];
char s2[200];
int j,count,count2,d,e,k;
char i,z;

printf("enter your 1st string\n");
//scanf("%*[^\n]%*c",s1);
gets(s1);
printf("enter your 2nd string\n");
//scanf("%*[^\n]%*c",s2);
gets(s2);
d=strlen(s1);
e=strlen(s2);
printf("%d\n",d);

printf("%d\n",e);
count=0;
for(k=0;s1[k]!='\0';k++)
{
	if(s1[k]==' ')
	{
		count=count+1;
	}
}
printf("the no of words in the given string are %d",)
}
//gets(s2)
printf("----------------------for string1-------------------------\n");
for(i='a';i<='z';i++)
{
	count=0;
	for(j=0;j<d;j++)
	{
		if(i==s1[j])
		{
			count=count+1;
		}
	}
	if(count>0)
	{
		printf("%c appears %d times\n",i,count);
	}
}
printf("---------------------for string2--------------------------\n");
for(z='a';z<='z';z++)
{
	count2=0;
	for(k=0;k<e;k++)
	{
		if(z==s2[k])
		{
			count2=count2+1;
		}
	}
	if(count2>0)
	{
		printf("%c appears %d times\n",z,count2);
	}
}
}
*/