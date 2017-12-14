/*                      ITESM Campus Queretaro                           */
/* This program loads the frequency of appearance of each charactar from */
/* a text file. The program reads the values with format.                */
/* Author: Oscar Hernandez                                               */
/* Modified by:   Diego Zamora Rodriguez                                 */

# include <stdio.h>
# include <stdlib.h>
# include <conio.h>

# define MaxSimbols 256
# define MaxStr 256

void Swap (float *p, float * q)
{
float Temp = *p;
  *p = *q;
  *q = Temp;
}

void Shift (float * p)
{
int i=0;

  for (i=0; i < (MaxSimbols - 1); i++) {
    Swap (p, p+1);
    p++;
  }
}

void Print (float *p)
{
int i;
  for (i=0; i < MaxSimbols; i++)
    printf ("\n%i -> %2.2f ",i,*(p++));
}

void LoadFile (char *FileName, float *p)
{
FILE *Source=fopen (FileName, "r");
int i;

  while ( fscanf (Source,"%i %f",&i,p++) != EOF ) ;

  fclose (Source);
}

float ComputeDifference(float a, float b){
    return a-b;
}

unsigned char FindK (float PFreq[], float CFreq[]){
    int CurrentDif = 4034;
    float DifComp = 0.0;
    int k = 0;
    int i = 0;
    while(i<MaxSimbols){
        //printf("%d, %d \n", PFreq[i], CFreq[i]);
        DifComp = ComputeDifference(PFreq[i], CFreq[i]);
        if(CurrentDif > DifComp){
            CurrentDif = DifComp;
            k = i;
        }
        i++;
        //Shift(CFreq);
    }
    return k;
}

float * countChar(char * file){
  FILE *fp = fopen(file, "r");
  int generalCount = 0;
  float count[256] = { 0 };
  int i, c;
  while((c=fgetc(fp))) {
    if(c == EOF) break;
    count[c]+=1;
    generalCount++;
  }
  for(i=0; i<256; i++) {
    if(count[i] > 0) {
      printf("frequency char %c: %f \n", i, (float)count[i]/(float)generalCount);
    }
  }

  fclose(fp);
  return count;
}


int main ()
{


  FILE *SourceFile;  // Definition of two pointers to point to files.
    FILE *DestFile;
    unsigned char Buffer;  // This is a 8 bits long variable without sign.  We will
                           // used it as a Byte.

    // Definition of string variables type that will store file's name
    char SourceName [MaxStr];
    char DestName [MaxStr];

  printf ("\nFile name to decrypt? ");
  gets (SourceName);
  /////////
   float Array [MaxSimbols];

  LoadFile ((char *) "Freqs.txt",Array);
  Shift (Array);
  Print (Array);
  float * cfreq = countChar(SourceName);
  //int k;
   int k = FindK(Array, cfreq);
   printf("k -> %d", k);


   ////////////////////
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
            Buffer = Buffer - k;
        fwrite (&Buffer,1,1,DestFile);
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
