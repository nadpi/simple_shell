#include "shell.h"
void tokenize(char *input, char **arg)
{
    char *token;
    int i = 0;

    token = strtok(input, " \n");
    while (token != NULL)
    {
        if (token[0] == '/' || token[0] == '$' || (token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z'))
        {
            arg[i++] = token;
        }
        token = strtok(NULL, " \n");
    }
    arg[i] = NULL;
    if (i == 0)
    {
	    arg[0] = "";
	    arg[1] = NULL;
    }
}
