/**  Homework 02
 
* *  Writing a Program in C
* *  @author: Valeria Martinez (vam6)
* *  @date: 02-13-2020 

*/ 






#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
//argc takes in the numner of arguments passed && argv[] is a pointer array for each argument 

    if(argc < 2){
        perror("Missing parameter. Try: copy <srcpath> <destinationpath>");
        exit(-1);
    }
    else if (argv[2] == NULL) {
        perror("Please provide source path and destination path");
        exit(-1);
    }

    //TO-DO:
    //check if file exists

    else{
        printf("The source path was: %s\n", argv[1]);
        printf("The destination path was: %s\n", argv[2]);
    }






    



}