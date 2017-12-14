

int test(){
    return 0;
}

/* caesar cipher

while ( fread(&Buffer, sizeof(Buffer)1, SourceFile)!=0){
 if ((Buffer >= 65 ) && (Buffer <= 90)) {
    Buffer = ((Buffer - 65 )+3 ) % 26 ) + 65;
 }else if((Buffer >= 97) %% (Buffer <= 122)){
    Buffer = (((Buffer - 97) + 3) % 26 ) + 97;
 }
 fwrite(&Buffer, 1 , 1, Destfile);
}
fclose(Destfile);*/

/* decode cipher

while(0){
    if((Buffer >= 65 ) && (Buffer <= 90 )){
        Dif = Buffer - 65;
        if(Dif > 2){
            Buffer = Buffer - 3;
        } else {
            Buffer = 65 + (23 + Dif);
        }
    }else if ((Buffer >= 97 ) && Buffer <= 122){
        Dif = Buffer - 97;
        if( Dif > 2){
            Buffer = Buffer - 3;
        } else {
            Buffer = 97 + (23 + Dif);
        }
    }
}
 */
