#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("\nLast 4 Commands:\n"); // print last 4 commands
    printf("%s \n\n", argv[1]);
    
    pid_t fq = fork(); // fork a child - call it Process Q
    if (fq == -1){
        fprintf(stderr, "Forking child failed.");
        return 1;
    }

    else if(fq==0){ // Child successfully forked
        execlp ("ls", "ls", "-la", NULL); // execute a command that shows all files in current directory with add'l information
        printf ("EXECLP Failed\n");
        exit(1);
    }


    wait(NULL); // the parent process waits for the child process's execution to terminate before leaving 'exit'
    
    return 0;
}