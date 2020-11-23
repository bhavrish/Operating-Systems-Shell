#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

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


    wait(NULL);
    
    return 0;
}