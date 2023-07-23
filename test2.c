#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 256

int main(int argc, char **argv)
{
    char *input = NULL;
    size_t bufsiz = 0;
    ssize_t charsRead = 0;
    char *arg[MAX_ARGS];
    int i = 0;
    char *token;
    pid_t pid;
    int status;

    while (1)
    {
        printf("$ ");
        charsRead = getline(&input, &bufsiz, stdin);

        if (charsRead == -1)
            break;

        // Remove the newline character from the input (if present)
        if (input[charsRead - 1] == '\n')
            input[charsRead - 1] = '\0';

        pid = fork();

        if (pid == -1)
        {
            perror("./shell");
            return 1;
        }
        else if (pid == 0)
        {
            i = 0;
            token = strtok(input, " ");
            while (token != NULL)
            {
                arg[i++] = token;
                token = strtok(NULL, " ");
            }
            arg[i] = NULL;
            execvp(arg[0], arg);
            perror("./shell");
            return 1;
        }
        else
        {
            waitpid(pid, &status, 0);
        }
    }

    free(input);
    return 0;
}
