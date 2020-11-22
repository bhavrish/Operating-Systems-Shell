// Program written by David A. A. Balaban EMPLID 23572639
// CCNY - CSC332 Operating Systems Group Project

#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    
	printf("\n In list\n"); // print success message

	int p1, p2, p3, p4;

p1 = fork();

	if(p1 == 0){
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

        int fid = open("t1.txt",O_WRONLY|O_CREAT, 0666);
        if(fid < 0){
        perror("Open: ");
        return -1;
        }

        dup2(fid, 1);  
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
        execlp("mv", "mv", "t1.txt", "tree.txt", NULL);
        return -1;
    }
    else if (p4 < 0) {
        perror("Child 4 Error: ");
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

    if(wait(NULL) == -1){
        perror("Wait Error: ");
        return -1;  
    }

	

    printf("\nLeaving List\n");

	
    return 0;
}
