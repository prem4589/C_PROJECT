#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
char a[100];
char b[100];
char *c1;
 // = (char*)malloc(sizeof(char)*100);
char *c2;
 // = (char*)malloc(sizeof(char)*100);
char x[100];
char y[100];
int r,d,e;
int t;
int i,j,count1,count2;
printf("enter your 1st string");
gets(a);
printf("enter your 2nd string");
gets(b);
d=strlen(a);
e=strlen(b);
c1=strtok(a," ");
c2=strtok(b," ");
r=0;
while(c1!=NULL)
{
	
	strcpy(x[r],c1);
	printf("%s\n",c1);
	
	c1=strtok(NULL," ");
	r++;
}
t=0;
while(c2!=NULL)
{
	strcpy(y[t],c2);
	printf("%s\n",c2);
	c2=strtok(NULL," ");
	t++;
}


for (i=0;i<strlen(c1);i++)
{
	printf("%s",x[i]);
}
for (i=0;i<strlen(c2);i++)
{
	printf("%s",y[i]);
}
}
