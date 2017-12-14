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
unsigned char character;

int generalCount = 0;
int charCount = 0;

  printf ("\nSource file name to count frequency? ");
  gets (SourceName);
  SourceFile=fopen (SourceName,"r+b");
  // Does the source file exist? Can the program open it and read the content of the file?
  if ( SourceFile != NULL ) {
    // If the source file has been opened then open the destination file
    printf ("\nCharacter to count frequency? ");
    scanf(" %c", &character);

    //DestFile = fopen (DestName,"w+b");
    //if ( DestFile != NULL ) {
      // while the end of the source file has not been reached, read one byte
      // at the time from the source file and then write it into the
      // destination file.
      while ( fread (&Buffer,sizeof(Buffer),1,SourceFile) != 0 ) {
        generalCount ++;
        if(Buffer == character){
            charCount++;
        }
        //Buffer = Buffer-32;
       // fwrite ((&Buffer),1,1,DestFile);
      }
      float frequency = (float)charCount/(float)generalCount;
      printf("The total number of characters were %d, with %d appearances of %c and a frequency of %f\n", generalCount, charCount, character, frequency);
      //fclose (DestFile);  // Close destination file to save its content.
    //}
   // else
    //  printf ("\nError: Destination file has not been created!!!");
    fclose (SourceFile); // Never leave a file open
  }
  else
    printf ("\nError: Source file does not exist !!");

  // Normal termination of program
  system ("PAUSE");
  return (0);
}



