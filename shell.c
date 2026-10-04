#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

int main() {
    char input[MAX_LINE];
    char *args[MAX_ARGS];

    while (1) {
        printf("minishell> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) {
            continue;
        }

        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL && i < MAX_ARGS - 1) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "minishell: expected argument to \"cd\"\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("minishell");
                }
            }
            continue;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } 
        else if (pid == 0) {
            if (execvp(args[0], args) < 0) {
                perror("Command not found");
            }
            exit(1);
        } 
        else {
            wait(NULL);
        }
    }

    return 0;
}
