/*
 ============================================================================
 Name        : a5FileHandling.c
 Author      : Prathamesh Shiralkar
 Version     :
 Copyright   : 
 Description : Assignment4 - File Handling
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pf printf
#define sf scanf
#define cmp !strcmp

int main(int argc, char *argv[]) {
	if(argc<3)
		pf("Incorrect No. of arguments entered!\n");
	else
	{
		if(cmp(argv[1], "type") && argc == 3)
		{
			FILE *fp;
			char c;
			fp=fopen(argv[2], "r");
			if(fp==NULL)
				pf("File does not exist!\n");
			else
			{
				pf("\n\nContents of file are : \n\n");
				while(!feof(fp)){
					c = getc(fp);
					if(c!=-1)
						pf("%c", c);
				}
				pf("\n\n");
			}
			fclose(fp);
		}
		else if(cmp(argv[1], "copy") && argc == 4)
		{
			FILE *src,*tar;
			src=fopen(argv[2], "r");
			tar=fopen(argv[3], "w");
			if(src==NULL)
				pf("File does not exist!\n");
			else
			{
				char c=getc(src);
				while(!feof(src)){
					putc(c, tar);
					c=getc(src);
				}
				pf("File copied successfully to %s!\n", argv[3]);
			}
			fclose(src);
			fclose(tar);
		}
		else
			pf("Incorrect arguments entered!\n");
	}
	return 0;
}
