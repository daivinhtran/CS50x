/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint32_t DWORD;
typedef uint8_t BYTE;
typedef struct
{
    DWORD signatures;
    BYTE remain[508];
} __attribute__((__packed__))
JPGBLOCK;

int main(void)
{
    FILE* infile = fopen("card.raw", "r");
    if (infile == NULL)
    {
        printf("Could not open card.raw file\n");
        return 2;
    }    
    
    JPGBLOCK buffer;
    int counter = 0;
    //skip the beginning junks (till the first jpg beginning)
    do
    {
    	counter++;
    	fread(&buffer, sizeof(JPGBLOCK), 1, infile);
    }
    while(buffer.signatures != 0xe0ffd8ff & buffer.signatures != 0xe1ffd8ff);
       
	int i = -1;
	char title[10];	
    while(1)
    {	
    	sprintf(title, "%03d.jpg", ++i);
  		FILE* outfile = fopen(title, "a");
    	do
    	{   
    		counter++;
    		fwrite(&buffer, sizeof(JPGBLOCK), 1, outfile);
    	 		
    		fread(&buffer,sizeof(JPGBLOCK), 1, infile);
    		
    		if(feof(infile)!=0)
    		{	
    			fclose(outfile);
    			goto endfile;	
    		}
    	}
    	while(buffer.signatures != 0xe0ffd8ff &&  buffer.signatures != 0xe1ffd8ff);
    	fclose(outfile);
    	
    }	
 	endfile:
    fclose(infile);
  	return 0;
}
