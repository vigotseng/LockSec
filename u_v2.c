#include <stdio.h>
#include <stdio.h>
#include <st
#include <stdlib.h>
int main (int argc,char **argv)
{
	void unlock (char filename[]);
	int i;
	char filename[40];
	if (argc < 2)
	{
		
		printf ("please input the filename : \n");
		scanf ("%s",filename);
		if (filename[0]=='#')
			{
				printf ("\n\ngood bye!\n\n");
				exit (0);
			}
		else 
		{	do
			{
			unlock (filename);
			printf ("\nplease input the filename : \n");
			scanf ("%s",filename);
			}
			while (filename[0]!='#');
			printf ("\n\nsee you!\n\n");
		}
		
	}
	else 
	{
	for (i=1;i<argc;i++)
	{
		unlock (argv[i]);
	}
	}
	return 0;
}

void unlock (char filename[])
{
	FILE *fp;
	int i,j;
	char temp[160];
	if ((fp=fopen(filename,"r"))==NULL)
	{
		printf ("can not open %s ,please check the filename.\n\n",filename);
	}
	else 
	{
		for (i=0;i<160;i++)
		{
			temp[i]=fgetc(fp)^255;
		}
		fclose (fp);
		fp=fopen(filename,"r+");
		for (i=0;i<160;i++)
		{
			fputc (temp[i],fp);
		}
		fclose (fp);

		}
		
}