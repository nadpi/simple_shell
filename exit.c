#include "shell.h"
/**
 * _exit - handle the exit command
 * @arg: command
 * Return: nothing
 */
void exity(char **arg)
{
	if (_strcmp(arg[0], "exit") == 0)
	{
		if (arg[1] != NULL)
		{
			if (isdigit(*arg[1]))
			{
				if (atoi(arg[1]) < 0)
				{
					fprintf(stderr, "exit: Illegal number: %s\n", arg[1]);
					exit(2);
				}
				exit(atoi(arg[1]));
			}
			else
			{
				fprintf(stderr, "exit: Illegal number: %s\n", arg[1]);
				exit(2);
			}
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
}
