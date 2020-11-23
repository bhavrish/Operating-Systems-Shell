#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
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
    fptr = fopen("./t2.txt", "w");

    if (fptr == NULL)
    {
        perror("Error");
    }

    fputs(cwd, fptr);
    fclose(fptr);
    printf("Current working directory written to t2.txt\n");

    // rename t2.txt to path-info.txt
    int value = rename("./t2.txt", "./path-info.txt");
    printf("Renamed t2.txt to path-info.txt\n");

    if (value)
    {
        perror("Error");
    }

    // concatenate tree.txt & path-info.txt
    FILE *fp1 = fopen("./tree.txt", "r");
    FILE *fp2 = fopen("./path-info.txt", "r");
    FILE *fp3 = fopen("./t3.txt", "w");
    char c;

    if (fp1 == NULL)
    {
        puts("Could not open tree.txt");
        exit(0);
    }

    if (fp2 == NULL)
    {
        puts("Could not open path-info.txt");
        exit(0);
    }

    if (fp3 == NULL)
    {
        puts("Could not open t3.txt");
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

    // rename t3.txt to log.txt
    value = rename("./t3.txt", "./log.txt");
    printf("Renamed t3.txt to log.txt\n");

    // remove tree.txt & path-info.txt
    if (remove("./path-info.txt") != 0)
        perror("Error");
    printf("Deleted path-info.txt\n");

    if (remove("./tree.txt") != 0)
        perror("Error");
    printf("Deleted tree.txt\n");

    return 0;
}