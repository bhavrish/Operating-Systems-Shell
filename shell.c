#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/wait.h>

struct Node { 
    char *command;
    struct Node* next; 
}; 

struct Node* head = NULL; 
struct Node* tail = NULL;
int listSize = 0;

// command to create and add to linked list
void addToList(char *command) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->command = command;
    temp->next = NULL;
    
    if (head == NULL) { // if empty list
        head = temp; // set head to temp
        tail = head; // set tail to head
        listSize++;
    }
    else { // if non-empty list
        tail->next = temp; // set tail->next to temp
        tail = temp; // set tail to temp

        if (listSize == 4) // if max size of 4 is reached, move head to the right (similar to queue)
            head = head->next;
        else // if max size is not yet reached, keep incrementing list size
            listSize++;
    }
} 

// command to get updated history
char* getHistory() {
    char *historyString = malloc(30); // store history of commands in a string (separated by commas)
    strcpy(historyString, "");

    struct Node* itr = head;
    int count = 0;
    while (itr != NULL) {
        if(count == 0)
        strcat(historyString, itr->command); // concatenate command to end of historyString
        else if(count > 0){
            strcat(historyString, ", "); // concatenate comma to beginning of historyString
            strcat(historyString, itr->command); // concatenate command to end of historyString
        }
        count++;
        itr = itr->next; 
    }

    return historyString;
} 

int main(int argc, char *argv[]) {
    while(1) { // run loop until user types "exit"
        printf("\n🔥: ");
        char *buffer = NULL;
        size_t len = 0;
        ssize_t bufferSize = 0;
        bufferSize = getline(&buffer, &len, stdin); // use getline to store input into buffer
        
        if (bufferSize > 0 && buffer[bufferSize-1] == '\n') // replace \n with \0
            buffer[--bufferSize] = '\0';

        addToList(buffer); // add command to linked list
        char* history = getHistory(); // update history

        pid_t pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Fork Failed");
            return 1;
        }
        else if (pid == 0) {
            if (strcmp(buffer, "tree") == 0) { // if user types tree, execute tree() command 
                char *args[] = {"./tree", buffer, NULL};
                execv("./objFiles/tree", args);
            }
            else if (strcmp(buffer, "list") == 0) { // if user types list, execute list() command
                if (chdir("Dir0") == -1) // change dir, otherwise print message that dir doesn't exist
                    printf("\033[1;31mDir0 does not exist!\033[0m\n");

                char *args[] = {"./list", buffer, NULL};
                execv("../objFiles/list", args);
            }
            else if (strcmp(buffer, "path") == 0) { // if user types path, execute path() command 
                if (chdir("Dir0") == -1) // change dir, otherwise print message that dir doesn't exist
                    printf("\033[1;31mDir0 does not exist!\033[0m\n");

                char *args[] = {"./path", buffer, NULL};
                execv("../objFiles/path", args);
            }
            else if (strcmp(buffer, "exit") == 0) { // if user types exit, execute exit() command
                if (chdir("Dir0") == -1) // change dir, otherwise print message that dir doesn't exist
                    printf("\033[1;31mDir0 does not exist!\033[0m\n");

                printf("\033[0;32mGoodbye!\033[0m\n");

                char *args[] = {"./exit", history, NULL};
                execv("../objFiles/exit", args);
            }
            else if (strcmp(buffer, "help") == 0) { // if user types exit, execute exit() command
                char *args[] = {"./help", buffer, NULL};
                execv("./objFiles/help", args);
            }
            else { // if user types invalid command, execute error() command
                char *args[] = {"./error", buffer, NULL};
                execv("./objFiles/error", args);
            }
            exit(1);
        }
        
        wait(NULL); 
        if (strcmp(buffer, "exit") == 0){
            getchar();
            break;
        }
    }
    
    return 0;
}