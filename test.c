#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int main(int argc, char **argv)
{
    char *input = NULL;
    size_t bufsiz = 0;
    ssize_t charsRead = 0;
    char *arg[256];
    int i = 0;
    char *token;
    pid_t pid;
    int status;

    bool is_terminal = isatty(STDIN_FILENO); // Check if input is from a terminal
    bool command_executed = false; // Flag to track if a command has been executed

    while (true)
    {
        if (is_terminal && !command_executed)
            printf("$ ");

        charsRead = getline(&input, &bufsiz, stdin);

        if (charsRead == -1)
            break;

        pid = fork();

        if (pid == -1)
        {
            perror("./shell");
            return 1;
        }
        else if (pid == 0)
        {
            token = strtok(input, " \n");
            while (token != NULL)
            {
                arg[i++] = token;
                token = strtok(NULL, " \n");
            }
            arg[i] = NULL;
            execve(arg[0], arg, environ);
            perror("./shell");
            return 1;
        }
        else
        {
            waitpid(pid, &status, 0);
            command_executed = true; // Set the flag to true after command execution
        }
    }
    free(input);
    return 0;
}
