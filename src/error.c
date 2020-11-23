#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    printf("\033[1;31m");
    printf("\nPlease enter a valid command. ");
    printf("\nType help to see list of valid commands. \n");
    printf("\033[0m");
        
    return 0;
}