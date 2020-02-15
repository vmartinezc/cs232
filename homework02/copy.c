/**  Homework 02
 
* *  Writing a Program in C
* *  @author: Valeria Martinez (vam6)
* *  @date: 02-13-2020 

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* * doesFileExist
* *  @param: filename
* * return 0 if file exists
* * -1 is it does not exist
* */ 

int doesFileExist(const char *file){
    if (access(file,F_OK)==0){
        return 0;
    }
    else{
        return -1;
    }
}





int main (int argc, char *argv[]){
    //argc takes in the numner of arguments passed && argv[] is a pointer array for each argument 

    const char *srcPath;
    const char *srcDest;



    if(argc < 2){
        perror("Missing parameter. Try: copy <srcpath> <destinationpath>");
        exit(-1);
    }
    else if (argv[2] == NULL) {
        perror("Please provide source path and destination path");
        exit(-1);
    }

    else if( access(const char *srcDest, F_OK) = 0){
        perror("File already exists");

    }

    //TO-DO:
    //check if file exists
    //use access function if it equals 0, then it means that file dest already exists

    else{
        printf("The source path was: %s\n", argv[1]);
        printf("The destination path was: %s\n", argv[2]);
    }






    



}