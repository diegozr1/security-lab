/*                      ITESM Campus Queretaro                           */
/* This program makes an exact copy of a digital file writing the result */
/* in a second one.   The user is prompted to insert the source and      */
/* destination files' name with their respective extension.              */
/* Author: Oscar Hernandez                                               */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/* Label that defines a maximum value that controls the length of a string*/
# define MaxStr 256

/* The main function does not receive arguments as inputs. */
int main ()
{
FILE *SourceFile;
FILE *DestFile;

unsigned char Buffer;
unsigned char Byte[8];
// Definition of string variables type that will store file's name
char SourceName [MaxStr];
char DestName [MaxStr];
unsigned char header[54];
int* p;
int i;

  printf ("\nSource file name? ");
  gets (SourceName);
  SourceFile=fopen (SourceName,"r+b");
  // Does the source file exist? Can the program open the content of the file?
  if ( SourceFile != NULL ) {
    // If the source file has been opened then open the destination file
    printf ("\nDestination file name? ");
    gets (DestName);

    DestFile = fopen (DestName,"w+b");
    if ( DestFile != NULL ) {
      // while the end of the source file has not been reached, read one byte
      // at the time from the source file and then write it into the
      // destination file.

	fread (&header,54,1,SourceFile);
	p = (int*) &header [6];
	int size = *p;
	i = 0;
      while (i < size ) {
        fread(Byte, 8 , 1, SourceFile);
        i += 1;
        Buffer = 0;
        for(int j=0; j<8; j++){
            Byte[j]&=0x01;
            Buffer = Buffer | Byte[j] * (unsigned char) pow(2,j);
        }
        fwrite(&Buffer, 1 , 1, DestFile);
      }
      fclose (DestFile);  // Close destination file to save its content.
    }
    else
      printf ("\nError: Destination file has not been created!!!");
    fclose (SourceFile); // Never leave a file open
  }
  else
    printf ("\nError: Source file does not exist !!");
  printf ("\n\n\n");
  system ("PAUSE");
  return (0);
}




