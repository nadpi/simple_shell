#include "shell.h"
#define MAX_ARGS 256

/**
 * findandexec - find and execute
 * @command: command
 * @path: path
 * @arg: arg
 * @option: option
 * Return: exit status of the executed command
 */
int findandexec(char *command, char *path, char **arg, int option)
{
    char *cleanpath;
    int flag = 1;

    if (arg[0] == NULL)
    {
        flag = 2;
        return flag;
    }

    if (arg[0][0] == '/')
    {
        execve(arg[0], arg, NULL);
        perror("./shell");
        exit(2);
    }
    else
    {
        cleanpath = malloc(strlen(path) + strlen(command) + 2);
        if (cleanpath == NULL)
        {
            perror("malloc");
            exit(1);
        }
        sprintf(cleanpath, "%s%s", path, command);
        if (access(cleanpath, X_OK) == 0)
        {
            if (option == 1)
            {
                pid_t pid = fork();
                if (pid == -1)
                {
                    perror("fork");
                    exit(1);
                }
                else if (pid == 0)
                {
                    execve(cleanpath, arg, NULL);
                    perror("./shell");
                    exit(2);
                }
                else
                {
                    waitpid(pid, &flag, 0);
                    if (WIFEXITED(flag))
                        flag = WEXITSTATUS(flag);
                }
            }
        }
        else
        {
            fprintf(stderr, "%s: command not found\n", command);
            flag = 0;
        }
        free(cleanpath);
    }
    return flag;
}
