/*                      ITESM Campus Queretaro                           */
/* This program makes an exact copy of a digital file writing the result */
/* in a second one.   The user is prompted to insert the source and      */
/* destination files' name with their respective extension.              */
/* Author: Oscar Hernandez                                               */

# include <stdio.h>
# include <stdlib.h>

/* Label that defines a maximum value that controls the length of a string*/
# define MaxStr 256

/* The main function does not receive arguments as inputs. */
int main ()
{
FILE *SourceFile;
FILE *DestFile;

unsigned char Buffer;
unsigned char next;
// Definition of string variables type that will store file's name
char SourceName [MaxStr];
char DestName [MaxStr];
unsigned char header[54];

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
	fwrite (&header,54,1,DestFile);
      int count = 0;
      while (fread (&Buffer,1,1,SourceFile) != 0 ) {
        fread (&next,1,1,SourceFile);
        count = Buffer % 8;
        next^= 1 << count;
        fwrite (&next,1,1,DestFile);
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




