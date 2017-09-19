#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>
struct Cal_freq
{
	char characters[100];  //defining struct function to declare size of char array in files.
	int count;
};
// creating function to declare struct variables and also for performing dot and vector products.
void plag(int a,int b,struct Cal_freq word1[],struct Cal_freq word2[])
{
	int sum=0;
	float float1=0;
	float float2=0;
	float plagerism;
	for(int i=0;i<a;i++)
	{
		for (int j = 0; j<b; j++)
		{
			if(strcmp(word1[i].characters,word2[j].characters)==0)
			{
				sum = sum+word1[i].count*word2[j].count; 
			}
		}
	}
	for (int i = 0; i < a; i++)
		{
			float1 = float1+(float)pow((word1[i].count),2);
		}

	for (int i = 0; i < a; i++)
		{
			float2 = float2 + pow((word2[i].count),2); //euclidian formula for dot and vector products
		}
		
	float1 = sqrt(float1);
	float2 = sqrt(float2);
	plagerism = sum/(float1*float2);
	printf("	%0.2f	",plagerism*100); //result of vector and dot products
}
/*
now,calling a function which takes input pointer variable andpoints out the address at variable string and
 and tokenises each and 
every string with respective to the space.
*/
int string_div(char *string,struct Cal_freq word[] )
{
char *pointer;
int i=0,j=0;
int ind_pos=0;
int f = 0;
pointer=strtok(string," ");
while(pointer!=NULL)
	{

	for(j=0;j<i+1;j++)
		{
			if(strcmp(word[j].characters,pointer)==0)
				{
				ind_pos = j;
				f++;
				}
			
		}
	if(f ==0 )
		{
			strcpy(word[i].characters,pointer);
			word[i].count=1;
			
		}
	else
		{
			word[ind_pos].count=word[ind_pos].count+ f;
			f=0;
		}
	pointer = strtok(NULL, " ");
	i++;
	}
	return i;
}
/*
now,we pass each and every pointer character to a function such that the function removes each and every 
special character and lowers each and every string.
*/
char* data_Format(char *ch)
{
	char* string = (char *) malloc(sizeof(char) * 1000);
	strlwr(ch);
	int i=0,j=0;
	int a = strlen(ch);
	while(i!=a)
	{
		if (ch[i]==32||ch[i]>96&&ch[i]<123)
		{
			string[j]=ch[i];
			j++;
		}
		i+=1;
	}
	string[i]='\0';
	return string;
	
}
/*
This function uses strstr() whichreturns a pointer to the first occurrence in given string
of any of the entire sequence of characters
 specified in sentence, or a null pointer if the string is not present in sentence.
*/
int file_cmp(char *nameof_file)
{
	char *compare = (char *) malloc(sizeof(char) * 3);
	compare = "txt";
	char *ret;
	int a;
	ret = strstr(nameof_file,compare);
	if(ret == NULL)
	{
		ret="hi";
	}
	a=strcmp(ret,compare);
	return a;
}
/*
this function activates the reading mode of file and if returns NULL,which means file not present
shows an error message,else,it returns the content of file.
*/
char* file_open(char *nameof_file)
{
	FILE *fptr;
	char *ch = (char *) malloc(sizeof(char) * 100);
	char *string = (char *) malloc(sizeof(char) * 100);
	fptr = fopen(nameof_file, "r");
	if(fptr == NULL) 
	{
		printf("Couldn't open File %s\n",nameof_file );
		perror("Error opening file");
	} 
	fscanf(fptr, "%[^EOF]s", ch);
	string=data_Format(ch);
	return string;
	
}
/*
the main function has struct which takes each and every string that will be stored into the array defined 
by the structure function and also checks for the defined directory and current directory path by checking
the command line arguments
*/
int main(int argc, char const *argv[])
{
	struct dirent *de; 
	//DIR *dr = opendir(".");
	char folder_path[1000];
	DIR *dir ;
	chdir(argv[1]);
	if (argc==2){
	dir=opendir(argv[1]);             //checks for directory in which user gives command line argument
	strcpy(folder_path,argv[1]);
	strcat(folder_path,"\\");
	}
	else
	{
	dir= opendir(".");//checks for current directory in which code is present
	strcpy(folder_path,".");
	strcat(folder_path,"\\");
	}
	char *nooffile[100];
	if (dir == NULL)         //if directory check fails,prints message
	{
		perror(" wrong path : ");
	}
	int a;
	int i=0;
	//it reads directory and checks for txt files
	while ((de = readdir(dir)) != NULL)
	{
		if (strlen(de->d_name)>2) 
		{
	   		a = file_cmp(de->d_name);
	   		if(a==0)
	   			{
					nooffile[i]=malloc(strlen(de->d_name));
					/*if text files present and sentence is present,then every string is appended to the newarray
					with dynamical memory access (malloc)function*/
					strcpy(nooffile[i],de->d_name);
					i=i+1;
	   			}	
	    }
	 }
	char *string1=(char *) malloc(sizeof(char) * 100);
	char *string2=(char *) malloc(sizeof(char) * 100);
	struct Cal_freq file1_characters[100];
	struct Cal_freq file2_characters[100];
	int word_count1,word_count2;
	for(int d=0;d<i;d++)
	{
		printf("	      %s",nooffile[d] );
	}
	printf("\n");
	for(int z=0; z<i; z++)
		{
			printf("	\n%s     ",nooffile[z] );
			for(int y=0;y<i;y++)
				{
					
					if(z!=y)
						{

							char filepath1[1000];
							char filepath2[1000];
							strcpy(filepath1,folder_path);
							strcpy(filepath2,folder_path);
							strcat(filepath1,nooffile[z]);
							strcat(filepath2,nooffile[y]);

							string1=file_open(filepath1);
							string2=file_open(filepath2);
							word_count1 = string_div(string1,file1_characters);
							word_count2 = string_div(string2,file2_characters);
							plag(word_count1,word_count2,file1_characters,file2_characters);
							for(int q=0;q<word_count1;q++)
							{
								file1_characters[q].count=0;
							}
							for(int q=0;q<word_count2;q++)
							{	
								file2_characters[q].count=0;
							}

						}
					else
						{
							 printf("	0.00	" );
						}
			}
			printf("\n");			
		}
		
}