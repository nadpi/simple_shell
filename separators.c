#include "shell.h"
/**
 * sep - Handles the commands separator
 *@input: input
 *@arg: arg
 *@flag: flag representing the separators
*/
void sep(char *input, char **arg, int flag)
{
	char *commands[256];

	if (flag == 1)
	{
		strtok(input, " ;");
	}

}
