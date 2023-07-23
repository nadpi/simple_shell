#include "shell.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - main
 * Return: always 0 (Success)
 */

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

    char *default_path = "/bin:/usr/bin"; // Default PATH
    char *path = NULL;

    while (1)
    {
        if (charsRead == -1)
            break;

        pid = fork();

        if (pid == -1)
        {
            perror("./shell");
            return (1);
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

            // Check if the command is "ls"
            if (strcmp(arg[0], "ls") == 0)
            {
                // Get the full path of "ls" using PATH-handling function
                char *full_path = find_command_path(arg[0], path ? path : default_path);
                if (full_path == NULL)
                {
                    fprintf(stderr, "Command not found: %s\n", arg[0]);
                    exit(1);
                }

                execve(full_path, arg, environ);
                perror("./shell");
                exit(1);
            }
            else
            {
                // If the command is not "ls", use execve directly
                execve(arg[0], arg, environ);
                perror("./shell");
                exit(1);
            }
        }
        else
        {
            waitpid(pid, &status, 0);
            printf("$ ");
            charsRead = getline(&input, &bufsiz, stdin);
        }
    }
    free(input);
    return (0);
}

// Function to search for the command in the specified PATH
char *find_command_path(const char *command, const char *path)
{
    char *dir = strtok(path, ":");

    while (dir != NULL)
    {
        char *full_path = malloc(strlen(dir) + strlen(command) + 2); // 2 for '/' and null terminator
        if (full_path == NULL)
        {
            perror("malloc");
            exit(1);
        }
        sprintf(full_path, "%s/%s", dir, command);

        // Check if the full path is executable
        if (access(full_path, X_OK) == 0)
            return full_path;

        free(full_path);
        dir = strtok(NULL, ":");
    }

    // Command not found in any of the directories in PATH
    return NULL;
}
