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

    printf("\033[0;36mStarted list command\033[0m\n");	
	
    p1 = fork();

	if(p1 == 0){
	// This is performing the first task, to clear the screen of the terminal
		printf("\033[0;36mClearing Terminal\033[0m\n");
		execlp("clear", "clear", NULL);
        return -1;
    }
    else if (p1 < 0) {
        perror("\033[0;31mChild 1 Error: \033[0m");
        return -1;
    }

    sleep(1);

    p2 = fork();

    if(p2 == 0){	
    // Then the program will print the contents of the current directory with some details as well
	printf("\033[0;36mPrinting current directory and its files\033[0m\n");
      	execlp("ls", "ls",  "-la", NULL);
        return -1;
    }
    else if (p2 < 0) {
        perror("\033[0;31mChild 2 Error: \033[0m");
        return -1;
    }

    sleep(1);

    p3 = fork();

    if(p3 == 0){ 
    // This will first open the t1.txt file	 
        
        int fid = open("./t1.txt",O_WRONLY);
        if(fid < 0){
        perror("\033[0;31mOpen: \033[0m");
        return -1;
        }
    // Then this is changing the output stream to the t1.txt file
        dup2(fid, 1);  
    // And finally we print the contents of the current directory to the output stream, in this case the file t1.txt
	printf("\033[0;36mPrinting output of ls -al to file t1.txt\033[0m\n"); 
      	execlp("ls", "ls", "-la", NULL);
        return -1;
    }
    else if (p3 < 0) {
        perror("\033[0;31mChild 3 Error: \033[0m");
        return -1;
    }

    sleep(1);

    p4 = fork();

    if(p4 == 0){ 
    // Finally the program will rename the t1.txt file to tree.txt
	printf("\033[0;36mRenaming t1.txt to tree.txt\033[0m\n");    
        execlp("mv", "mv", "./t1.txt", "./tree.txt", NULL);
        return -1;
    }
    else if (p4 < 0) {
        perror("\033[0;31mChild 4 Error: \033[0m");
        return -1;
    }
    
	
    // Then the program will wait for each of it's children to be terminated correctly
    printf("\033[0;36mWaiting for children to be killed\033[0m\n");	
  
    if(wait(NULL) == -1){
        perror("\033[0;31mWait Error: \033[0m");
        return -1;  
    }

    if(wait(NULL) == -1){
        perror("\033[0;31mWait Error: \033[0m");
        return -1;  
    }

    if(wait(NULL) == -1){
        perror("\033[0;31mWait Error: \033[0m");
        return -1;  
    }

    if(wait(NULL) == -1){
        perror("\033[0;31mWait Error: \033[0m");
        return -1;  
    }

    printf("\033[0;36mList command is done\033[0m\n");	
	
    return 0;
}
