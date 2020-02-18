/**  Homework 02
 
* *  Writing a Program in C
* *  @author: Valeria Martinez (vam6)
* *  @date: 02-13-2020 

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



/* doesSrcFileExist
*  @param: srcFile, pointer to sourcefile
*  @returns: 0 if file exists, -1 if file doesn't exist
*/

int doesSrcFileExist(const char *srcFile){
    if(access(srcFile, F_OK)!= -1){
        return 1;
    }
    else{
        return 0;
    }
}

/*  doesFileExist
*   @param: filename
*  return 0 if file exists
*  -1 is it does not exist
*/ 
int doesDestFileExist(const char *file){
    if (access(file,F_OK)==0){ 
        return 0;
    }
    else{
        return -1;
        
    }
}

/*  checkArgs
*   @argc: int, takes in number of args
*   @argv  pointer array, stores each argument
*   return -1 if error, 0 if all args are valid
*/
int checkArgs(int argc, char *argv[]){
    if (argc<2){
        perror("Missing parameter. \nTry: copy <srcpath> <destination path>");
        exit(-1);
    }
    else if (argv[2] == NULL){
        perror("Please provide destination path.");
        exit(-1);
    }
    else if(!doesSrcFileExist(argv[1])){
        perror(argv[1]);
        exit(-1);
    }

    else if(doesDestFileExist(argv[2])){
        printf("dest already exists");
    }
    else {
        printf("The source path was: %s\n", argv[1]);
        printf("The destination path was: %s\n", argv[2]);
        return 0;
    }
}



int main (int argc, char *argv[]){  

   checkArgs(argc, argv);

   FILE *srcPath, *destPath; //Declares pointer for file typedef variables

   //opens file for reading
   srcPath = fopen(argv[1], "r"); 

   //creates an empty file for writing
   destPath = fopen(argv[2], "w");

   // Takes single character of file at a time
   char f;
   f = fgetc(srcPath);

   while (f != EOF){
       fputc(f, destPath);
       f = fgetc(srcPath);
   }

   fclose(srcPath);
   fclose(destPath);
   printf("Finished copying files");
   return 0;

}





