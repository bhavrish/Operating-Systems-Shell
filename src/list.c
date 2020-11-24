// Program written by David A. A. Balaban EMPLID 23572639
// CCNY - CSC332 Operating Systems Group Project

#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	int p1, p2, p3, p4;

    printf("Started list command\n");	
	
    p1 = fork();

	if(p1 == 0){
	// This is performing the first task, to clear the screen of the terminal
		printf("Clearing Terminal\n");
		execlp("clear", "clear", NULL);
        return -1;
    }
    else if (p1 < 0) {
        perror("Child 1 Error: ");
        return -1;
    }

    sleep(1);

    p2 = fork();

    if(p2 == 0){	
    // Then the program will print the contents of the current directory with some details as well
	printf("Printing current directory and its files\n");
      	execlp("ls", "ls",  "-la", NULL);
        return -1;
    }
    else if (p2 < 0) {
        perror("Child 2 Error: ");
        return -1;
    }

    sleep(1);

    p3 = fork();

    if(p3 == 0){ 
    // This will first open the t1.txt file	 
        
        int fid = open("./t1.txt",O_WRONLY);
        if(fid < 0){
        perror("Open: ");
        return -1;
        }
    // Then this is changing the output stream to the t1.txt file
        dup2(fid, 1);  
    // And finally we print the contents of the current directory to the output stream, in this case the file t1.txt
	printf("Printing output of ls -al to file t1.txt\n"); 
      	execlp("ls", "ls", "-la", NULL);
        return -1;
    }
    else if (p3 < 0) {
        perror("Child 3 Error: ");
        return -1;
    }

    sleep(1);

    p4 = fork();

    if(p4 == 0){ 
    // Finally the program will rename the t1.txt file to tree.txt
	printf("Renaming t1.txt to tree.txt\n");    
        execlp("mv", "mv", "./t1.txt", "./tree.txt", NULL);
        return -1;
    }
    else if (p4 < 0) {
        perror("Child 4 Error: ");
        return -1;
    }
    
	
    // Then the program will wait for each of it's children to be terminated correctly
    printf("Waiting for children to be killed\n");	
  
    if(wait(NULL) == -1){
        perror("Wait Error: ");
        return -1;  
    }

    if(wait(NULL) == -1){
        perror("Wait Error: ");
        return -1;  
    }

    if(wait(NULL) == -1){
        perror("Wait Error: ");
        return -1;  
    }

    if(wait(NULL) == -1){
        perror("Wait Error: ");
        return -1;  
    }

    printf("List command is done\n");	
	
    return 0;
}
