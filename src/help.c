#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    printf("\033[0;32m"); // toggle green
    printf("tree:");
    printf("\033[0m");
    printf("\033[01;33m"); // toggle yellow
    printf(" this new command will create a directory and call it Dir0. Then it will change the working directory to Dir0, and create three empty text files namely; t1.txt, t2.txt,and t3.txt, and one empty directory , called Dir1,inside it. \n\n");
    printf("\033[0m");
    
    printf("\033[0;32m"); // toggle green
    printf("list:");
    printf("\033[0m");
    printf("\033[01;33m"); // toggle yellow
    printf(" this new command will clear the terminal screen and print a detailed list of all content of the current directory (similar to ls -l) to the terminal and t1.txt. Finally, it will change the name of text file to tree.txt. \n\n");
    printf("\033[0m");
    
    printf("\033[0;32m"); // toggle green
    printf("path:");
    printf("\033[0m");
    printf("\033[01;33m"); // toggle yellow
    printf(" this new command will print the path of the current directory to the terminal and t2.txt, and change the name of text file to path-info.txt. Concatenate the content of tree.txt and path.txt into t3.txt and change the last to log.txt. Finally, delete tree and path text files. \n\n");
    printf("\033[0m");
    
    printf("\033[0;32m"); // toggle green
    printf("exit:");
    printf("\033[0m");
    printf("\033[01;33m"); // toggle yellow
    printf(" this new command will print a list the last 4 commands to the terminal, a detailed list of all content of the current directory (similar to ls -l). Finally, it will wait for the user to hit the 'return' key to terminate the shell and return the control to the original shell program on your machine. \n");
    printf("\033[0m");
        
    return 0;
}