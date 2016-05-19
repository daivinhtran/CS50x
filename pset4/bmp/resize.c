/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
   	int n = atoi(argv[1]);

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w+");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // determine padding for scanlines of input file
    int padding_in =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // multiply biWidth and biHeight by n
    bi.biWidth = bi.biWidth * n;
    bi.biHeight = bi.biHeight * n;
    
    // determine padding for scanlines of output file
    int padding_out =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // update biSizeImage and bfSize
	bi.biSizeImage = (bi.biWidth*3 + padding_out)*abs(bi.biHeight);
	bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
   

	int inptr_offset = 54;
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i= i+n)
    {
		
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
       	{       		       	
           	// temporary storage
           	RGBTRIPLE triple;
                      	
			if(j%n == 0 && j!= 0)
			{
				inptr_offset += sizeof(RGBTRIPLE) ;
			}
			
			//change the offset of the file pointer inptr
			fseek(inptr, inptr_offset, SEEK_SET);
			
           	// read RGB triple from infile
           	fread(&triple, sizeof(RGBTRIPLE), 1, inptr);           
           	
           	// write RGB triple to outfile
           	fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
           	
       	}	
        // skip to zero padding 
        inptr_offset += sizeof(RGBTRIPLE);
        
        // skip over padding in input file poiter, if any
       	inptr_offset +=padding_in;
		
        // then add zero padding to output file pointer, if any
        for (int k = 0; k < padding_out; k++)
        {
            fputc(0x00, outptr);
       	}
       	// reached the end of the scanline
       	
       	// allocatate a temporary memory to duplicate the scanline n times
       	RGBTRIPLE* temp_pointer = (RGBTRIPLE*)malloc(bi.biWidth*sizeof(RGBTRIPLE) + padding_out);
       	
       	if ( temp_pointer != NULL)
       	{ 	
       		//offset the stream of outptr to the beginning of the scanline
       		fseek(outptr, -(bi.biWidth*3 + padding_out), SEEK_CUR);		
       		
			fread(temp_pointer, bi.biWidth*sizeof(RGBTRIPLE) + padding_out, 1, outptr);
			
			for (int m = 1; m < n; m++)
			{
				fwrite(temp_pointer, bi.biWidth*sizeof(RGBTRIPLE) + padding_out, 1, outptr);				
			}
			
			free(temp_pointer);
		}
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
