#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    printf("\n In path\n"); // print success message

    // print the current working directory
    char cwd[200];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
    }
    else
    {
        perror("Error");
        return 1;
    }

    // write cwd to t2.txt
    FILE *fptr;
    fptr = fopen("./src/Dir0/t2.txt", "w");

    if (fptr == NULL)
    {
        perror("Error");
    }

    fputs(cwd, fptr);
    fclose(fptr);
    printf("Current working directory written to t2.txt\n");

    // rename t2.txt to path-info.txt
    int value = rename("./src/Dir0/t2.txt", "./src/Dir0/path-info.txt");
    printf("Renamed t2.txt to path-info.txt\n");

    if (value)
    {
        perror("Error");
    }

    // concatenate tree.txt & path-info.txt
    FILE *fp1 = fopen("./src/Dir0/tree.txt", "r");
    FILE *fp2 = fopen("./src/Dir0/path-info.txt", "r");
    FILE *fp3 = fopen("./src/Dir0/t3.txt", "w");
    char c;

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
    {
        puts("Could not open files\n");
        exit(0);
    }

    while ((c = fgetc(fp1)) != EOF)
        fputc(c, fp3);
    while ((c = fgetc(fp2)) != EOF)
        fputc(c, fp3);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    printf("Concatenated tree.txt & path-info.txt to t3.txt\n");

    // rename t2.txt to path-info.txt
    value = rename("./src/Dir0/t3.txt", "./src/Dir0/log.txt");
    printf("Renamed t3.txt to log.txt\n");

    // remove tree.txt & path-info.txt
    if (remove("./src/Dir0/path-info.txt") != 0)
        perror("Error");
    printf("Deleted path-info.txt\n");

    if (remove("./src/Dir0/tree.txt") != 0)
        perror("Error");
    printf("Deleted tree.txt\n");

    return 0;
}