#include "shell.h"
/**
 * env - prints the env variables
*/
void env(void)
{
	char **environment = environ;
	int i = 0;

	while (environment[i] != NULL)
	{
		printf("%s\n", environment[i]);
		i++;
	}
}
