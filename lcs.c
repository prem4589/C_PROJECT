#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <ctype.h>
#include "filehandle.h"
int lcs1(char*ab,char*r)
{
    int t=0;
    int j=0;
    int k=0;
    char* lcs3 = (char*)malloc(sizeof(char)*10);
   	for(int t=0;t<strlen(ab);t++)
	{
		int x=t;
		int y=x;
		for(int j=0;j<strlen(r);j++)
		{
    		if(x<strlen(ab))
			{
				if (ab[x]==r[j])
				{
					x+=1;
					if((x-t)>k)
					{
		                k=x-t;int a=0;
		                for(int z=t;z<x;z++)
		                	{
		                		lcs3[a]=ab[z];
		                		a++;
		                	}
		                lcs3[a]='\0';
					}
				} 
				else
        		{
            		x=y;
        		}   
			}
		}
	}
    return(k);
}
char* char1(char *character)
{
	char* string = (char *) malloc(sizeof(char) * 1000);
	strlwr(character);
	int t=0,j=0;
	int a = strlen(character);
	while(t!=a)
	{
		if (character[t]==32||character[t]>96&&character[t]<123)
		{
			string[j]=character[t];
			j++;
		}
		t+=1;
	}
	string[t]='\0';
	return string;
}
int compare_file(char *file_name)
{
	char *compare = (char *) malloc(sizeof(char) * 3);
	compare = "txt";
	char *abc;
	int a;
	abc = strstr(file_name,compare);
	if(abc == NULL)
	{
		abc="hello!how are you";
	}
	a=strcmp(abc,compare);
	return a;
}
char* file_opening(char *file_name)
{
	FILE *fileptr;
	char *character = (char *) malloc(sizeof(char) * 100);
	char *string = (char *) malloc(sizeof(char) * 100);
	fileptr = fopen(file_name, "r");
	if(fileptr == NULL) 
	{
		printf("fil cant open %s\n",file_name );
		perror("coudnt open file");
	} 
	fscanf(fileptr, "%[^EOF]s", character);
	string=char1(character);
	return string;
}
float lcs4(int length1,int length2,int lcs2)
{
	float ans = (2*lcs2);
	float ans2 = ans /(length1+length2);
	return ans2*100;
}
int main(int argc, char const *argv[])
{
	struct dirent *de; 
	// DIR *dr = opendir("G://MSIT//cspp_c//project");
	char folder_path[1000];
	DIR *dir ;
	chdir(argv[1]);
	if (argc==2){
	dir=opendir(argv[1]);
	strcpy(folder_path,argv[1]);
	strcat(folder_path,"\\");
	}
	else
	{
	dir= opendir(".");
	strcpy(folder_path,".");
	strcat(folder_path,"\\");
	}
	char *file_length[100];
	if (dir == NULL) 
	{
		perror(" error while defining path ");
	}
	int a;
	int t=0;
	while ((de = readdir(dir)) != NULL)
	{
		if (strlen(de->d_name)>2) 
		{
	   		a =compare_file(de->d_name);
	   		if(a==0)
	   			{
					file_length[t]=malloc(strlen(de->d_name));
					strcpy(file_length[t],de->d_name);
					t=t+1;
	   			}	
	    }
	}
	char *file1=(char *) malloc(sizeof(char) * 100);
	char *file2=(char *) malloc(sizeof(char) * 100);
	int lcs2,length1,length2;
	float Plager;
	for(int d=0;d<t;d++)
	{
		printf("	      %s",file_length[d] );
	}
	printf("\n");
	int z,y;
	for(z=0; z<t; z++)
	{
		printf("	\n%s     ",file_length[z] );
		for(y=0;y<t;y++)
		{
			if(z!=y)
			{
				char filepath1[1000];
				char filepath2[1000];
				strcpy(filepath1,folder_path);
				strcpy(filepath2,folder_path);
				strcat(filepath1,file_length[z]);
				strcat(filepath2,file_length[y]);
				file1=file_opening(filepath1);
				file2=file_opening(filepath2);
				length1=strlen(file1);
				length2=strlen(file2);
				lcs2=lcs1(file1,file2);
				Plager =  lcs4(length1,length2,lcs2);
				printf("	%0.2f	",Plager);				
			}
			else
			{
				printf("	0.00	" );
			}
		}
		printf("\n");
	}  
}