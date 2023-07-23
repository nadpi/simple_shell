#include "shell.h"
void findandexec(char *command, char *path, char **arg)
{
    char *cleanpath = malloc(strlen(path) + strlen(command) + 2); // +2 for the slash and null terminator
    if (cleanpath == NULL)
    {
        perror("malloc");
        return;
    }

    strcpy(cleanpath, path);
    strcat(cleanpath, command);

    if (access(cleanpath, X_OK) == 0)
    {
        execve(cleanpath, arg, environ);
        perror("execve");
        free(cleanpath); // Should never be reached, but good to free memory just in case
        exit(1); // Terminate the program
    }
    else
    {
        fprintf(stderr, "%s: command not found\n", command);
    }

    free(cleanpath);
}
