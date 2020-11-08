#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    printf("\n Quitting..\n"); // print success message
    printf("\n Last 4 Commands:\n"); // print last 4 commands
    printf(argv[1]);
        
    return 0;
}