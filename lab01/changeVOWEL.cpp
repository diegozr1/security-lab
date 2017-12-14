/*                      ITESM Campus Queretaro                           */
/* This program makes an exact copy of a digital file writing the result */
/* in a second file.   The user is prompted to insert the source and     */
/* destination files' name with their respective extension.              */
/* Author: Oscar Hernandez                                               */

# include <stdio.h>
# include <stdlib.h>

/* Label that defines a maximum value that controls the length of a string*/
# define MaxStr 256

/* The main function does not receive arguments as inputs. */
int main ()
{
FILE *SourceFile;  // Definition of two pointers to point to files.
FILE *DestFile;
unsigned char Buffer;  // This is a 8 bits long variable without sign.  We will
                       // used it as a Byte.

// Definition of string variables type that will store file's name
char SourceName [MaxStr];
char DestName [MaxStr];

int count = 0;

  printf ("\nSource file name? ");
  gets (SourceName);
  SourceFile=fopen (SourceName,"r+b");
  // Does the source file exist? Can the program open it and read the content of the file?
  if ( SourceFile != NULL ) {
    // If the source file has been opened then open the destination file
    printf ("\nDestination file name? ");
    gets (DestName);

    DestFile = fopen (DestName,"w+b");
    if ( DestFile != NULL ) {
      // while the end of the source file has not been reached, read one byte
      // at the time from the source file and then write it into the
      // destination file.
      while ( fread (&Buffer,sizeof(Buffer),1,SourceFile) != 0 ) {
            ++count ;
            if(Buffer == 'a'){
                fprintf(DestFile, "%d", 1);
                continue;
            }
            if(Buffer == 'e'){
                fprintf(DestFile, "%d", 2);
                continue;
            }
            if(Buffer == 'i'){
                fprintf(DestFile, "%d", 3);
                continue;
            }
            if(Buffer == 'o'){
                fprintf(DestFile, "%d", 4);
                continue;
            }
            if(Buffer == 'u'){
                fprintf(DestFile, "%d", 5);
                continue;
            }
        //fwrite (&Buffer,1,1,DestFile);
        fprintf(DestFile, "%c", Buffer);
      }
      fclose (DestFile);  // Close destination file to save its content.
    }
    else
      printf ("\nError: Destination file has not been created!!!");
    fclose (SourceFile); // Never leave a file open
  }
  else
    printf ("\nError: Source file does not exist !!");

  // Normal termination of program
  system ("PAUSE");
  return (0);
}



