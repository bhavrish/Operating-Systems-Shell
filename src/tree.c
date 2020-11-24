// tree*: this new command will create a directory and call it Dir0. Then it will change the working
//directory to Dir0, and create three empty text files namely; t1.txt, t2.txt,and t3.txt, and one empty
//directory , called Dir1,inside it.
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

// function to make Directory
int makeDirectory(char* directoryName){
    // if mkdir fails, return -1 or else return 0
    if (mkdir(directoryName, 0777) == -1){
        perror("Error while creating the directory Dir0");
        return -1;
    }
    printf("%s created!\n", directoryName);
    return 0;
}

//function to change directory
int changeDirectory(char* directoryName){
    //if chdir fails, return -1 or else return 0
    if (chdir(directoryName) == -1){
        perror("Failed to change directory to Dir0");
        return -1;  
    }   
    printf("Directory changed to %s!\n", directoryName);
    return 0;

}

//function to create file
int createFile(char* filename){
    FILE *fp;
    fp = fopen(filename,"w");
    //if creating a file fails,  return -1 or else return 0
    if (fp == NULL) {
        perror("Failed: to create the file");
        return -1;
    }
    printf("File %s created!\n", filename);
    fclose(fp);
    return 0;
}

int tree(){
    // Creating a directory called Dir0, returns -1 if there was an error. 
    if(makeDirectory("Dir0") == -1){
        return -1;
    }
    // Changing to Dir0, returns -1 if there was an error. 
    if(changeDirectory("Dir0") == -1){
        return -1;
    }
    // creating file t2.txt, returns -1 if there was an error. 
    if(createFile("t1.txt") == -1){
        return -1;
    }
    // creating file t2.txt, returns -1 if there was an error. 
    if(createFile("t2.txt") == -1){
        return -1;
    }
    // creating file t3.txt, returns -1 if there was an error. 
    if(createFile("t3.txt") == -1){
        return -1;
    }
    // Creating a directory called Dir1, returns -1 if there was an error.
    if(makeDirectory("Dir1") == -1){
        return -1;
    }
    return 0;
}

int main() { 
    //Final execution, returns -1 if there was an error in the process.
    return tree(); 
}